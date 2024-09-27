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

#define NOTCONN_PERIOD          pdMS_TO_TICKS(500)
#define CONN_PERIOD             pdMS_TO_TICKS(10000)
#define RECV_PERIOD             pdMS_TO_TICKS(50)
#define FILE_URL                "https://celestrak.org/NORAD/elements/gp.php?CATNR=25544&FORMAT=tle"
#define FILE_PATH               "/littlefs/ISS(ZARYA).txt"
#define WIFI_CONNECTED_BIT      BIT0

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

esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    static char *output_buffer;  // 用于存储HTTP请求响应的缓冲区
    static int output_len;       // 存储已读取的字节数
    switch(evt->event_id) {
        case HTTP_EVENT_ON_DATA:
            if (!esp_http_client_is_chunked_response(evt->client)) {
                // 如果配置了user_data缓冲区，将响应复制到缓冲区
                if (evt->user_data) {
                    memcpy(evt->user_data + output_len, evt->data, evt->data_len);
                } else {
                    if (output_buffer == NULL) {
                        output_buffer = (char *) malloc(esp_http_client_get_content_length(evt->client));
                        output_len = 0;
                        if (output_buffer == NULL) {
                            ESP_LOGE(TAG, "Failed to allocate memory for output buffer");
                            return ESP_FAIL;
                        }
                    }
                    memcpy(output_buffer + output_len, evt->data, evt->data_len);
                }
                output_len += evt->data_len;
            }
            break;
        case HTTP_EVENT_ON_FINISH:
            if (output_buffer != NULL) {
                // 在这里处理完整的响应数据，例如写入文件
                FILE* f = fopen(FILE_PATH, "w");
                if (f == NULL) {
                    ESP_LOGE(TAG, "Failed to open file for writing");
                } else {
                    ESP_LOGI(TAG, "Writing data to the file.\n");
                    fprintf(f, "%s", output_buffer);
                    fclose(f);
                }
                free(output_buffer);
                output_buffer = NULL;
            }
            output_len = 0;
            break;
        default:
            break;
    }
    return ESP_OK;
}

void download_tle_task(void *pvParameters)
{
    ESP_LOGI(TAG, "Downloading TLE data from URL");

    esp_http_client_config_t config = {
        .url = FILE_URL,  // 页面URL
        /**
         * @brief   如果是普通的HTTP连接，那么是不需要配置证书的，而HTTPS需要
         */
        .cert_pem = NULL,  // 用于配置指定服务器的SSL证书，NULL代表使用默认证书
        .skip_cert_common_name_check = true,  // 跳过证书通用名称的检查
        .transport_type = HTTP_TRANSPORT_OVER_SSL,  // 确保客户端和服务器端的通信是加密的，指定使用SSL/TLS加密的HTTP连接
        /**
         * @brief   esp_crt_bundle_attach 是 ESP-IDF 提供的一个函数，它会加载一个包含多个受信任 CA 证书的捆绑包。
         *          这样可以验证各种不同的服务器证书，而不需要单独指定每个证书。
         */
        .crt_bundle_attach = esp_crt_bundle_attach,  
        .event_handler = _http_event_handler,  // 定义事件处理函数
    };
    
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_method(client, HTTP_METHOD_GET);
    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %lld",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));

        FILE* f = fopen(FILE_PATH, "w");
        if (f == NULL) {
            ESP_LOGE(TAG, "Failed to open file for writing");
            esp_http_client_cleanup(client);
            vTaskDelete(NULL);
            return;
        }

        char buffer[128];
        int data_read;
        // NOTE: data_read返回0，导致没有任何内容被写入至文件中
        do
        {
            data_read = esp_http_client_read(client, buffer, sizeof(buffer));
            if (fwrite(buffer, 1, data_read, f) != data_read) 
            {
                ESP_LOGE(TAG, "Failed to write data to file");
                fclose(f);
                esp_http_client_cleanup(client);
                vTaskDelete(NULL);
                return;
            }
            // 打印读取的数据
            printf("%.*s", data_read, buffer);

            if (data_read < 0 || 0 == data_read) 
            {
                ESP_LOGE(TAG, "Error occurred during reading: %d", data_read);
            }
        } while(data_read > 0);

        fclose(f);

        // 在这里对下载的数据进行检验
        FILE *fp = fopen(FILE_PATH, "r");
        ESP_LOGI(TAG, "Showing the content of the file: \n");
        char temp_buffer[128];

        while (fgets(temp_buffer, sizeof(temp_buffer), fp))
        {
            ESP_LOGW(TAG, "%s", temp_buffer);
        }
        fclose(fp);

        ESP_LOGI(TAG, "File written successfully");
    } 
    else 
    {
        ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
    vTaskDelete(NULL);
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

    // if (RotQueueHandler != NULL)
    // {
    //     xTaskCreate(rotator_controller, "rotator_control", 4096, (void *)RotQueueHandler, 3, NULL);
    //     xTaskCreate(tcp_server_task, "tcp_server", 4096, (void *)RotQueueHandler, 5, NULL);

    //     LedStatus = NOTCONNECTED;
    // }

}
