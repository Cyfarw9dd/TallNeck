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

void echo_task(void *arg)
{
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
            else if (strcmp(data, "trking") == 0)
            {
                xTaskNotify(orbit_trking_handler, ORB_TRKING, eSetValueWithOverwrite);
            }
            else if (strcmp(data, "help") == 0)
            {
                printf("update tle\tActivate the TLE data download function.\t\n");
                printf("trking\tActivate the orbit tracking function.\t\n");
            }
            else
            {
                ESP_LOGW(TAG, "Try enter the 'help' for further information.\n");
            }
        }

        vTaskDelay(1000 / portTICK_PERIOD_MS);  

    }
}