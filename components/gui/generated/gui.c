#include "gui.h"

#include "lvgl_display.h"
#define TAG         "gui"



void gui_task(void)
{
    ESP_LOGI(TAG, "Starting LVGL task");
    uint32_t task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
    events_init(&guider_ui);  
    setup_ui(&guider_ui);

    while (1) 
    {
        // Lock the mutex due to the LVGL APIs are not thread-safe
        if (example_lvgl_lock(-1)) 
        {
            task_delay_ms = lv_timer_handler();
            // Release the mutex
            example_lvgl_unlock();
        }
        if (task_delay_ms > EXAMPLE_LVGL_TASK_MAX_DELAY_MS) 
        {
            task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
        } 
        else if (task_delay_ms < EXAMPLE_LVGL_TASK_MIN_DELAY_MS) 
        {
            task_delay_ms = EXAMPLE_LVGL_TASK_MIN_DELAY_MS;
        }
        vTaskDelay(pdMS_TO_TICKS(task_delay_ms));
    }
}