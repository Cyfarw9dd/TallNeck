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
    ORB_TRKING = 0x02,
    LAUNCH_TCP = 0x03,
    LAUNCH_ROT = 0x04
}EVENT_BITS;

void echo_task(void *arg);

