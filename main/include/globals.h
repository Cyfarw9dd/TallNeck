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

extern QueueHandle_t SatnameQueueHandler;

