#pragma once

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

#include "globals.h"

// 任务通知传递掩码
typedef enum
{
    NO_EVENT = 0X00,
    UPDATE_TLE = 0X01,
    START_ORB_TRKING = 0x02,
    END_ORB_TRKING = 0X03,
    LAUNCH_TCP = 0x04,
    LAUNCH_ROT = 0x05
}EVENT_BITS;

void echo_task(void *arg);

