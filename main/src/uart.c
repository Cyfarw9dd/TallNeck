#include "uart.h"

#define BUF_SIZE    (1024)
#define TAG         "uart"

#define ECHO_TEST_TXD (GPIO_NUM_43)
#define ECHO_TEST_RXD (GPIO_NUM_44)
#define ECHO_TEST_RTS (UART_PIN_NO_CHANGE)
#define ECHO_TEST_CTS (UART_PIN_NO_CHANGE)

#define ECHO_UART_PORT_NUM      (UART_NUM_0)
#define ECHO_UART_BAUD_RATE     (115200)
#define ECHO_TASK_STACK_SIZE    (2048)

void echo_task(void *pvParameter)
{
    BaseType_t tx_status;
    char input_satname[128] = {0};

    // UART串口配置
    uart_config_t uart_config = {
        .baud_rate = ECHO_UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    int intr_alloc_flags = 0;

#if CONFIG_UART_ISR_IN_IRAM
    intr_alloc_flags = ESP_INTR_FLAG_IRAM;
#endif

    // 安装UART驱动程序
    ESP_ERROR_CHECK(uart_driver_install(ECHO_UART_PORT_NUM, BUF_SIZE * 2, 0, 0, NULL, intr_alloc_flags));
    // 参数配置和引脚设置
    ESP_ERROR_CHECK(uart_param_config(ECHO_UART_PORT_NUM, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(ECHO_UART_PORT_NUM, ECHO_TEST_TXD, ECHO_TEST_RXD, ECHO_TEST_RTS, ECHO_TEST_CTS));

    // 为接受到的数据创建临时缓冲区
    char *data = (char *) malloc(BUF_SIZE);

    while (1) {
        // 从串口中读取数据
        int len = uart_read_bytes(ECHO_UART_PORT_NUM, data, (BUF_SIZE - 1), 20 / portTICK_PERIOD_MS);
        if (len) {
            if (strstr(data, "reconnect") != NULL)
            {
                // xTaskNotify(tle_download_handler, UPDATE_TLE, eSetValueWithOverwrite);
            }
            else if (strstr(data, "update tle") != NULL)
            {
                xTaskNotify(tle_download_handler, UPDATE_TLE, eSetValueWithOverwrite);
            }
            else if (strstr(data, "start trking") != NULL)
            {
                xTaskNotify(orbit_trking_handler, START_ORB_TRKING, eSetValueWithOverwrite);
                ESP_LOGI(TAG, "Activate the tracking mode.\n");
            }
            /**
             * @brief   对于业余卫星名的传输，任务通知已不再适合，使用消息队列会更加恰当
             *          消息队列将会维护一个字符串，该字符串用于存储输入的卫星名，并将该卫星名使用消息队列传输给追踪任务
             */
            else if (strstr(data, "AO-7") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "AO-10") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "UO-11") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "LO-19") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "AO-27") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "IO-26") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "RS-15") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "FO-29") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "GO-32") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "ISS") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "NO-44") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "NO-44") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "SO-50") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "CO-50") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "CO-57") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "RS-22") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "LILACSAT-2") != NULL)
            {
                strncpy(input_satname, data, sizeof(data - 1));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strstr(data, "end trking") != NULL)
            {
                xTaskNotify(orbit_trking_handler, END_ORB_TRKING, eSetValueWithOverwrite);
                ESP_LOGI(TAG, "Deactivate the tracking mode.\n");
            }
            else if (strstr(data, "help") != NULL)
            {
                printf("update tle\tActivate the TLE data download function.\t\n");
                printf("start trking\tActivate the orbit tracking function.\t\n");
                printf("end trking\tDeactivate the orbit tracking function.\t\n");
            }
            else
            {
                ESP_LOGW(TAG, "Try enter the 'help' for further information.\n");
            }
        }

        vTaskDelay(1000 / portTICK_PERIOD_MS);  

    }
}