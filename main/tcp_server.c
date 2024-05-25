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
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "protocol_examples_common.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#define PORT CONFIG_EXAMPLE_PORT
#define KEEPALIVE_IDLE CONFIG_EXAMPLE_KEEPALIVE_IDLE
#define KEEPALIVE_INTERVAL CONFIG_EXAMPLE_KEEPALIVE_INTERVAL
#define KEEPALIVE_COUNT CONFIG_EXAMPLE_KEEPALIVE_COUNT

#define MY_DEBUG_TEST 1

static const char *TAG = "example";

typedef struct
{
    float az; // Azimuth
    float el; // Elevation
}AntennaRot;

AntennaRot sat_req;

char test_buffer[128];

QueueHandle_t RotQueueHandler;                          // Create rotator queue handler

static void do_retransmit(const int sock)
{
    AntennaRot *rot_ptr;
    BaseType_t TXStatus;                    // queue status variable
    int len;
    char rx_buffer[128];                    // the tx buffer(rx buffer)

    float prev_az = 0, prev_el = 0;
    float curr_az = 0, curr_el = 0;

    float delta_az, delta_el;

    do
    {
        len = recv(sock, rx_buffer, sizeof(rx_buffer) - 1, 0);      // get the length of the buffer
        if (len < 0)
        {
            ESP_LOGE(TAG, "Error occurred during receiving: errno %d", errno);
        }
        else if (len == 0)
        {
            ESP_LOGW(TAG, "Connection closed");
        }
        // Receive data successfully
        else
        {
            // If the queue is empty, then send the rotator data
            if (uxQueueMessagesWaiting(RotQueueHandler) == 0)
            {
                rx_buffer[len] = 0; // Null-terminate whatever is received and treat it like a string
                // Use ESP_LOGI() to print out a not very important message
                // ESP_LOGI(TAG, "Received %d bytes: %s", len, rx_buffer);     // print data and treate it like a string

                sscanf(rx_buffer, "\\P %f %f", &curr_az, &curr_el);           // transform data in to type float
                
                delta_az = curr_az > prev_az ? (curr_az - prev_az) : (prev_az - curr_az);
                delta_el = curr_el > prev_el ? (curr_el - prev_el) : (prev_el - curr_el);
                
                // ESP_LOGI(TAG, "prev_az:  %.3f; prev_el:  %.3f", prev_az,  prev_el);
                // ESP_LOGI(TAG, "curr_az:  %.3f; curr_el:  %.3f", curr_az,  curr_el);
                // ESP_LOGI(TAG, "delta_az: %.3f; delta_el: %.3f", delta_az, delta_el);

                rot_ptr = (AntennaRot *)malloc(sizeof(AntennaRot));
                if (rot_ptr != NULL)
                {
                    rot_ptr->az = curr_az;
                    rot_ptr->el = curr_el;
                    
                    TXStatus = xQueueSend(RotQueueHandler, &rot_ptr, 0);      // Send a message to a queue
                    if (TXStatus == pdPASS)
                    {
                        ESP_LOGI(TAG, "send done");
                    }
                    else
                    {
                        ESP_LOGI(TAG, "send failed");
                        free(rot_ptr);      // Send failed, free the alloced memory
                    }
                }
                else
                    ESP_LOGI(TAG, "alloc failed.\n");
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

    int err = bind(listen_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (err != 0)
    {
        ESP_LOGE(TAG, "Socket unable to bind: errno %d", errno);
        ESP_LOGE(TAG, "IPPROTO: %d", addr_family);
        goto CLEAN_UP;
    }
    ESP_LOGI(TAG, "Socket bound, port %d", PORT);

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
        int sock = accept(listen_sock, (struct sockaddr *)&source_addr, &addr_len);
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

        shutdown(sock, 0);
        close(sock);
    }

CLEAN_UP:
    close(listen_sock);
    vTaskDelete(NULL);
}

static void rotator_controller(void *pvParameters)
{
    AntennaRot *rot_ptr;
    // Try to receive data from the queue, then print it out.
    BaseType_t RXStatus;
    while (1)
    {
        if (uxQueueMessagesWaiting(RotQueueHandler) != 0)
        {
            rot_ptr = (AntennaRot *) malloc (sizeof(AntennaRot));
            RXStatus = xQueueReceive(RotQueueHandler, &rot_ptr, portMAX_DELAY);      // portMAX_DELAY is equal to 1, means the maximum waiting time
            if (RXStatus == pdPASS && rot_ptr != NULL)
            {
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

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    // Connect default AP 
    ESP_ERROR_CHECK(example_connect());

    // Need two task, one part take charge recviving data from Look4sat, the other in charge rotator controlling.
    RotQueueHandler = xQueueCreate(256, sizeof(AntennaRot *));  // Create message queue
    
    if (RotQueueHandler != NULL)
    {
        // Create task "rotator_controller", if the stack size too small, it make cause overflow.
        xTaskCreate(rotator_controller, "rotator_contr1111111", 4096, (void *)RotQueueHandler, 3, NULL);
        
#ifdef CONFIG_EXAMPLE_IPV4
        xTaskCreate(tcp_server_task, "tcp_server", 4096, (void *)RotQueueHandler, 5, NULL);
#endif
#ifdef CONFIG_EXAMPLE_IPV6
        xTaskCreate(tcp_server_task, "tcp_server", 4096, (void *)AF_INET6, 5, NULL);
#endif
    }
}
