#include "gui.h"

#include "lvgl_display.h"



void gui_task(void)
{
    lvgl_display_init();
    events_init(&guider_ui);  
    setup_ui(&guider_ui);

    while(1)
    {
        vTaskDelay(30 / portTICK_PERIOD_MS);
    }
}