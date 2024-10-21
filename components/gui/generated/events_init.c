/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "custom.h"
static uint16_t copiesCnt = 1;
static char buf[6];

static void scrHome_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_animation(guider_ui.scrHome_contBG, 100, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrHome_contBG, 100, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		
		break;
	}
    default:
        break;
    }
}

static void scrHome_contSetup_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrSetup, guider_ui.scrSetup_del, &guider_ui.scrHome_del, setup_scr_scrSetup, LV_SCR_LOAD_ANIM_FADE_ON, 100, 200, false, true);
		lv_obj_set_style_bg_color(guider_ui.scrHome_contBG, lv_color_hex(0xe12e2e), LV_PART_MAIN);
		ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 272, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrHome_contPrint_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrPrintMenu, guider_ui.scrPrintMenu_del, &guider_ui.scrHome_del, setup_scr_scrPrintMenu, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrHome_contCopy_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrCopy, guider_ui.scrCopy_del, &guider_ui.scrHome_del, setup_scr_scrCopy, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 60, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrHome_contScan_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrScan, guider_ui.scrScan_del, &guider_ui.scrHome_del, setup_scr_scrScan, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

void events_init_scrHome (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrHome, scrHome_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrHome_contSetup, scrHome_contSetup_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrHome_contPrint, scrHome_contPrint_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrHome_contCopy, scrHome_contCopy_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrHome_contScan, scrHome_contScan_event_handler, LV_EVENT_ALL, ui);
}

static void scrCopy_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrCopy_sliderBright_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		slider_adjust_img_cb(guider_ui.scrCopy_imgScanned, lv_slider_get_value(guider_ui.scrCopy_sliderBright), lv_slider_get_value(guider_ui.scrCopy_sliderHue));
		break;
	}
    default:
        break;
    }
}

static void scrCopy_sliderHue_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		slider_adjust_img_cb(guider_ui.scrCopy_imgScanned, lv_slider_get_value(guider_ui.scrCopy_sliderBright), lv_slider_get_value(guider_ui.scrCopy_sliderHue));
		break;
	}
    default:
        break;
    }
}

static void scrCopy_btnNext_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_animation(guider_ui.scrCopy_imgScanned, 200, 0, lv_img_get_zoom(guider_ui.scrCopy_imgScanned), 201, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_img_set_zoom, NULL, NULL, NULL);
		ui_load_scr_animation(&guider_ui, &guider_ui.scrCopy2, guider_ui.scrCopy2_del, &guider_ui.scrCopy_del, setup_scr_scrCopy2, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrCopy_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrCopy_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

void events_init_scrCopy (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrCopy, scrCopy_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrCopy_sliderBright, scrCopy_sliderBright_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrCopy_sliderHue, scrCopy_sliderHue_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrCopy_btnNext, scrCopy_btnNext_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrCopy_btnBack, scrCopy_btnBack_event_handler, LV_EVENT_ALL, ui);
}

static void scrCopy2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_UNLOAD_START:
	{
		copiesCnt = 1;
		break;
	}
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_animation(guider_ui.scrCopy2_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy2_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrCopy2_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy2_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrCopy2_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrCopy2_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		ui_animation(guider_ui.scrCopy2_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy2_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrCopy2_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy2_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrCopy2_btnNext_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrLoader, guider_ui.scrLoader_del, &guider_ui.scrCopy2_del, setup_scr_scrLoader, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, false, true);
		ui_animation(guider_ui.scrCopy2_contBG, 200, 0, lv_obj_get_width(guider_ui.scrCopy2_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrCopy2_contBG, 200, 0, lv_obj_get_height(guider_ui.scrCopy2_contBG), 272, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrCopy2_btnPlus_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		copiesCnt++;
		sprintf(buf,  "%d" , copiesCnt);
		lv_label_set_text(guider_ui.scrCopy2_labelCounter, buf);
		break;
	}
	case LV_EVENT_LONG_PRESSED_REPEAT:
	{
		copiesCnt++;
		sprintf(buf,  "%d" , copiesCnt);
		lv_label_set_text(guider_ui.scrCopy2_labelCounter, buf);
		break;
	}
    default:
        break;
    }
}

static void scrCopy2_btnMinus_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		if (copiesCnt == 1) break;
		copiesCnt--;
		sprintf(buf,  "%d" , copiesCnt);
		lv_label_set_text(guider_ui.scrCopy2_labelCounter, buf);
		break;
	}
	case LV_EVENT_LONG_PRESSED_REPEAT:
	{
		if (copiesCnt == 1) break;
		copiesCnt--;
		sprintf(buf,  "%d" , copiesCnt);
		lv_label_set_text(guider_ui.scrCopy2_labelCounter, buf);
		break;
	}
    default:
        break;
    }
}

void events_init_scrCopy2 (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrCopy2, scrCopy2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrCopy2_btnBack, scrCopy2_btnBack_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrCopy2_btnNext, scrCopy2_btnNext_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrCopy2_btnPlus, scrCopy2_btnPlus_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrCopy2_btnMinus, scrCopy2_btnMinus_event_handler, LV_EVENT_ALL, ui);
}

static void scrScan_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_animation(guider_ui.scrScan_contBG, 100, 0, lv_obj_get_width(guider_ui.scrScan_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrScan_contBG, 100, 0, lv_obj_get_height(guider_ui.scrScan_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrScan_sliderBright_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		slider_adjust_img_cb(guider_ui.scrScan_imgScanned, lv_slider_get_value(guider_ui.scrScan_sliderBright), lv_slider_get_value(guider_ui.scrScan_sliderHue));
		break;
	}
    default:
        break;
    }
}

static void scrScan_sliderHue_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		slider_adjust_img_cb(guider_ui.scrScan_imgScanned, lv_slider_get_value(guider_ui.scrScan_sliderBright), lv_slider_get_value(guider_ui.scrScan_sliderHue));
		break;
	}
    default:
        break;
    }
}

static void scrScan_btnNext_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrScanFini, guider_ui.scrScanFini_del, &guider_ui.scrScan_del, setup_scr_scrScanFini, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		lv_obj_set_style_bg_color(guider_ui.scrScan_contBG, lv_color_hex(0x28b620), LV_PART_MAIN);
		ui_animation(guider_ui.scrScan_contBG, 200, 0, lv_obj_get_width(guider_ui.scrScan_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrScan_contBG, 200, 0, lv_obj_get_height(guider_ui.scrScan_contBG), 272, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrScan_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrScan_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_NONE, 400, 200, false, true);
		break;
	}
    default:
        break;
    }
}

void events_init_scrScan (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrScan, scrScan_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrScan_sliderBright, scrScan_sliderBright_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrScan_sliderHue, scrScan_sliderHue_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrScan_btnNext, scrScan_btnNext_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrScan_btnBack, scrScan_btnBack_event_handler, LV_EVENT_ALL, ui);
}

static void scrPrintMenu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_width(guider_ui.scrPrintMenu_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_height(guider_ui.scrPrintMenu_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrPrintMenu_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrPrintMenu_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_width(guider_ui.scrPrintMenu_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_height(guider_ui.scrPrintMenu_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrPrintMenu_contInternet_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.scrPrintMenu_contBG, lv_color_hex(0xe12e2e), LV_PART_MAIN);
		ui_animation(guider_ui.scrPrintMenu_contBG, 200, 0, lv_obj_get_width(guider_ui.scrPrintMenu_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintMenu_contBG, 200, 0, lv_obj_get_height(guider_ui.scrPrintMenu_contBG), 272, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		ui_load_scr_animation(&guider_ui, &guider_ui.scrPrintInternet, guider_ui.scrPrintInternet_del, &guider_ui.scrPrintMenu_del, setup_scr_scrPrintInternet, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, false, true);
		break;
	}
    default:
        break;
    }
}

static void scrPrintMenu_contMobile_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrPrintMobile, guider_ui.scrPrintMobile_del, &guider_ui.scrPrintMenu_del, setup_scr_scrPrintMobile, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, false, true);
		ui_animation(guider_ui.scrPrintMenu_contBG, 200, 0, lv_obj_get_width(guider_ui.scrPrintMenu_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintMenu_contBG, 200, 0, lv_obj_get_height(guider_ui.scrPrintMenu_contBG), 272, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrPrintMenu_contUSB_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrPrintUSB, guider_ui.scrPrintUSB_del, &guider_ui.scrPrintMenu_del, setup_scr_scrPrintUSB, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_width(guider_ui.scrPrintMenu_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_height(guider_ui.scrPrintMenu_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

void events_init_scrPrintMenu (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrPrintMenu, scrPrintMenu_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrPrintMenu_btnBack, scrPrintMenu_btnBack_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrPrintMenu_contInternet, scrPrintMenu_contInternet_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrPrintMenu_contMobile, scrPrintMenu_contMobile_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrPrintMenu_contUSB, scrPrintMenu_contUSB_event_handler, LV_EVENT_ALL, ui);
}

static void scrPrintUSB_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_UNLOAD_START:
	{
		copiesCnt = 1;
		break;
	}
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_animation(guider_ui.scrPrintUSB_contBG, 100, 0, lv_obj_get_width(guider_ui.scrPrintUSB_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintUSB_contBG, 100, 0, lv_obj_get_height(guider_ui.scrPrintUSB_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		uint32_t i;
		static lv_style_t style_scrPrintUSB_listFiles_extra_btns_main_checked;
			ui_init_style(&style_scrPrintUSB_listFiles_extra_btns_main_checked);
			
			lv_style_set_pad_top(&style_scrPrintUSB_listFiles_extra_btns_main_checked, 5);
			lv_style_set_pad_left(&style_scrPrintUSB_listFiles_extra_btns_main_checked, 5);
			lv_style_set_pad_right(&style_scrPrintUSB_listFiles_extra_btns_main_checked, 5);
			lv_style_set_pad_bottom(&style_scrPrintUSB_listFiles_extra_btns_main_checked, 5);
			lv_style_set_border_width(&style_scrPrintUSB_listFiles_extra_btns_main_checked, 0);
			lv_style_set_text_color(&style_scrPrintUSB_listFiles_extra_btns_main_checked, lv_color_hex(0xffffff));
			lv_style_set_text_font(&style_scrPrintUSB_listFiles_extra_btns_main_checked, lv_obj_get_style_text_font(guider_ui.scrPrintUSB_listFiles_item0, LV_PART_MAIN|LV_STATE_DEFAULT));
			lv_style_set_radius(&style_scrPrintUSB_listFiles_extra_btns_main_checked, 3);
			lv_style_set_bg_opa(&style_scrPrintUSB_listFiles_extra_btns_main_checked, 255);
			lv_style_set_bg_color(&style_scrPrintUSB_listFiles_extra_btns_main_checked, lv_color_hex(0x969696));
			
		for(i = 0; i < lv_obj_get_child_cnt(guider_ui.scrPrintUSB_listFiles); i++) {
		    lv_obj_t * button = lv_obj_get_child(guider_ui.scrPrintUSB_listFiles, i);
		    lv_obj_add_flag(button, LV_OBJ_FLAG_CHECKABLE);
		    lv_obj_add_style(button, &style_scrPrintUSB_listFiles_extra_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
		}
		break;
	}
    default:
        break;
    }
}

static void scrPrintUSB_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrPrintUSB_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void scrPrintUSB_btnNext_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrLoader, guider_ui.scrLoader_del, &guider_ui.scrPrintUSB_del, setup_scr_scrLoader, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		ui_animation(guider_ui.scrPrintUSB_contBG, 200, 0, lv_obj_get_width(guider_ui.scrPrintUSB_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintUSB_contBG, 200, 0, lv_obj_get_height(guider_ui.scrPrintUSB_contBG), 272, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrPrintUSB_btnPlus_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		copiesCnt++;
		sprintf(buf,  "%d" , copiesCnt);
		lv_label_set_text(guider_ui.scrPrintUSB_labelCounter, buf);
		break;
	}
	case LV_EVENT_LONG_PRESSED_REPEAT:
	{
		copiesCnt++;
		sprintf(buf,  "%d" , copiesCnt);
		lv_label_set_text(guider_ui.scrPrintUSB_labelCounter, buf);
		break;
	}
    default:
        break;
    }
}

static void scrPrintUSB_btnMinus_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		if (copiesCnt == 1) break;
		copiesCnt--;
		sprintf(buf,  "%d" , copiesCnt);
		lv_label_set_text(guider_ui.scrPrintUSB_labelCounter, buf);
		break;
	}
	case LV_EVENT_LONG_PRESSED_REPEAT:
	{
		if (copiesCnt == 1) break;
		copiesCnt--;
		sprintf(buf,  "%d" , copiesCnt);
		lv_label_set_text(guider_ui.scrPrintUSB_labelCounter, buf);
		break;
	}
    default:
        break;
    }
}

void events_init_scrPrintUSB (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrPrintUSB, scrPrintUSB_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrPrintUSB_btnBack, scrPrintUSB_btnBack_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrPrintUSB_btnNext, scrPrintUSB_btnNext_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrPrintUSB_btnPlus, scrPrintUSB_btnPlus_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrPrintUSB_btnMinus, scrPrintUSB_btnMinus_event_handler, LV_EVENT_ALL, ui);
}

static void scrPrintMobile_btnNxet_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrPrintMobile_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		lv_obj_set_style_bg_color(guider_ui.scrPrintMobile_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN);
		ui_animation(guider_ui.scrPrintMobile_contBG, 200, 0, lv_obj_get_width(guider_ui.scrPrintMobile_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintMobile_contBG, 200, 0, lv_obj_get_height(guider_ui.scrPrintMobile_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

void events_init_scrPrintMobile (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrPrintMobile_btnNxet, scrPrintMobile_btnNxet_event_handler, LV_EVENT_ALL, ui);
}

static void scrPrintInternet_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrPrintInternet_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		lv_obj_set_style_bg_color(guider_ui.scrPrintInternet_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN);
		ui_animation(guider_ui.scrPrintInternet_contBG, 200, 0, lv_obj_get_width(guider_ui.scrPrintInternet_contBG), 480, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintInternet_contBG, 200, 0, lv_obj_get_height(guider_ui.scrPrintInternet_contBG), 60, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

void events_init_scrPrintInternet (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrPrintInternet_btnBack, scrPrintInternet_btnBack_event_handler, LV_EVENT_ALL, ui);
}

static void scrSetup_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrSetup_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 100, 200, false, true);
		lv_obj_set_style_bg_color(guider_ui.scrSetup_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN);
		ui_animation(guider_ui.scrSetup_contBG, 200, 0, lv_obj_get_width(guider_ui.scrSetup_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrSetup_contBG, 200, 0, lv_obj_get_height(guider_ui.scrSetup_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

void events_init_scrSetup (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrSetup_btnBack, scrSetup_btnBack_event_handler, LV_EVENT_ALL, ui);
}

static void scrLoader_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		lv_anim_t loader_arc;
		lv_anim_init(&loader_arc);
		lv_anim_set_exec_cb(&loader_arc, (lv_anim_exec_xcb_t)lv_arc_set_end_angle);
		lv_anim_set_values(&loader_arc, 0, 360);
		lv_anim_set_time(&loader_arc, 2000);
		lv_anim_set_delay(&loader_arc, 100);
		lv_anim_set_var(&loader_arc, guider_ui.scrLoader_arcLoader);
		lv_anim_start(&loader_arc);
		
		lv_anim_t loader_tp;
		lv_anim_init(&loader_tp);
		// lv_anim_set_exec_cb(&loader_tp, (lv_anim_exec_xcb_t)lv_textprogress_set_value);
		lv_anim_set_ready_cb(&loader_tp, load_scrPrintFini_cb);
		lv_anim_set_values(&loader_tp, 0, 100);
		lv_anim_set_time(&loader_tp, 2000);
		lv_anim_set_delay(&loader_tp, 100);
		lv_anim_set_var(&loader_tp, guider_ui.scrLoader_tpLoader);
		lv_anim_start(&loader_tp);
		break;
	}
    default:
        break;
    }
}

void events_init_scrLoader (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrLoader, scrLoader_event_handler, LV_EVENT_ALL, ui);
}

static void scrPrintFini_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_UNLOAD_START:
	{
		lv_obj_set_style_bg_color(guider_ui.scrPrintFini_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN);
		ui_animation(guider_ui.scrPrintFini_contBG, 200, 0, lv_obj_get_width(guider_ui.scrPrintFini_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrPrintFini_contBG, 200, 0, lv_obj_get_height(guider_ui.scrPrintFini_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrPrintFini_btnNxet_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrPrintFini_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 100, 200, false, true);
		break;
	}
    default:
        break;
    }
}

void events_init_scrPrintFini (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrPrintFini, scrPrintFini_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrPrintFini_btnNxet, scrPrintFini_btnNxet_event_handler, LV_EVENT_ALL, ui);
}

static void scrScanFini_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_SCREEN_UNLOAD_START:
	{
		lv_obj_set_style_bg_color(guider_ui.scrScanFini_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN);
		ui_animation(guider_ui.scrScanFini_contBG, 200, 0, lv_obj_get_width(guider_ui.scrScanFini_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
		ui_animation(guider_ui.scrScanFini_contBG, 200, 0, lv_obj_get_height(guider_ui.scrScanFini_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
		break;
	}
    default:
        break;
    }
}

static void scrScanFini_btnNxet_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrScanFini_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 400, 200, false, true);
		break;
	}
    default:
        break;
    }
}

void events_init_scrScanFini (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->scrScanFini, scrScanFini_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->scrScanFini_btnNxet, scrScanFini_btnNxet_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
