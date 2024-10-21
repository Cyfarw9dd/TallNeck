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



void setup_scr_scrCopy(lv_ui *ui)
{
	//Write codes scrCopy
	ui->scrCopy = lv_obj_create(NULL);
	lv_obj_set_size(ui->scrCopy, 536, 240);
	lv_obj_set_scrollbar_mode(ui->scrCopy, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrCopy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy_contBG
	ui->scrCopy_contBG = lv_obj_create(ui->scrCopy);
	lv_obj_set_pos(ui->scrCopy_contBG, 0, 0);
	lv_obj_set_size(ui->scrCopy_contBG, 536, 52);
	lv_obj_set_scrollbar_mode(ui->scrCopy_contBG, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrCopy_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy_labelTitle
	ui->scrCopy_labelTitle = lv_label_create(ui->scrCopy);
	lv_label_set_text(ui->scrCopy_labelTitle, "SCANNING IMAGE");
	lv_label_set_long_mode(ui->scrCopy_labelTitle, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrCopy_labelTitle, 150, 20);
	lv_obj_set_size(ui->scrCopy_labelTitle, 234, 28);

	//Write style for scrCopy_labelTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy_labelTitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy_labelTitle, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy_labelTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrCopy_labelTitle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrCopy_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy_labelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy_imgScanned
	ui->scrCopy_imgScanned = lv_img_create(ui->scrCopy);
	lv_obj_add_flag(ui->scrCopy_imgScanned, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrCopy_imgScanned, &_example_alpha_346x171);
	lv_img_set_pivot(ui->scrCopy_imgScanned, 0,0);
	lv_img_set_angle(ui->scrCopy_imgScanned, 0);
	lv_obj_set_pos(ui->scrCopy_imgScanned, 26, 52);
	lv_obj_set_size(ui->scrCopy_imgScanned, 346, 171);

	//Write style for scrCopy_imgScanned, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrCopy_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrCopy_imgScanned, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrCopy_imgScanned, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy_contPanel
	ui->scrCopy_contPanel = lv_obj_create(ui->scrCopy);
	lv_obj_set_pos(ui->scrCopy_contPanel, 397, 52);
	lv_obj_set_size(ui->scrCopy_contPanel, 111, 127);
	lv_obj_set_scrollbar_mode(ui->scrCopy_contPanel, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrCopy_contPanel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrCopy_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_contPanel, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrCopy_contPanel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy_contPanel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy_contPanel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrCopy_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrCopy_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrCopy_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrCopy_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy_contPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy_imgBright
	ui->scrCopy_imgBright = lv_img_create(ui->scrCopy_contPanel);
	lv_obj_add_flag(ui->scrCopy_imgBright, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrCopy_imgBright, &_bright_alpha_17x17);
	lv_img_set_pivot(ui->scrCopy_imgBright, 50,50);
	lv_img_set_angle(ui->scrCopy_imgBright, 0);
	lv_obj_set_pos(ui->scrCopy_imgBright, 20, 7);
	lv_obj_set_size(ui->scrCopy_imgBright, 17, 17);

	//Write style for scrCopy_imgBright, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrCopy_imgBright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrCopy_imgBright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_imgBright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrCopy_imgBright, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy_imgColor
	ui->scrCopy_imgColor = lv_img_create(ui->scrCopy_contPanel);
	lv_obj_add_flag(ui->scrCopy_imgColor, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrCopy_imgColor, &_hue_alpha_15x15);
	lv_img_set_pivot(ui->scrCopy_imgColor, 50,50);
	lv_img_set_angle(ui->scrCopy_imgColor, 0);
	lv_obj_set_pos(ui->scrCopy_imgColor, 68, 8);
	lv_obj_set_size(ui->scrCopy_imgColor, 15, 15);

	//Write style for scrCopy_imgColor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrCopy_imgColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrCopy_imgColor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_imgColor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrCopy_imgColor, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy_sliderBright
	ui->scrCopy_sliderBright = lv_slider_create(ui->scrCopy_contPanel);
	lv_slider_set_range(ui->scrCopy_sliderBright, 0, 100);
	lv_slider_set_mode(ui->scrCopy_sliderBright, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->scrCopy_sliderBright, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->scrCopy_sliderBright, 29, 33);
	lv_obj_set_size(ui->scrCopy_sliderBright, 5, 83);

	//Write style for scrCopy_sliderBright, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy_sliderBright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy_sliderBright, lv_color_hex(0xd2d2d2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy_sliderBright, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_sliderBright, 55, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->scrCopy_sliderBright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy_sliderBright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrCopy_sliderBright, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy_sliderBright, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_sliderBright, 55, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for scrCopy_sliderBright, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy_sliderBright, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy_sliderBright, lv_color_hex(0x000d2e), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy_sliderBright, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_sliderBright, 55, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes scrCopy_sliderHue
	ui->scrCopy_sliderHue = lv_slider_create(ui->scrCopy_contPanel);
	lv_slider_set_range(ui->scrCopy_sliderHue, 0, 359);
	lv_slider_set_mode(ui->scrCopy_sliderHue, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->scrCopy_sliderHue, 180, LV_ANIM_OFF);
	lv_obj_set_pos(ui->scrCopy_sliderHue, 75, 33);
	lv_obj_set_size(ui->scrCopy_sliderHue, 5, 83);

	//Write style for scrCopy_sliderHue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy_sliderHue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy_sliderHue, lv_color_hex(0xd2d2d2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy_sliderHue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_sliderHue, 55, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->scrCopy_sliderHue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy_sliderHue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrCopy_sliderHue, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy_sliderHue, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_sliderHue, 55, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for scrCopy_sliderHue, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy_sliderHue, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy_sliderHue, lv_color_hex(0x000d2e), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy_sliderHue, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_sliderHue, 55, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes scrCopy_btnNext
	ui->scrCopy_btnNext = lv_btn_create(ui->scrCopy);
	ui->scrCopy_btnNext_label = lv_label_create(ui->scrCopy_btnNext);
	lv_label_set_text(ui->scrCopy_btnNext_label, "NEXT");
	lv_label_set_long_mode(ui->scrCopy_btnNext_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrCopy_btnNext_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrCopy_btnNext, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrCopy_btnNext_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrCopy_btnNext, 397, 196);
	lv_obj_set_size(ui->scrCopy_btnNext, 111, 32);

	//Write style for scrCopy_btnNext, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy_btnNext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrCopy_btnNext, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrCopy_btnNext, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy_btnNext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_btnNext, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy_btnNext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy_btnNext, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy_btnNext, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy_btnNext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy_btnNext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrCopy_btnBack
	ui->scrCopy_btnBack = lv_btn_create(ui->scrCopy);
	ui->scrCopy_btnBack_label = lv_label_create(ui->scrCopy_btnBack);
	lv_label_set_text(ui->scrCopy_btnBack_label, "<");
	lv_label_set_long_mode(ui->scrCopy_btnBack_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->scrCopy_btnBack_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->scrCopy_btnBack, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->scrCopy_btnBack_label, LV_PCT(100));
	lv_obj_set_pos(ui->scrCopy_btnBack, 27, 15);
	lv_obj_set_size(ui->scrCopy_btnBack, 39, 28);

	//Write style for scrCopy_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrCopy_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scrCopy_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrCopy_btnBack, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrCopy_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrCopy_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrCopy_btnBack, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrCopy_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrCopy_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of scrCopy.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->scrCopy);

	//Init events for screen.
	events_init_scrCopy(ui);
}
