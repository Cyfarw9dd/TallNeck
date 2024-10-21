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



void setup_scr_scrPrintFini(lv_ui *ui)
{
	//Write codes scrPrintFini
	ui->scrPrintFini = lv_obj_create(NULL);
	lv_obj_set_size(ui->scrPrintFini, 536, 240);
	lv_obj_set_scrollbar_mode(ui->scrPrintFini, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrPrintFini, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrPrintFini, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrPrintFini, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrPrintFini, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintFini_contBG
	ui->scrPrintFini_contBG = lv_obj_create(ui->scrPrintFini);
	lv_obj_set_pos(ui->scrPrintFini_contBG, 0, 0);
	lv_obj_set_size(ui->scrPrintFini_contBG, 536, 240);
	lv_obj_set_scrollbar_mode(ui->scrPrintFini_contBG, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrPrintFini_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrPrintFini_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintFini_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrPrintFini_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrPrintFini_contBG, lv_color_hex(0x28b620), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrPrintFini_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrPrintFini_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrPrintFini_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrPrintFini_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrPrintFini_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrPrintFini_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintFini_btnNxet
	ui->scrPrintFini_btnNxet = lv_btn_create(ui->scrPrintFini_contBG);
	ui->scrPrintFini_btnNxet_label = lv_label_create(ui->scrPrintFini_btnNxet);
	lv_label_set_text(ui->scrPrintFini_btnNxet_label, "CONTINUE");
	lv_label_set_long_mode(ui->scrPrintFini_btnNxet_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrPrintFini_btnNxet_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrPrintFini_btnNxet, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrPrintFini_btnNxet_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrPrintFini_btnNxet, 180, 186);
	lv_obj_set_size(ui->scrPrintFini_btnNxet, 174, 34);

	//Write style for scrPrintFini_btnNxet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrPrintFini_btnNxet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrPrintFini_btnNxet, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scrPrintFini_btnNxet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scrPrintFini_btnNxet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->scrPrintFini_btnNxet, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintFini_btnNxet, 21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrPrintFini_btnNxet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrPrintFini_btnNxet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrPrintFini_btnNxet, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrPrintFini_btnNxet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrPrintFini_btnNxet, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintFini_imgIconOk
	ui->scrPrintFini_imgIconOk = lv_img_create(ui->scrPrintFini);
	lv_obj_add_flag(ui->scrPrintFini_imgIconOk, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrPrintFini_imgIconOk, &_ready_alpha_97x97);
	lv_img_set_pivot(ui->scrPrintFini_imgIconOk, 55,55);
	lv_img_set_angle(ui->scrPrintFini_imgIconOk, 0);
	lv_obj_set_pos(ui->scrPrintFini_imgIconOk, 206, 31);
	lv_obj_set_size(ui->scrPrintFini_imgIconOk, 97, 97);

	//Write style for scrPrintFini_imgIconOk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrPrintFini_imgIconOk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrPrintFini_imgIconOk, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintFini_imgIconOk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrPrintFini_imgIconOk, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrPrintFini_labelPrompt
	ui->scrPrintFini_labelPrompt = lv_label_create(ui->scrPrintFini);
	lv_label_set_text(ui->scrPrintFini_labelPrompt, "Printing finished");
	lv_label_set_long_mode(ui->scrPrintFini_labelPrompt, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrPrintFini_labelPrompt, 81, 148);
	lv_obj_set_size(ui->scrPrintFini_labelPrompt, 374, 28);

	//Write style for scrPrintFini_labelPrompt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrPrintFini_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrPrintFini_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrPrintFini_labelPrompt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrPrintFini_labelPrompt, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrPrintFini_labelPrompt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrPrintFini_labelPrompt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrPrintFini_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrPrintFini_labelPrompt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrPrintFini_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrPrintFini_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrPrintFini_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrPrintFini_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrPrintFini_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrPrintFini_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of scrPrintFini.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->scrPrintFini);

	//Init events for screen.
	events_init_scrPrintFini(ui);
}
