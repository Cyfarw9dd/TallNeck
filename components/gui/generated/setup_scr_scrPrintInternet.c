/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_scrPrintInternet(lv_ui *ui)
{
	//Write codes scrPrintInternet
	ui->scrPrintInternet = lv_obj_create(NULL);
	lv_obj_set_size(ui->scrPrintInternet, 536, 240);
	lv_obj_set_scrollbar_mode(ui->scrPrintInternet, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrPrintInternet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrPrintInternet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrPrintInternet, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrPrintInternet, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintInternet_contBG
	ui->scrPrintInternet_contBG = lv_obj_create(ui->scrPrintInternet);
	lv_obj_set_pos(ui->scrPrintInternet_contBG, 0, 0);
	lv_obj_set_size(ui->scrPrintInternet_contBG, 536, 240);
	lv_obj_set_scrollbar_mode(ui->scrPrintInternet_contBG, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrPrintInternet_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrPrintInternet_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintInternet_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrPrintInternet_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrPrintInternet_contBG, lv_color_hex(0xe12e2e), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrPrintInternet_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrPrintInternet_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrPrintInternet_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrPrintInternet_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrPrintInternet_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrPrintInternet_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintInternet_imgPrinter
	ui->scrPrintInternet_imgPrinter = lv_img_create(ui->scrPrintInternet_contBG);
	lv_obj_add_flag(ui->scrPrintInternet_imgPrinter, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrPrintInternet_imgPrinter, &_printer2_alpha_93x68);
	lv_img_set_pivot(ui->scrPrintInternet_imgPrinter, 55,55);
	lv_img_set_angle(ui->scrPrintInternet_imgPrinter, 0);
	lv_obj_set_pos(ui->scrPrintInternet_imgPrinter, 138, 68);
	lv_obj_set_size(ui->scrPrintInternet_imgPrinter, 93, 68);

	//Write style for scrPrintInternet_imgPrinter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrPrintInternet_imgPrinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrPrintInternet_imgPrinter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintInternet_imgPrinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrPrintInternet_imgPrinter, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintInternet_imgWave
	ui->scrPrintInternet_imgWave = lv_img_create(ui->scrPrintInternet_contBG);
	lv_obj_add_flag(ui->scrPrintInternet_imgWave, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrPrintInternet_imgWave, &_no_internet_alpha_44x32);
	lv_img_set_pivot(ui->scrPrintInternet_imgWave, 50,50);
	lv_img_set_angle(ui->scrPrintInternet_imgWave, 0);
	lv_obj_set_pos(ui->scrPrintInternet_imgWave, 246, 60);
	lv_obj_set_size(ui->scrPrintInternet_imgWave, 44, 32);

	//Write style for scrPrintInternet_imgWave, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrPrintInternet_imgWave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrPrintInternet_imgWave, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintInternet_imgWave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrPrintInternet_imgWave, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintInternet_imgCloud
	ui->scrPrintInternet_imgCloud = lv_img_create(ui->scrPrintInternet_contBG);
	lv_obj_add_flag(ui->scrPrintInternet_imgCloud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrPrintInternet_imgCloud, &_cloud_alpha_82x45);
	lv_img_set_pivot(ui->scrPrintInternet_imgCloud, 50,50);
	lv_img_set_angle(ui->scrPrintInternet_imgCloud, 0);
	lv_obj_set_pos(ui->scrPrintInternet_imgCloud, 309, 32);
	lv_obj_set_size(ui->scrPrintInternet_imgCloud, 82, 45);

	//Write style for scrPrintInternet_imgCloud, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrPrintInternet_imgCloud, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrPrintInternet_imgCloud, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintInternet_imgCloud, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrPrintInternet_imgCloud, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintInternet_labelPrompt
	ui->scrPrintInternet_labelPrompt = lv_label_create(ui->scrPrintInternet_contBG);
	lv_label_set_text(ui->scrPrintInternet_labelPrompt, "No internet connection");
	lv_label_set_long_mode(ui->scrPrintInternet_labelPrompt, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrPrintInternet_labelPrompt, 60, 153);
	lv_obj_set_size(ui->scrPrintInternet_labelPrompt, 415, 28);

	//Write style for scrPrintInternet_labelPrompt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrPrintInternet_labelPrompt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrPrintInternet_labelPrompt, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrPrintInternet_labelPrompt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrPrintInternet_labelPrompt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrPrintInternet_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintInternet_btnBack
	ui->scrPrintInternet_btnBack = lv_btn_create(ui->scrPrintInternet_contBG);
	ui->scrPrintInternet_btnBack_label = lv_label_create(ui->scrPrintInternet_btnBack);
	lv_label_set_text(ui->scrPrintInternet_btnBack_label, "BACK");
	lv_label_set_long_mode(ui->scrPrintInternet_btnBack_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrPrintInternet_btnBack_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrPrintInternet_btnBack, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrPrintInternet_btnBack_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrPrintInternet_btnBack, 201, 188);
	lv_obj_set_size(ui->scrPrintInternet_btnBack, 134, 34);

	//Write style for scrPrintInternet_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrPrintInternet_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrPrintInternet_btnBack, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scrPrintInternet_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scrPrintInternet_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->scrPrintInternet_btnBack, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintInternet_btnBack, 21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrPrintInternet_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrPrintInternet_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrPrintInternet_btnBack, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrPrintInternet_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrPrintInternet_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of scrPrintInternet.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->scrPrintInternet);

	//Init events for screen.
	events_init_scrPrintInternet(ui);
}
