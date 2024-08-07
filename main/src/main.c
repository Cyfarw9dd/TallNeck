/* BSD Socket API Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/timers.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "protocol_examples_common.h"
#include "driver/rmt_tx.h"
#include "driver/gpio.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#include "driver/gpio.h"
#include "tcp_server.h"
#include "stepper_motor_encoder.h"
#include "esp_system.h"
#include "esp_task_wdt.h"
#include "wifi_sta.h"


#define NOTCONN_PERIOD          pdMS_TO_TICKS(500)
#define CONN_PERIOD             pdMS_TO_TICKS(10000)
#define RECV_PERIOD             pdMS_TO_TICKS(50)

char test_buffer[128];

QueueHandle_t RotQueueHandler;               
TimerHandle_t LedTimerHandle;

gpio_num_t gpio_led_num = GPIO_NUM_2;       
int LedCounter = 0;     
unsigned char LedStatus = NOTCONNECTED;     
BaseType_t LedTimerStarted;

static const char *TAG = "example";


// const static uint32_t accel_samples = 500;
// const static uint32_t uniform_speed_hz = 1500;
// const static uint32_t decel_samples = 500;

void stepper_motor_encoder_init(void)
{
    ESP_LOGI(TAG, "Initialize EN + DIR GPIO");
    gpio_config_t en_dir_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .intr_type = GPIO_INTR_DISABLE,
        .pin_bit_mask = 1ULL << STEP_MOTOR_GPIO_DIR | 1ULL << STEP_MOTOR_GPIO_EN,
    };
    ESP_ERROR_CHECK(gpio_config(&en_dir_gpio_config));

    ESP_LOGI(TAG, "Create RMT TX channel");
    rmt_channel_handle_t motor_chan = NULL;
    rmt_tx_channel_config_t tx_chan_config = {
        .clk_src = RMT_CLK_SRC_DEFAULT, // select clock source
        .gpio_num = STEP_MOTOR_GPIO_STEP,
        .mem_block_symbols = 64,
        .resolution_hz = STEP_MOTOR_RESOLUTION_HZ,
        .trans_queue_depth = 10, // set the number of transactions that can be pending in the background
    };
    ESP_ERROR_CHECK(rmt_new_tx_channel(&tx_chan_config, &motor_chan));

    ESP_LOGI(TAG, "Set spin direction");
    gpio_set_level(STEP_MOTOR_GPIO_DIR, STEP_MOTOR_SPIN_DIR_CLOCKWISE);
    ESP_LOGI(TAG, "Enable step motor");
    gpio_set_level(STEP_MOTOR_GPIO_EN, STEP_MOTOR_ENABLE_LEVEL);

    ESP_LOGI(TAG, "Create motor encoders");
    stepper_motor_curve_encoder_config_t accel_encoder_config = {
        .resolution = STEP_MOTOR_RESOLUTION_HZ,
        .sample_points = 500,
        .start_freq_hz = 500,
        .end_freq_hz = 1500,
    };
    rmt_encoder_handle_t accel_motor_encoder = NULL;
    ESP_ERROR_CHECK(rmt_new_stepper_motor_curve_encoder(&accel_encoder_config, &accel_motor_encoder));

    stepper_motor_uniform_encoder_config_t uniform_encoder_config = {
        .resolution = STEP_MOTOR_RESOLUTION_HZ,
    };
    rmt_encoder_handle_t uniform_motor_encoder = NULL;
    ESP_ERROR_CHECK(rmt_new_stepper_motor_uniform_encoder(&uniform_encoder_config, &uniform_motor_encoder));

    stepper_motor_curve_encoder_config_t decel_encoder_config = {
        .resolution = STEP_MOTOR_RESOLUTION_HZ,
        .sample_points = 500,
        .start_freq_hz = 1500,
        .end_freq_hz = 500,
    };
    rmt_encoder_handle_t decel_motor_encoder = NULL;
    ESP_ERROR_CHECK(rmt_new_stepper_motor_curve_encoder(&decel_encoder_config, &decel_motor_encoder));

    ESP_LOGI(TAG, "Enable RMT channel");
    ESP_ERROR_CHECK(rmt_enable(motor_chan));

    ESP_LOGI(TAG, "Spin motor for 6000 steps: 500 accel + 5000 uniform + 500 decel");
    rmt_transmit_config_t tx_config = {
        .loop_count = 0,
    };
}

void Led_Init(void)
{
    gpio_set_direction(gpio_led_num, GPIO_MODE_OUTPUT);     
}

/*
@brief
    Rotator control task, only output a group of data in the same time.
    Recv one and output one.
    Real-Time control.
*/
static void rotator_controller(void *pvParameters)
{
    AntennaRot *rot_ptr;
    BaseType_t RXStatus;

    // ESP_ERROR_CHECK(esp_task_wdt_add(NULL));    // Add task wdt
    // ESP_ERROR_CHECK(esp_task_wdt_status(NULL)); // Check the status of the twdt
    while (1)
    {
        // esp_task_wdt_reset();   // Feed the wdt
        if (uxQueueMessagesWaiting(RotQueueHandler) != 0)
        {
            rot_ptr = (AntennaRot *) malloc (sizeof(AntennaRot));
            RXStatus = xQueueReceive(RotQueueHandler, &rot_ptr, portMAX_DELAY);      // portMAX_DELAY is equal to 1, means the maximum waiting time
            if (RXStatus == pdPASS && rot_ptr != NULL)
            {
                LedStatus = RECVIVING;
                ESP_LOGI(TAG, "recv done, az: %f el: %f", rot_ptr->az, rot_ptr->el);
                free(rot_ptr);
                vTaskDelay(1000 / portTICK_PERIOD_MS);
            }

            // Not receive the data, use delay to block the task, in order not to trigger the wdt
            else
            {
                // free(rot_ptr);
                ESP_LOGI(TAG, "didnt receive");
                vTaskDelay(1000 / portTICK_PERIOD_MS);
            }

        }
        else 
        {
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }

}

/*
@brief 
    Led timer callback function.
    When not connected, blink the led slow.
    When is connected, always blowing up.
    When is recviving the az and the el or the some other thing, blink the led really quick.

    prepare to add:
    Check the break up status, then reset the status of the led.
*/
static void led_timer_callback(TimerHandle_t xTimer)
{
    LedCounter++;
    gpio_set_level(gpio_led_num, LedCounter % 2);
    if (LedStatus == CONNECTED)
    {
        LedCounter = 2;
    }
    else if (LedStatus == RECVIVING)
    {
        xTimerChangePeriod(xTimer, RECV_PERIOD, 0);
    }
    else
    {
        ;
    }
}


void app_main(void)
{
    Led_Init();     // Initialize function

    LedTimerHandle = xTimerCreate("led_controller", NOTCONN_PERIOD, pdTRUE, 0, led_timer_callback);  // Create the led control timer.
    RotQueueHandler = xQueueCreate(5, sizeof(AntennaRot *));  // Create message queue

    if (LedTimerHandle != NULL)
    {
        LedTimerStarted = xTimerStart(LedTimerHandle, 0);  // Start the timer
    }
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());   // Creat a default event loop

    // ESP_ERROR_CHECK(example_connect());  // Connect default AP
    wifi_init_sta();
    
    if (RotQueueHandler != NULL)
    {
        xTaskCreate(rotator_controller, "rotator_control", 4096, (void *)RotQueueHandler, 3, NULL);
        xTaskCreate(tcp_server_task, "tcp_server", 4096, (void *)RotQueueHandler, 5, NULL);

        LedStatus = CONNECTED;
    }

}
