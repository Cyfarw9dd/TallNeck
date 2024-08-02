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

#define PORT CONFIG_EXAMPLE_PORT
#define KEEPALIVE_IDLE CONFIG_EXAMPLE_KEEPALIVE_IDLE
#define KEEPALIVE_INTERVAL CONFIG_EXAMPLE_KEEPALIVE_INTERVAL
#define KEEPALIVE_COUNT CONFIG_EXAMPLE_KEEPALIVE_COUNT

#define NOT_TRACKING_FARSIDE    0
#define DELTA_VALUE             0.01
#define NOTCONN_PERIOD          pdMS_TO_TICKS(500)
#define CONN_PERIOD             pdMS_TO_TICKS(10000)
#define RECV_PERIOD             pdMS_TO_TICKS(50)

static const char *TAG = "example";

typedef struct
{
    float az; // Azimuth
    float el; // Elevation
}AntennaRot;

typedef enum
{
    NOTCONNECTED = 1,
    CONNECTED,
    RECVIVING,
}Connect_Status;

AntennaRot sat_req;

char test_buffer[128];

QueueHandle_t RotQueueHandler;               
TimerHandle_t LedTimerHandle;

gpio_num_t gpio_led_num = GPIO_NUM_2;       
int LedCounter = 0;     
unsigned char LedStatus = NOTCONNECTED;     
BaseType_t LedTimerStarted;


void Led_Init(void)
{
    gpio_set_direction(gpio_led_num, GPIO_MODE_OUTPUT);     
}

static void do_retransmit(const int sock)
{
    AntennaRot *rot_ptr;
    BaseType_t TXStatus;                    
    int len;
    char rx_buffer[128];                    

    float prev_az = 0, prev_el = 0;
    float curr_az = 0, curr_el = 0;

    float delta_az, delta_el;

    do
    {
        len = recv(sock, rx_buffer, sizeof(rx_buffer) - 1, 0);      
        if (len < 0)
        {
            LedStatus = CONNECTED;
            ESP_LOGE(TAG, "Error occurred during receiving: errno %d", errno);
        }
        else if (len == 0)
        {
            LedStatus = CONNECTED;
            ESP_LOGW(TAG, "Connection closed");
        }
        else
        {
            if (uxQueueMessagesWaiting(RotQueueHandler) == 0)
            {
                rx_buffer[len] = 0; // Null-terminate whatever is received and treat it like a string

                sscanf(rx_buffer, "\\P %f %f", &curr_az, &curr_el);           // transform data in to type float
                
                delta_az = curr_az > prev_az ? (curr_az - prev_az) : (prev_az - curr_az);
                delta_el = curr_el > prev_el ? (curr_el - prev_el) : (prev_el - curr_el);

                // Exclude the condition EL is negative, that's mean the satllite is on the far side of the Earth
#if (NOT_TRACKING_FARSIDE)
                if (curr_el >= 0 && prev_el >= 0)
                {
                    if (delta_az > DELTA_VALUE || delta_el > DELTA_VALUE)
                    {
#endif
                        rot_ptr = (AntennaRot *)malloc(sizeof(AntennaRot));
                        if (rot_ptr != NULL)
                        {
                            rot_ptr->az = curr_az;
                            rot_ptr->el = curr_el;
                            
                            TXStatus = xQueueSend(RotQueueHandler, &rot_ptr, 0);      // Send a message to a queue
                            if (TXStatus == pdPASS)
                            {
                                ESP_LOGI(TAG, "send done");
                                prev_az = curr_az;
                                prev_el = curr_el;
                            }
                            else
                            {
                                ESP_LOGI(TAG, "send failed");
                                free(rot_ptr);      // Send failed, free the alloced memory
                            }
                        }
                        else
                            ESP_LOGI(TAG, "alloc failed.\n");
#if (NOT_TRACKING_FARSIDE)
                    }
                }
#endif
            }
        }

    } while (len > 0);
}

static void tcp_server_task(void *pvParameters)
{
    char addr_str[128];
    int addr_family = (int)AF_INET;
    int ip_protocol = 0;
    int keepAlive = 1;
    int keepIdle = KEEPALIVE_IDLE;
    int keepInterval = KEEPALIVE_INTERVAL;
    int keepCount = KEEPALIVE_COUNT;
    struct sockaddr_storage dest_addr;

#ifdef CONFIG_EXAMPLE_IPV4
    if (addr_family == AF_INET)
    {
        struct sockaddr_in *dest_addr_ip4 = (struct sockaddr_in *)&dest_addr;
        dest_addr_ip4->sin_addr.s_addr = htonl(INADDR_ANY);
        dest_addr_ip4->sin_family = AF_INET;
        dest_addr_ip4->sin_port = htons(PORT);
        ip_protocol = IPPROTO_IP;
    }
#endif
#ifdef CONFIG_EXAMPLE_IPV6
    if (addr_family == AF_INET6)
    {
        struct sockaddr_in6 *dest_addr_ip6 = (struct sockaddr_in6 *)&dest_addr;
        bzero(&dest_addr_ip6->sin6_addr.un, sizeof(dest_addr_ip6->sin6_addr.un));
        dest_addr_ip6->sin6_family = AF_INET6;
        dest_addr_ip6->sin6_port = htons(PORT);
        ip_protocol = IPPROTO_IPV6;
    }
#endif
    // Create a socket?
    int listen_sock = socket(addr_family, SOCK_STREAM, ip_protocol);
    if (listen_sock < 0)
    {
        ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
        vTaskDelete(NULL);
        return;
    }
    int opt = 1;
    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
#if defined(CONFIG_EXAMPLE_IPV4) && defined(CONFIG_EXAMPLE_IPV6)
    // Note that by default IPV6 binds to both protocols, it is must be disabled
    // if both protocols used at the same time (used in CI)
    setsockopt(listen_sock, IPPROTO_IPV6, IPV6_V6ONLY, &opt, sizeof(opt));
#endif

    ESP_LOGI(TAG, "Socket created");
    // Bind
    int err = bind(listen_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (err != 0)
    {
        ESP_LOGE(TAG, "Socket unable to bind: errno %d", errno);
        ESP_LOGE(TAG, "IPPROTO: %d", addr_family);
        goto CLEAN_UP;
    }
    ESP_LOGI(TAG, "Socket bound, port %d", PORT);
    // Listen
    err = listen(listen_sock, 1);
    if (err != 0)
    {
        ESP_LOGE(TAG, "Error occurred during listen: errno %d", errno);
        goto CLEAN_UP;
    }

    while (1)
    {

        ESP_LOGI(TAG, "Socket listening");
        
        struct sockaddr_storage source_addr; // Large enough for both IPv4 or IPv6
        socklen_t addr_len = sizeof(source_addr);
        int sock = accept(listen_sock, (struct sockaddr *)&source_addr, &addr_len); // Accept, recving data
        if (sock < 0)
        {
            ESP_LOGE(TAG, "Unable to accept connection: errno %d", errno);
            break;
        }

        // Set tcp keepalive option
        setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &keepAlive, sizeof(int));
        setsockopt(sock, IPPROTO_TCP, TCP_KEEPIDLE, &keepIdle, sizeof(int));
        setsockopt(sock, IPPROTO_TCP, TCP_KEEPINTVL, &keepInterval, sizeof(int));
        setsockopt(sock, IPPROTO_TCP, TCP_KEEPCNT, &keepCount, sizeof(int));
        // Convert ip address to string
#ifdef CONFIG_EXAMPLE_IPV4
        if (source_addr.ss_family == PF_INET)
        {
            inet_ntoa_r(((struct sockaddr_in *)&source_addr)->sin_addr, addr_str, sizeof(addr_str) - 1);
        }
#endif
#ifdef CONFIG_EXAMPLE_IPV6
        if (source_addr.ss_family == PF_INET6)
        {
            inet6_ntoa_r(((struct sockaddr_in6 *)&source_addr)->sin6_addr, addr_str, sizeof(addr_str) - 1);
        }
#endif
        ESP_LOGI(TAG, "Socket accepted ip address: %s", addr_str);

        do_retransmit(sock);
        // After transmision is over, close the socket and free the memory.
        shutdown(sock, 0);
        close(sock);
    }

CLEAN_UP:
    close(listen_sock);
    vTaskDelete(NULL);
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
    while (1)
    {
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
static void LedTimerCallback(TimerHandle_t xTimer)
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

    LedTimerHandle = xTimerCreate("led_controller", NOTCONN_PERIOD, pdTRUE, 0, LedTimerCallback);  // Create the led control timer.
    RotQueueHandler = xQueueCreate(5, sizeof(AntennaRot *));  // Create message queue

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());   // Creat a default event loop

    ESP_ERROR_CHECK(example_connect());  // Connect default AP
    
    if (RotQueueHandler != NULL && LedTimerHandle != NULL)
    {
        xTaskCreate(rotator_controller, "rotator_control", 4096, (void *)RotQueueHandler, 3, NULL);
        xTaskCreate(tcp_server_task, "tcp_server", 4096, (void *)RotQueueHandler, 5, NULL);

        LedStatus = CONNECTED;
        LedTimerStarted = xTimerStart(LedTimerHandle, 0);  // Start the timer
    }

    while (1)
    {
        vTaskDelay(portMAX_DELAY);  // TODO:Hold the main thread if the connection error occur.
    }
}
