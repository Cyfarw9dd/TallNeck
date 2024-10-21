#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "esp_log.h"
#include "esp_err.h"

#include "gui_guider.h"
#include "widgets_init.h"
#include "events_init.h"
#include "custom.h"

void gui_task(void);

