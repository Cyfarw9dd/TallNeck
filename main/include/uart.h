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
#include "sgp4sdp4.h"
#include "wifi_manager.h"

void echo_task(void *pvParameter);

