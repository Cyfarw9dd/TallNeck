#pragma once

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

extern TaskHandle_t tle_download_handler;
extern TaskHandle_t orbit_trking_handler;
extern TaskHandle_t tcp_server_handler;
extern TaskHandle_t stepper_motor_handler;
extern TaskHandle_t uart_handler;
extern TaskHandle_t gui_handler;

extern QueueHandle_t SatnameQueueHandler;

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

