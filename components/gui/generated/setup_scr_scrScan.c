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



void setup_scr_scrScan(lv_ui *ui)
{
	//Write codes scrScan
	ui->scrScan = lv_obj_create(NULL);
	lv_obj_set_size(ui->scrScan, 536, 240);
	lv_obj_set_scrollbar_mode(ui->scrScan, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrScan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrScan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrScan, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrScan, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrScan_contBG
	ui->scrScan_contBG = lv_obj_create(ui->scrScan);
	lv_obj_set_pos(ui->scrScan_contBG, 0, 0);
	lv_obj_set_size(ui->scrScan_contBG, 536, 52);
	lv_obj_set_scrollbar_mode(ui->scrScan_contBG, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrScan_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrScan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrScan_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrScan_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrScan_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrScan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrScan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrScan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrScan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrScan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrScan_labelTitle
	ui->scrScan_labelTitle = lv_label_create(ui->scrScan);
	lv_label_set_text(ui->scrScan_labelTitle, "SCANNING IMAGE");
	lv_label_set_long_mode(ui->scrScan_labelTitle, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrScan_labelTitle, 150, 20);
	lv_obj_set_size(ui->scrScan_labelTitle, 234, 28);

	//Write style for scrScan_labelTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrScan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrScan_labelTitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrScan_labelTitle, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrScan_labelTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrScan_labelTitle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrScan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrScan_labelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrScan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrScan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrScan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrScan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrScan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrScan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrScan_imgScanned
	ui->scrScan_imgScanned = lv_img_create(ui->scrScan);
	lv_obj_add_flag(ui->scrScan_imgScanned, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrScan_imgScanned, &_example_alpha_346x171);
	lv_img_set_pivot(ui->scrScan_imgScanned, 0,0);
	lv_img_set_angle(ui->scrScan_imgScanned, 0);
	lv_obj_set_pos(ui->scrScan_imgScanned, 26, 52);
	lv_obj_set_size(ui->scrScan_imgScanned, 346, 171);

	//Write style for scrScan_imgScanned, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrScan_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrScan_imgScanned, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrScan_imgScanned, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrScan_contPanel
	ui->scrScan_contPanel = lv_obj_create(ui->scrScan);
	lv_obj_set_pos(ui->scrScan_contPanel, 397, 52);
	lv_obj_set_size(ui->scrScan_contPanel, 111, 127);
	lv_obj_set_scrollbar_mode(ui->scrScan_contPanel, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrScan_contPanel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrScan_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_contPanel, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrScan_contPanel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrScan_contPanel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrScan_contPanel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrScan_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrScan_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrScan_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrScan_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrScan_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrScan_imgIconBright
	ui->scrScan_imgIconBright = lv_img_create(ui->scrScan_contPanel);
	lv_obj_add_flag(ui->scrScan_imgIconBright, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrScan_imgIconBright, &_bright_alpha_17x17);
	lv_img_set_pivot(ui->scrScan_imgIconBright, 50,50);
	lv_img_set_angle(ui->scrScan_imgIconBright, 0);
	lv_obj_set_pos(ui->scrScan_imgIconBright, 20, 7);
	lv_obj_set_size(ui->scrScan_imgIconBright, 17, 17);

	//Write style for scrScan_imgIconBright, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrScan_imgIconBright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrScan_imgIconBright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_imgIconBright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrScan_imgIconBright, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrScan_imgIconHue
	ui->scrScan_imgIconHue = lv_img_create(ui->scrScan_contPanel);
	lv_obj_add_flag(ui->scrScan_imgIconHue, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrScan_imgIconHue, &_hue_alpha_15x15);
	lv_img_set_pivot(ui->scrScan_imgIconHue, 50,50);
	lv_img_set_angle(ui->scrScan_imgIconHue, 0);
	lv_obj_set_pos(ui->scrScan_imgIconHue, 68, 8);
	lv_obj_set_size(ui->scrScan_imgIconHue, 15, 15);

	//Write style for scrScan_imgIconHue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrScan_imgIconHue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrScan_imgIconHue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_imgIconHue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrScan_imgIconHue, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrScan_sliderBright
	ui->scrScan_sliderBright = lv_slider_create(ui->scrScan_contPanel);
	lv_slider_set_range(ui->scrScan_sliderBright, 0, 100);
	lv_slider_set_mode(ui->scrScan_sliderBright, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->scrScan_sliderBright, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->scrScan_sliderBright, 29, 33);
	lv_obj_set_size(ui->scrScan_sliderBright, 5, 83);

	//Write style for scrScan_sliderBright, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrScan_sliderBright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrScan_sliderBright, lv_color_hex(0xd2d2d2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrScan_sliderBright, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_sliderBright, 55, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->scrScan_sliderBright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrScan_sliderBright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrScan_sliderBright, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrScan_sliderBright, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_sliderBright, 55, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for scrScan_sliderBright, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrScan_sliderBright, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrScan_sliderBright, lv_color_hex(0x000d2e), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrScan_sliderBright, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_sliderBright, 55, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes scrScan_sliderHue
	ui->scrScan_sliderHue = lv_slider_create(ui->scrScan_contPanel);
	lv_slider_set_range(ui->scrScan_sliderHue, 0, 359);
	lv_slider_set_mode(ui->scrScan_sliderHue, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->scrScan_sliderHue, 180, LV_ANIM_OFF);
	lv_obj_set_pos(ui->scrScan_sliderHue, 75, 33);
	lv_obj_set_size(ui->scrScan_sliderHue, 5, 83);

	//Write style for scrScan_sliderHue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrScan_sliderHue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrScan_sliderHue, lv_color_hex(0xd2d2d2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrScan_sliderHue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_sliderHue, 55, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->scrScan_sliderHue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrScan_sliderHue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrScan_sliderHue, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrScan_sliderHue, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_sliderHue, 55, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for scrScan_sliderHue, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrScan_sliderHue, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrScan_sliderHue, lv_color_hex(0x000d2e), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrScan_sliderHue, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_sliderHue, 55, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes scrScan_btnNext
	ui->scrScan_btnNext = lv_btn_create(ui->scrScan);
	ui->scrScan_btnNext_label = lv_label_create(ui->scrScan_btnNext);
	lv_label_set_text(ui->scrScan_btnNext_label, "NEXT");
	lv_label_set_long_mode(ui->scrScan_btnNext_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrScan_btnNext_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrScan_btnNext, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrScan_btnNext_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrScan_btnNext, 397, 196);
	lv_obj_set_size(ui->scrScan_btnNext, 111, 32);

	//Write style for scrScan_btnNext, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrScan_btnNext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrScan_btnNext, lv_color_hex(0x28b620), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrScan_btnNext, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrScan_btnNext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_btnNext, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrScan_btnNext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrScan_btnNext, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrScan_btnNext, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrScan_btnNext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrScan_btnNext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrScan_btnBack
	ui->scrScan_btnBack = lv_btn_create(ui->scrScan);
	ui->scrScan_btnBack_label = lv_label_create(ui->scrScan_btnBack);
	lv_label_set_text(ui->scrScan_btnBack_label, "<");
	lv_label_set_long_mode(ui->scrScan_btnBack_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrScan_btnBack_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrScan_btnBack, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrScan_btnBack_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrScan_btnBack, 27, 15);
	lv_obj_set_size(ui->scrScan_btnBack, 39, 28);

	//Write style for scrScan_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrScan_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrScan_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrScan_btnBack, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrScan_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrScan_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrScan_btnBack, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrScan_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrScan_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of scrScan.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->scrScan);

	//Init events for screen.
	events_init_scrScan(ui);
}
