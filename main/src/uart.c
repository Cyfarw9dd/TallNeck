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
            data[len] = '\0';
            if (strcmp(data, "reconnect") == 0)
            {
                // xTaskNotify(tle_download_handler, UPDATE_TLE, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "update tle") == 0 || strcmp(data, "tle") == 0 || strcmp(data, "upt") == 0)
            {
                xTaskNotify(tle_download_handler, UPDATE_TLE, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "start trking") == 0)
            {
                xTaskNotify(orbit_trking_handler, START_ORB_TRKING, eSetValueWithOverwrite);
            }
            /**
             * @brief   对于业余卫星名的传输，任务通知已不再适合，使用消息队列会更加恰当
             *          消息队列将会维护一个字符串，该字符串用于存储输入的卫星名，并将该卫星名使用消息队列传输给追踪任务
             */
            else if (strcmp(data, "AO-7") == 0)
            {
                strncpy(input_satname, data, sizeof(data));
                tx_status = xQueueSend(SatnameQueueHandler, input_satname, 0);
                if (tx_status != pdPASS)
                {
                    ESP_LOGE(TAG, "Satellite input name send failed.\n");
                }
            }
            else if (strcmp(data, "AO-10") == 0)
            {
                xTaskNotify(orbit_trking_handler, AO_10, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "UO-11") == 0)
            {
                xTaskNotify(orbit_trking_handler, UO_11, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "LO-19") == 0)
            {
                xTaskNotify(orbit_trking_handler, LO_19, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "AO-27") == 0)
            {
                xTaskNotify(orbit_trking_handler, AO_27, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "IO-26") == 0)
            {
                xTaskNotify(orbit_trking_handler, IO_26, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "RS-15") == 0)
            {
                xTaskNotify(orbit_trking_handler, RS_15, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "FO-29") == 0)
            {
                xTaskNotify(orbit_trking_handler, FO_29, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "GO-32") == 0)
            {
                xTaskNotify(orbit_trking_handler, GO_32, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "ISS") == 0)
            {
                xTaskNotify(orbit_trking_handler, ISS, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "NO-44") == 0)
            {
                xTaskNotify(orbit_trking_handler, NO_44, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "NO-44") == 0)
            {
                xTaskNotify(orbit_trking_handler, NO_44, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "SO-50") == 0)
            {
                xTaskNotify(orbit_trking_handler, SO_50, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "CO-50") == 0)
            {
                xTaskNotify(orbit_trking_handler, CO_50, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "CO_57") == 0)
            {
                xTaskNotify(orbit_trking_handler, CO_57, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "RS-22") == 0)
            {
                xTaskNotify(orbit_trking_handler, RS_22, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "LILACSAT-2") == 0)
            {
                xTaskNotify(orbit_trking_handler, LILACSAT_2, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "end trking") == 0)
            {
                xTaskNotify(orbit_trking_handler, END_ORB_TRKING, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "help") == 0)
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