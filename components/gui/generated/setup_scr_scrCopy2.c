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



void setup_scr_scrCopy2(lv_ui *ui)
{
	//Write codes scrCopy2
	ui->scrCopy2 = lv_obj_create(NULL);
	lv_obj_set_size(ui->scrCopy2, 536, 240);
	lv_obj_set_scrollbar_mode(ui->scrCopy2, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrCopy2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_contBG
	ui->scrCopy2_contBG = lv_obj_create(ui->scrCopy2);
	lv_obj_set_pos(ui->scrCopy2_contBG, 0, 0);
	lv_obj_set_size(ui->scrCopy2_contBG, 536, 52);
	lv_obj_set_scrollbar_mode(ui->scrCopy2_contBG, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrCopy2_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_btnBack
	ui->scrCopy2_btnBack = lv_btn_create(ui->scrCopy2_contBG);
	ui->scrCopy2_btnBack_label = lv_label_create(ui->scrCopy2_btnBack);
	lv_label_set_text(ui->scrCopy2_btnBack_label, "<");
	lv_label_set_long_mode(ui->scrCopy2_btnBack_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrCopy2_btnBack_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrCopy2_btnBack, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrCopy2_btnBack_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrCopy2_btnBack, 27, 15);
	lv_obj_set_size(ui->scrCopy2_btnBack, 39, 28);

	//Write style for scrCopy2_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy2_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_btnBack, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy2_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_btnBack, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy2_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_labelTitle
	ui->scrCopy2_labelTitle = lv_label_create(ui->scrCopy2);
	lv_label_set_text(ui->scrCopy2_labelTitle, "SCANNING IMAGE");
	lv_label_set_long_mode(ui->scrCopy2_labelTitle, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrCopy2_labelTitle, 150, 20);
	lv_obj_set_size(ui->scrCopy2_labelTitle, 234, 28);

	//Write style for scrCopy2_labelTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy2_labelTitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_labelTitle, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_labelTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrCopy2_labelTitle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy2_labelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_imgScanned
	ui->scrCopy2_imgScanned = lv_img_create(ui->scrCopy2);
	lv_obj_add_flag(ui->scrCopy2_imgScanned, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrCopy2_imgScanned, &_example_alpha_269x133);
	lv_img_set_pivot(ui->scrCopy2_imgScanned, 0,0);
	lv_img_set_angle(ui->scrCopy2_imgScanned, 0);
	lv_obj_set_pos(ui->scrCopy2_imgScanned, 26, 52);
	lv_obj_set_size(ui->scrCopy2_imgScanned, 269, 133);

	//Write style for scrCopy2_imgScanned, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrCopy2_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrCopy2_imgScanned, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrCopy2_imgScanned, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_btnNext
	ui->scrCopy2_btnNext = lv_btn_create(ui->scrCopy2);
	ui->scrCopy2_btnNext_label = lv_label_create(ui->scrCopy2_btnNext);
	lv_label_set_text(ui->scrCopy2_btnNext_label, "NEXT");
	lv_label_set_long_mode(ui->scrCopy2_btnNext_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrCopy2_btnNext_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrCopy2_btnNext, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrCopy2_btnNext_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrCopy2_btnNext, 326, 193);
	lv_obj_set_size(ui->scrCopy2_btnNext, 183, 33);

	//Write style for scrCopy2_btnNext, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy2_btnNext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_btnNext, lv_color_hex(0x28b620), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_btnNext, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_btnNext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_btnNext, 21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_btnNext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy2_btnNext, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_btnNext, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_btnNext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy2_btnNext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_contPanel
	ui->scrCopy2_contPanel = lv_obj_create(ui->scrCopy2);
	lv_obj_set_pos(ui->scrCopy2_contPanel, 326, 52);
	lv_obj_set_size(ui->scrCopy2_contPanel, 183, 125);
	lv_obj_set_scrollbar_mode(ui->scrCopy2_contPanel, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrCopy2_contPanel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy2_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_contPanel, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_contPanel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_contPanel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_contPanel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy2_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_labelCopies
	ui->scrCopy2_labelCopies = lv_label_create(ui->scrCopy2_contPanel);
	lv_label_set_text(ui->scrCopy2_labelCopies, "Copies");
	lv_label_set_long_mode(ui->scrCopy2_labelCopies, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrCopy2_labelCopies, 35, 6);
	lv_obj_set_size(ui->scrCopy2_labelCopies, 111, 28);

	//Write style for scrCopy2_labelCopies, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy2_labelCopies, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_labelCopies, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_labelCopies, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy2_labelCopies, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_labelCopies, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_labelCounter
	ui->scrCopy2_labelCounter = lv_label_create(ui->scrCopy2_contPanel);
	lv_label_set_text(ui->scrCopy2_labelCounter, "1");
	lv_label_set_long_mode(ui->scrCopy2_labelCounter, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrCopy2_labelCounter, 53, 30);
	lv_obj_set_size(ui->scrCopy2_labelCounter, 71, 26);

	//Write style for scrCopy2_labelCounter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy2_labelCounter, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scrCopy2_labelCounter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scrCopy2_labelCounter, lv_color_hex(0x909090), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->scrCopy2_labelCounter, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_labelCounter, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy2_labelCounter, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_labelCounter, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_labelCounter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrCopy2_labelCounter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrCopy2_labelCounter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy2_labelCounter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_labelCounter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_labelCounter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_labelCounter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy2_labelCounter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_labelCounter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_labelCounter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_btnPlus
	ui->scrCopy2_btnPlus = lv_btn_create(ui->scrCopy2_contPanel);
	ui->scrCopy2_btnPlus_label = lv_label_create(ui->scrCopy2_btnPlus);
	lv_label_set_text(ui->scrCopy2_btnPlus_label, "+");
	lv_label_set_long_mode(ui->scrCopy2_btnPlus_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrCopy2_btnPlus_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrCopy2_btnPlus, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrCopy2_btnPlus_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrCopy2_btnPlus, 136, 30);
	lv_obj_set_size(ui->scrCopy2_btnPlus, 39, 26);

	//Write style for scrCopy2_btnPlus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy2_btnPlus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_btnPlus, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_btnPlus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_btnPlus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_btnPlus, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_btnPlus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy2_btnPlus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_btnPlus, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_btnPlus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy2_btnPlus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_btnMinus
	ui->scrCopy2_btnMinus = lv_btn_create(ui->scrCopy2_contPanel);
	ui->scrCopy2_btnMinus_label = lv_label_create(ui->scrCopy2_btnMinus);
	lv_label_set_text(ui->scrCopy2_btnMinus_label, "-");
	lv_label_set_long_mode(ui->scrCopy2_btnMinus_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrCopy2_btnMinus_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrCopy2_btnMinus, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrCopy2_btnMinus_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrCopy2_btnMinus, 6, 30);
	lv_obj_set_size(ui->scrCopy2_btnMinus, 39, 26);

	//Write style for scrCopy2_btnMinus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy2_btnMinus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_btnMinus, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_btnMinus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_btnMinus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_btnMinus, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_btnMinus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy2_btnMinus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_btnMinus, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_btnMinus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy2_btnMinus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_labelColor
	ui->scrCopy2_labelColor = lv_label_create(ui->scrCopy2_contPanel);
	lv_label_set_text(ui->scrCopy2_labelColor, "Color");
	lv_label_set_long_mode(ui->scrCopy2_labelColor, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrCopy2_labelColor, 5, 74);
	lv_obj_set_size(ui->scrCopy2_labelColor, 69, 22);

	//Write style for scrCopy2_labelColor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy2_labelColor, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_labelColor, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_labelColor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy2_labelColor, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_labelColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_labelVertical
	ui->scrCopy2_labelVertical = lv_label_create(ui->scrCopy2_contPanel);
	lv_label_set_text(ui->scrCopy2_labelVertical, "Vertical\n");
	lv_label_set_long_mode(ui->scrCopy2_labelVertical, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrCopy2_labelVertical, 83, 75);
	lv_obj_set_size(ui->scrCopy2_labelVertical, 96, 22);

	//Write style for scrCopy2_labelVertical, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy2_labelVertical, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_labelVertical, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_labelVertical, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy2_labelVertical, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_labelVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_swColor
	ui->scrCopy2_swColor = lv_switch_create(ui->scrCopy2_contPanel);
	lv_obj_set_pos(ui->scrCopy2_swColor, 14, 97);
	lv_obj_set_size(ui->scrCopy2_swColor, 49, 19);

	//Write style for scrCopy2_swColor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy2_swColor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_swColor, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_swColor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_swColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_swColor, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_swColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrCopy2_swColor, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->scrCopy2_swColor, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->scrCopy2_swColor, lv_color_hex(0x28b620), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_swColor, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->scrCopy2_swColor, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for scrCopy2_swColor, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy2_swColor, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_swColor, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_swColor, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_swColor, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_swColor, 111, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes scrCopy2_swVertical
	ui->scrCopy2_swVertical = lv_switch_create(ui->scrCopy2_contPanel);
	lv_obj_set_pos(ui->scrCopy2_swVertical, 109, 97);
	lv_obj_set_size(ui->scrCopy2_swVertical, 49, 19);

	//Write style for scrCopy2_swVertical, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy2_swVertical, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_swVertical, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_swVertical, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_swVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_swVertical, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_swVertical, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrCopy2_swVertical, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->scrCopy2_swVertical, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->scrCopy2_swVertical, lv_color_hex(0x28b620), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_swVertical, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->scrCopy2_swVertical, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for scrCopy2_swVertical, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy2_swVertical, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_swVertical, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_swVertical, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_swVertical, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_swVertical, 111, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes scrCopy2_contDDLpanel
	ui->scrCopy2_contDDLpanel = lv_obj_create(ui->scrCopy2);
	lv_obj_set_pos(ui->scrCopy2_contDDLpanel, 26, 193);
	lv_obj_set_size(ui->scrCopy2_contDDLpanel, 269, 39);
	lv_obj_set_scrollbar_mode(ui->scrCopy2_contDDLpanel, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrCopy2_contDDLpanel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy2_contDDLpanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_contDDLpanel, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_contDDLpanel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_contDDLpanel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_contDDLpanel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_contDDLpanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy2_contDDLpanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_contDDLpanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_contDDLpanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_contDDLpanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy2_ddlistMode
	ui->scrCopy2_ddlistMode = lv_dropdown_create(ui->scrCopy2_contDDLpanel);
	lv_dropdown_set_options(ui->scrCopy2_ddlistMode, "Best\nNormal\nDraft");
	lv_obj_set_pos(ui->scrCopy2_ddlistMode, 8, 7);
	lv_obj_set_size(ui->scrCopy2_ddlistMode, 120, 26);

	//Write style for scrCopy2_ddlistMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->scrCopy2_ddlistMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_ddlistMode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_ddlistMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_ddlistMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_ddlistMode, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_ddlistMode, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_ddlistMode, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_ddlistMode, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_ddlistMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_ddlistMode, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_ddlistMode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_ddlistMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrCopy2_ddlistMode, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_text_color(ui->scrCopy2_ddlistMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->scrCopy2_ddlistMode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->scrCopy2_ddlistMode, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->scrCopy2_ddlistMode, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_top(ui->scrCopy2_ddlistMode, 8, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_left(ui->scrCopy2_ddlistMode, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_right(ui->scrCopy2_ddlistMode, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_radius(ui->scrCopy2_ddlistMode, 3, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->scrCopy2_ddlistMode, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->scrCopy2_ddlistMode, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_ddlistMode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->scrCopy2_ddlistMode, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for scrCopy2_ddlistMode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->scrCopy2_ddlistMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->scrCopy2_ddlistMode, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->scrCopy2_ddlistMode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->scrCopy2_ddlistMode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->scrCopy2_ddlistMode, 8, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->scrCopy2_ddlistMode, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->scrCopy2_ddlistMode, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->scrCopy2_ddlistMode, 3, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->scrCopy2_ddlistMode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->scrCopy2_ddlistMode, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_ddlistMode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->scrCopy2_ddlistMode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style for scrCopy2_ddlistMode, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
	lv_obj_set_style_text_color(ui->scrCopy2_ddlistMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_text_font(ui->scrCopy2_ddlistMode, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_text_opa(ui->scrCopy2_ddlistMode, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_width(ui->scrCopy2_ddlistMode, 1, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_opa(ui->scrCopy2_ddlistMode, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_color(ui->scrCopy2_ddlistMode, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_side(ui->scrCopy2_ddlistMode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_top(ui->scrCopy2_ddlistMode, 8, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_left(ui->scrCopy2_ddlistMode, 6, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_right(ui->scrCopy2_ddlistMode, 6, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_radius(ui->scrCopy2_ddlistMode, 3, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_opa(ui->scrCopy2_ddlistMode, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_color(ui->scrCopy2_ddlistMode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_ddlistMode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_shadow_width(ui->scrCopy2_ddlistMode, 0, LV_PART_MAIN|LV_STATE_DISABLED);

	//Write style state: LV_STATE_CHECKED for &style_scrCopy2_ddlistMode_extra_list_selected_checked
	static lv_style_t style_scrCopy2_ddlistMode_extra_list_selected_checked;
	ui_init_style(&style_scrCopy2_ddlistMode_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_scrCopy2_ddlistMode_extra_list_selected_checked, 0);
	lv_style_set_radius(&style_scrCopy2_ddlistMode_extra_list_selected_checked, 0);
	lv_style_set_bg_opa(&style_scrCopy2_ddlistMode_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_scrCopy2_ddlistMode_extra_list_selected_checked, lv_color_hex(0x2f3243));
	lv_style_set_bg_grad_dir(&style_scrCopy2_ddlistMode_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->scrCopy2_ddlistMode), &style_scrCopy2_ddlistMode_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_scrCopy2_ddlistMode_extra_list_main_default
	static lv_style_t style_scrCopy2_ddlistMode_extra_list_main_default;
	ui_init_style(&style_scrCopy2_ddlistMode_extra_list_main_default);
	
	lv_style_set_max_height(&style_scrCopy2_ddlistMode_extra_list_main_default, 90);
	lv_style_set_text_color(&style_scrCopy2_ddlistMode_extra_list_main_default, lv_color_hex(0x2f3243));
	lv_style_set_text_font(&style_scrCopy2_ddlistMode_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_scrCopy2_ddlistMode_extra_list_main_default, 255);
	lv_style_set_border_width(&style_scrCopy2_ddlistMode_extra_list_main_default, 0);
	lv_style_set_radius(&style_scrCopy2_ddlistMode_extra_list_main_default, 0);
	lv_style_set_bg_opa(&style_scrCopy2_ddlistMode_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_scrCopy2_ddlistMode_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_scrCopy2_ddlistMode_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->scrCopy2_ddlistMode), &style_scrCopy2_ddlistMode_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_scrCopy2_ddlistMode_extra_list_scrollbar_default
	static lv_style_t style_scrCopy2_ddlistMode_extra_list_scrollbar_default;
	ui_init_style(&style_scrCopy2_ddlistMode_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_scrCopy2_ddlistMode_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_scrCopy2_ddlistMode_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_scrCopy2_ddlistMode_extra_list_scrollbar_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_scrCopy2_ddlistMode_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->scrCopy2_ddlistMode), &style_scrCopy2_ddlistMode_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes scrCopy2_ddlistDPI
	ui->scrCopy2_ddlistDPI = lv_dropdown_create(ui->scrCopy2_contDDLpanel);
	lv_dropdown_set_options(ui->scrCopy2_ddlistDPI, "72 DPI\n96 DPI\n150 DPI\n300 DPI\n600 DPI\n900 DPI\n1200 DPI");
	lv_obj_set_pos(ui->scrCopy2_ddlistDPI, 139, 7);
	lv_obj_set_size(ui->scrCopy2_ddlistDPI, 120, 26);

	//Write style for scrCopy2_ddlistDPI, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->scrCopy2_ddlistDPI, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy2_ddlistDPI, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy2_ddlistDPI, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy2_ddlistDPI, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy2_ddlistDPI, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy2_ddlistDPI, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy2_ddlistDPI, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy2_ddlistDPI, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy2_ddlistDPI, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy2_ddlistDPI, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_ddlistDPI, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy2_ddlistDPI, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrCopy2_ddlistDPI, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_text_color(ui->scrCopy2_ddlistDPI, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->scrCopy2_ddlistDPI, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->scrCopy2_ddlistDPI, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->scrCopy2_ddlistDPI, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_top(ui->scrCopy2_ddlistDPI, 8, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_left(ui->scrCopy2_ddlistDPI, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_right(ui->scrCopy2_ddlistDPI, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_radius(ui->scrCopy2_ddlistDPI, 3, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->scrCopy2_ddlistDPI, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->scrCopy2_ddlistDPI, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_ddlistDPI, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->scrCopy2_ddlistDPI, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for scrCopy2_ddlistDPI, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->scrCopy2_ddlistDPI, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->scrCopy2_ddlistDPI, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->scrCopy2_ddlistDPI, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->scrCopy2_ddlistDPI, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->scrCopy2_ddlistDPI, 8, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->scrCopy2_ddlistDPI, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->scrCopy2_ddlistDPI, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->scrCopy2_ddlistDPI, 3, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->scrCopy2_ddlistDPI, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->scrCopy2_ddlistDPI, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_ddlistDPI, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->scrCopy2_ddlistDPI, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style for scrCopy2_ddlistDPI, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
	lv_obj_set_style_text_color(ui->scrCopy2_ddlistDPI, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_text_font(ui->scrCopy2_ddlistDPI, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_text_opa(ui->scrCopy2_ddlistDPI, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_width(ui->scrCopy2_ddlistDPI, 1, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_opa(ui->scrCopy2_ddlistDPI, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_color(ui->scrCopy2_ddlistDPI, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_side(ui->scrCopy2_ddlistDPI, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_top(ui->scrCopy2_ddlistDPI, 8, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_left(ui->scrCopy2_ddlistDPI, 6, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_right(ui->scrCopy2_ddlistDPI, 6, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_radius(ui->scrCopy2_ddlistDPI, 3, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_opa(ui->scrCopy2_ddlistDPI, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_color(ui->scrCopy2_ddlistDPI, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy2_ddlistDPI, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_shadow_width(ui->scrCopy2_ddlistDPI, 0, LV_PART_MAIN|LV_STATE_DISABLED);

	//Write style state: LV_STATE_CHECKED for &style_scrCopy2_ddlistDPI_extra_list_selected_checked
	static lv_style_t style_scrCopy2_ddlistDPI_extra_list_selected_checked;
	ui_init_style(&style_scrCopy2_ddlistDPI_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_scrCopy2_ddlistDPI_extra_list_selected_checked, 0);
	lv_style_set_radius(&style_scrCopy2_ddlistDPI_extra_list_selected_checked, 0);
	lv_style_set_bg_opa(&style_scrCopy2_ddlistDPI_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_scrCopy2_ddlistDPI_extra_list_selected_checked, lv_color_hex(0x2f3243));
	lv_style_set_bg_grad_dir(&style_scrCopy2_ddlistDPI_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->scrCopy2_ddlistDPI), &style_scrCopy2_ddlistDPI_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_scrCopy2_ddlistDPI_extra_list_main_default
	static lv_style_t style_scrCopy2_ddlistDPI_extra_list_main_default;
	ui_init_style(&style_scrCopy2_ddlistDPI_extra_list_main_default);
	
	lv_style_set_max_height(&style_scrCopy2_ddlistDPI_extra_list_main_default, 90);
	lv_style_set_text_color(&style_scrCopy2_ddlistDPI_extra_list_main_default, lv_color_hex(0x2f3243));
	lv_style_set_text_font(&style_scrCopy2_ddlistDPI_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_scrCopy2_ddlistDPI_extra_list_main_default, 255);
	lv_style_set_border_width(&style_scrCopy2_ddlistDPI_extra_list_main_default, 0);
	lv_style_set_radius(&style_scrCopy2_ddlistDPI_extra_list_main_default, 0);
	lv_style_set_bg_opa(&style_scrCopy2_ddlistDPI_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_scrCopy2_ddlistDPI_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_scrCopy2_ddlistDPI_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->scrCopy2_ddlistDPI), &style_scrCopy2_ddlistDPI_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_scrCopy2_ddlistDPI_extra_list_scrollbar_default
	static lv_style_t style_scrCopy2_ddlistDPI_extra_list_scrollbar_default;
	ui_init_style(&style_scrCopy2_ddlistDPI_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_scrCopy2_ddlistDPI_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_scrCopy2_ddlistDPI_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_scrCopy2_ddlistDPI_extra_list_scrollbar_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_scrCopy2_ddlistDPI_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->scrCopy2_ddlistDPI), &style_scrCopy2_ddlistDPI_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//The custom code of scrCopy2.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->scrCopy2);

	//Init events for screen.
	events_init_scrCopy2(ui);
}
