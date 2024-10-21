/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void hello(void)
{
    printf("hello world.\n");
}

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    printf("hello world.\n");
}

void load_scrPrintFini_cb()
{
    lv_obj_t * act_scr = lv_scr_act();
    lv_disp_t * d = lv_obj_get_disp(act_scr);
    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        if (guider_ui.scrPrintFini_del == true) {
          setup_scr_scrPrintFini(&guider_ui);
        }
        lv_scr_load_anim(guider_ui.scrPrintFini, LV_SCR_LOAD_ANIM_FADE_ON, 400, 100, true);
        guider_ui.scrPrintFini_del = true;
    }
}

void slider_adjust_img_cb(lv_obj_t * img, int32_t brightValue, int16_t hueValue)
{
    static lv_color_t recolor;

    recolor = lv_color_hsv_to_rgb(hueValue, 100, brightValue);

    lv_obj_set_style_img_recolor(img, recolor, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(img, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
}
