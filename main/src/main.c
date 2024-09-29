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
#include <sys/stat.h>
#include <unistd.h>
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
#include "driver/gpio.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#include "tcp_server.h"
#include "stepper_motor_encoder.h"
#include "esp_system.h"
#include "esp_task_wdt.h"
#include "wifi_sta.h"
#include "esp_littlefs.h"
#include "esp_http_client.h"
#include "http_app.h"
#include "esp_crt_bundle.h"

#include "wifi_manager.h"
#include "littlefs.h"
#include "get_tle.h"

#define NOTCONN_PERIOD          pdMS_TO_TICKS(500)
#define CONN_PERIOD             pdMS_TO_TICKS(10000)
#define RECV_PERIOD             pdMS_TO_TICKS(50)

char test_buffer[128];

TimerHandle_t LedTimerHandle;
gpio_num_t gpio_led_num = GPIO_NUM_2;       
int LedCounter = 0;     
unsigned char LedStatus = NOTCONNECTED;     
BaseType_t LedTimerStarted;
static const char *TAG = "main";

static void Led_Init(void)
{
    gpio_set_direction(gpio_led_num, GPIO_MODE_OUTPUT);     
}

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


/**
 * @brief this is an exemple of a callback that you can setup in your own app to get notified of wifi manager event.
 */
void cb_connection_ok(void *pvParameter)
{
	ip_event_got_ip_t* param = (ip_event_got_ip_t*)pvParameter;

	/* transform IP to human readable string */
	char str_ip[16];
	esp_ip4addr_ntoa(&param->ip_info.ip, str_ip, IP4ADDR_STRLEN_MAX);

	ESP_LOGI(TAG, "I have a connection and my IP is %s!", str_ip);
    // 在这里触发数据下载任务
    xTaskCreate(download_tle_task, "download_tle", 8192, NULL, 5, NULL);

}

void app_main(void)
{
    Led_Init();  // LED初始化
    littlefs_init(&littlefs_conf);  // LittleFS 文件系统初始化
    ESP_LOGW(TAG, "Before running the callback func, the file content is:\n");
    char temp_buffer[128];
    FILE *fp = fopen(FILE_PATH, "r");
    while (fgets(temp_buffer, sizeof(temp_buffer), fp))
    {
        ESP_LOGW(TAG, "%s", temp_buffer);
    }
    fclose(fp);
    // esp_err_t err = nvs_flash_erase();  // 用于擦除nvs部分
    LedTimerHandle = xTimerCreate("led_controller", NOTCONN_PERIOD, pdTRUE, 0, led_timer_callback);  // 创建LED定时器
    RotQueueHandler = xQueueCreate(5, sizeof(Tcp_Sentence *));  // 创建用于传输俯仰角数据的消息队列

    if (LedTimerHandle != NULL)
    {
        LedTimerStarted = xTimerStart(LedTimerHandle, 0);  // 启动LED定时器
    }

    // wifi manager IP address: 10.10.0.1
	wifi_manager_start();
    // 回调函数，用于返回IP 
	wifi_manager_set_callback(WM_EVENT_STA_GOT_IP, &cb_connection_ok);

    if (RotQueueHandler != NULL)
    {
        xTaskCreate(rotator_controller, "rotator_control", 4096, (void *)RotQueueHandler, 3, NULL);
        xTaskCreate(tcp_server_task, "tcp_server", 4096, (void *)RotQueueHandler, 5, NULL);

        LedStatus = NOTCONNECTED;
    }

}
