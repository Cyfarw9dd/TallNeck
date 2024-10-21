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



void setup_scr_scrHome(lv_ui *ui)
{
	//Write codes scrHome
	ui->scrHome = lv_obj_create(NULL);
	lv_obj_set_size(ui->scrHome, 536, 240);
	lv_obj_set_scrollbar_mode(ui->scrHome, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrHome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrHome, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_contBG
	ui->scrHome_contBG = lv_obj_create(ui->scrHome);
	lv_obj_set_pos(ui->scrHome_contBG, 0, 0);
	lv_obj_set_size(ui->scrHome_contBG, 536, 52);
	lv_obj_set_scrollbar_mode(ui->scrHome_contBG, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrHome_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_contMain
	ui->scrHome_contMain = lv_obj_create(ui->scrHome);
	lv_obj_set_pos(ui->scrHome_contMain, 39, 55);
	lv_obj_set_size(ui->scrHome_contMain, 457, 123);
	lv_obj_set_scrollbar_mode(ui->scrHome_contMain, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrHome_contMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_contMain, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_contMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_contMain, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_contMain, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_contSetup
	ui->scrHome_contSetup = lv_obj_create(ui->scrHome_contMain);
	lv_obj_set_pos(ui->scrHome_contSetup, 341, 8);
	lv_obj_set_size(ui->scrHome_contSetup, 111, 105);
	lv_obj_set_scrollbar_mode(ui->scrHome_contSetup, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrHome_contSetup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_contSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_contSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_contSetup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_contSetup, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_contSetup, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_contSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_contSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_contSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_contSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->scrHome_contSetup, &_btn_bg_4_111x105, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->scrHome_contSetup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->scrHome_contSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_contSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_imgIconSetup
	ui->scrHome_imgIconSetup = lv_img_create(ui->scrHome_contSetup);
	lv_obj_add_flag(ui->scrHome_imgIconSetup, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrHome_imgIconSetup, &_setup_alpha_35x35);
	lv_img_set_pivot(ui->scrHome_imgIconSetup, 50,50);
	lv_img_set_angle(ui->scrHome_imgIconSetup, 0);
	lv_obj_set_pos(ui->scrHome_imgIconSetup, 50, 16);
	lv_obj_set_size(ui->scrHome_imgIconSetup, 35, 35);
	lv_obj_add_flag(ui->scrHome_imgIconSetup, LV_OBJ_FLAG_EVENT_BUBBLE);

	//Write style for scrHome_imgIconSetup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrHome_imgIconSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrHome_imgIconSetup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_imgIconSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrHome_imgIconSetup, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_labelSetup
	ui->scrHome_labelSetup = lv_label_create(ui->scrHome_contSetup);
	lv_label_set_text(ui->scrHome_labelSetup, "SETUP");
	lv_label_set_long_mode(ui->scrHome_labelSetup, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrHome_labelSetup, 5, 78);
	lv_obj_set_size(ui->scrHome_labelSetup, 85, 16);
	lv_obj_add_flag(ui->scrHome_labelSetup, LV_OBJ_FLAG_EVENT_BUBBLE);

	//Write style for scrHome_labelSetup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrHome_labelSetup, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrHome_labelSetup, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrHome_labelSetup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrHome_labelSetup, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_labelSetup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_contPrint
	ui->scrHome_contPrint = lv_obj_create(ui->scrHome_contMain);
	lv_obj_set_pos(ui->scrHome_contPrint, 230, 8);
	lv_obj_set_size(ui->scrHome_contPrint, 111, 105);
	lv_obj_set_scrollbar_mode(ui->scrHome_contPrint, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrHome_contPrint, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_contPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_contPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_contPrint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_contPrint, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_contPrint, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_contPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_contPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_contPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_contPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->scrHome_contPrint, &_btn_bg_3_111x105, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->scrHome_contPrint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->scrHome_contPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_contPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_imgIconPrint
	ui->scrHome_imgIconPrint = lv_img_create(ui->scrHome_contPrint);
	lv_obj_add_flag(ui->scrHome_imgIconPrint, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrHome_imgIconPrint, &_print_alpha_35x35);
	lv_img_set_pivot(ui->scrHome_imgIconPrint, 50,50);
	lv_img_set_angle(ui->scrHome_imgIconPrint, 0);
	lv_obj_set_pos(ui->scrHome_imgIconPrint, 50, 16);
	lv_obj_set_size(ui->scrHome_imgIconPrint, 35, 35);
	lv_obj_add_flag(ui->scrHome_imgIconPrint, LV_OBJ_FLAG_EVENT_BUBBLE);

	//Write style for scrHome_imgIconPrint, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrHome_imgIconPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrHome_imgIconPrint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_imgIconPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrHome_imgIconPrint, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_labelPrint
	ui->scrHome_labelPrint = lv_label_create(ui->scrHome_contPrint);
	lv_label_set_text(ui->scrHome_labelPrint, "PRINT");
	lv_label_set_long_mode(ui->scrHome_labelPrint, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrHome_labelPrint, 3, 78);
	lv_obj_set_size(ui->scrHome_labelPrint, 85, 16);
	lv_obj_add_flag(ui->scrHome_labelPrint, LV_OBJ_FLAG_EVENT_BUBBLE);

	//Write style for scrHome_labelPrint, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrHome_labelPrint, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrHome_labelPrint, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrHome_labelPrint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrHome_labelPrint, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_labelPrint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_contCopy
	ui->scrHome_contCopy = lv_obj_create(ui->scrHome_contMain);
	lv_obj_set_pos(ui->scrHome_contCopy, 6, 8);
	lv_obj_set_size(ui->scrHome_contCopy, 111, 105);
	lv_obj_set_scrollbar_mode(ui->scrHome_contCopy, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrHome_contCopy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_contCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_contCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_contCopy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_contCopy, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_contCopy, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_contCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_contCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_contCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_contCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->scrHome_contCopy, &_btn_bg_1_111x105, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->scrHome_contCopy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->scrHome_contCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_contCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_imgIconCopy
	ui->scrHome_imgIconCopy = lv_img_create(ui->scrHome_contCopy);
	lv_obj_add_flag(ui->scrHome_imgIconCopy, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrHome_imgIconCopy, &_copy_alpha_41x35);
	lv_img_set_pivot(ui->scrHome_imgIconCopy, 50,50);
	lv_img_set_angle(ui->scrHome_imgIconCopy, 0);
	lv_obj_set_pos(ui->scrHome_imgIconCopy, 50, 16);
	lv_obj_set_size(ui->scrHome_imgIconCopy, 41, 35);
	lv_obj_add_flag(ui->scrHome_imgIconCopy, LV_OBJ_FLAG_EVENT_BUBBLE);

	//Write style for scrHome_imgIconCopy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrHome_imgIconCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrHome_imgIconCopy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_imgIconCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrHome_imgIconCopy, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_labelCopy
	ui->scrHome_labelCopy = lv_label_create(ui->scrHome_contCopy);
	lv_label_set_text(ui->scrHome_labelCopy, "COPY");
	lv_label_set_long_mode(ui->scrHome_labelCopy, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrHome_labelCopy, 3, 78);
	lv_obj_set_size(ui->scrHome_labelCopy, 85, 16);
	lv_obj_add_flag(ui->scrHome_labelCopy, LV_OBJ_FLAG_EVENT_BUBBLE);

	//Write style for scrHome_labelCopy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrHome_labelCopy, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrHome_labelCopy, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrHome_labelCopy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrHome_labelCopy, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_labelCopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_contScan
	ui->scrHome_contScan = lv_obj_create(ui->scrHome_contMain);
	lv_obj_set_pos(ui->scrHome_contScan, 118, 8);
	lv_obj_set_size(ui->scrHome_contScan, 111, 105);
	lv_obj_set_scrollbar_mode(ui->scrHome_contScan, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrHome_contScan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_contScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_contScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_contScan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_contScan, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_contScan, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_contScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_contScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_contScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_contScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->scrHome_contScan, &_btn_bg_2_111x105, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->scrHome_contScan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->scrHome_contScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_contScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_imgIconScan
	ui->scrHome_imgIconScan = lv_img_create(ui->scrHome_contScan);
	lv_obj_add_flag(ui->scrHome_imgIconScan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrHome_imgIconScan, &_scan_alpha_41x35);
	lv_img_set_pivot(ui->scrHome_imgIconScan, 50,50);
	lv_img_set_angle(ui->scrHome_imgIconScan, 0);
	lv_obj_set_pos(ui->scrHome_imgIconScan, 50, 16);
	lv_obj_set_size(ui->scrHome_imgIconScan, 41, 35);
	lv_obj_add_flag(ui->scrHome_imgIconScan, LV_OBJ_FLAG_EVENT_BUBBLE);

	//Write style for scrHome_imgIconScan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrHome_imgIconScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrHome_imgIconScan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_imgIconScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrHome_imgIconScan, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_labelScan
	ui->scrHome_labelScan = lv_label_create(ui->scrHome_contScan);
	lv_label_set_text(ui->scrHome_labelScan, "SCAN");
	lv_label_set_long_mode(ui->scrHome_labelScan, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrHome_labelScan, 3, 78);
	lv_obj_set_size(ui->scrHome_labelScan, 85, 16);
	lv_obj_add_flag(ui->scrHome_labelScan, LV_OBJ_FLAG_EVENT_BUBBLE);

	//Write style for scrHome_labelScan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrHome_labelScan, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrHome_labelScan, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrHome_labelScan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrHome_labelScan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_labelScan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_contTop
	ui->scrHome_contTop = lv_obj_create(ui->scrHome);
	lv_obj_set_pos(ui->scrHome_contTop, 25, 0);
	lv_obj_set_size(ui->scrHome_contTop, 484, 53);
	lv_obj_set_scrollbar_mode(ui->scrHome_contTop, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrHome_contTop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_contTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_contTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_contTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_contTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_contTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_contTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_contTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_contTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_imgIconWIFI
	ui->scrHome_imgIconWIFI = lv_img_create(ui->scrHome_contTop);
	lv_obj_add_flag(ui->scrHome_imgIconWIFI, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrHome_imgIconWIFI, &_wifi_alpha_36x22);
	lv_img_set_pivot(ui->scrHome_imgIconWIFI, 50,50);
	lv_img_set_angle(ui->scrHome_imgIconWIFI, 0);
	lv_obj_set_pos(ui->scrHome_imgIconWIFI, 22, 18);
	lv_obj_set_size(ui->scrHome_imgIconWIFI, 36, 22);

	//Write style for scrHome_imgIconWIFI, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrHome_imgIconWIFI, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrHome_imgIconWIFI, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_imgIconWIFI, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrHome_imgIconWIFI, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_imgIconCall
	ui->scrHome_imgIconCall = lv_img_create(ui->scrHome_contTop);
	lv_obj_add_flag(ui->scrHome_imgIconCall, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrHome_imgIconCall, &_tel_alpha_31x21);
	lv_img_set_pivot(ui->scrHome_imgIconCall, 50,50);
	lv_img_set_angle(ui->scrHome_imgIconCall, 0);
	lv_obj_set_pos(ui->scrHome_imgIconCall, 79, 19);
	lv_obj_set_size(ui->scrHome_imgIconCall, 31, 21);

	//Write style for scrHome_imgIconCall, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrHome_imgIconCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrHome_imgIconCall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_imgIconCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrHome_imgIconCall, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_imgIconEco
	ui->scrHome_imgIconEco = lv_img_create(ui->scrHome_contTop);
	lv_obj_add_flag(ui->scrHome_imgIconEco, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrHome_imgIconEco, &_eco_alpha_32x19);
	lv_img_set_pivot(ui->scrHome_imgIconEco, 50,50);
	lv_img_set_angle(ui->scrHome_imgIconEco, 0);
	lv_obj_set_pos(ui->scrHome_imgIconEco, 127, 18);
	lv_obj_set_size(ui->scrHome_imgIconEco, 32, 19);

	//Write style for scrHome_imgIconEco, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrHome_imgIconEco, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrHome_imgIconEco, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_imgIconEco, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrHome_imgIconEco, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_imgIconPC
	ui->scrHome_imgIconPC = lv_img_create(ui->scrHome_contTop);
	lv_obj_add_flag(ui->scrHome_imgIconPC, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scrHome_imgIconPC, &_pc_alpha_33x21);
	lv_img_set_pivot(ui->scrHome_imgIconPC, 50,50);
	lv_img_set_angle(ui->scrHome_imgIconPC, 0);
	lv_obj_set_pos(ui->scrHome_imgIconPC, 185, 18);
	lv_obj_set_size(ui->scrHome_imgIconPC, 33, 21);

	//Write style for scrHome_imgIconPC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->scrHome_imgIconPC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scrHome_imgIconPC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_imgIconPC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->scrHome_imgIconPC, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_labelDate
	ui->scrHome_labelDate = lv_label_create(ui->scrHome_contTop);
	lv_label_set_text(ui->scrHome_labelDate, "22 Aug 2023  14:30");
	lv_label_set_long_mode(ui->scrHome_labelDate, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrHome_labelDate, 245, 22);
	lv_obj_set_size(ui->scrHome_labelDate, 243, 24);

	//Write style for scrHome_labelDate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrHome_labelDate, lv_color_hex(0xe9e9e9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrHome_labelDate, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrHome_labelDate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrHome_labelDate, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_labelDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_labelPrompt
	ui->scrHome_labelPrompt = lv_label_create(ui->scrHome);
	lv_label_set_text(ui->scrHome_labelPrompt, "\nWhat do you want to do today?");
	lv_label_set_long_mode(ui->scrHome_labelPrompt, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->scrHome_labelPrompt, 39, 191);
	lv_obj_set_size(ui->scrHome_labelPrompt, 278, 39);

	//Write style for scrHome_labelPrompt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_labelPrompt, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scrHome_labelPrompt, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scrHome_labelPrompt, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->scrHome_labelPrompt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scrHome_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scrHome_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scrHome_labelPrompt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_labelPrompt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_labelPrompt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_labelPrompt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_labelPrompt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_contColorInk
	ui->scrHome_contColorInk = lv_obj_create(ui->scrHome);
	lv_obj_set_pos(ui->scrHome_contColorInk, 339, 185);
	lv_obj_set_size(ui->scrHome_contColorInk, 157, 45);
	lv_obj_set_scrollbar_mode(ui->scrHome_contColorInk, LV_SCROLLBAR_MODE_OFF);

	//Write style for scrHome_contColorInk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->scrHome_contColorInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_contColorInk, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scrHome_contColorInk, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_contColorInk, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_contColorInk, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scrHome_contColorInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scrHome_contColorInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scrHome_contColorInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scrHome_contColorInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_contColorInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scrHome_barBlueInk
	ui->scrHome_barBlueInk = lv_bar_create(ui->scrHome_contColorInk);
	lv_obj_set_style_anim_time(ui->scrHome_barBlueInk, 1000, 0);
	lv_bar_set_mode(ui->scrHome_barBlueInk, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->scrHome_barBlueInk, 0, 100);
	lv_bar_set_value(ui->scrHome_barBlueInk, 80, LV_ANIM_ON);
	lv_obj_set_pos(ui->scrHome_barBlueInk, 11, 0);
	lv_obj_set_size(ui->scrHome_barBlueInk, 26, 44);

	//Write style for scrHome_barBlueInk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrHome_barBlueInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_barBlueInk, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_barBlueInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrHome_barBlueInk, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrHome_barBlueInk, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_barBlueInk, lv_color_hex(0x2ad3ff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_barBlueInk, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_barBlueInk, 11, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes scrHome_barRedInk
	ui->scrHome_barRedInk = lv_bar_create(ui->scrHome_contColorInk);
	lv_obj_set_style_anim_time(ui->scrHome_barRedInk, 1000, 0);
	lv_bar_set_mode(ui->scrHome_barRedInk, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->scrHome_barRedInk, 0, 100);
	lv_bar_set_value(ui->scrHome_barRedInk, 25, LV_ANIM_ON);
	lv_obj_set_pos(ui->scrHome_barRedInk, 45, 0);
	lv_obj_set_size(ui->scrHome_barRedInk, 23, 44);

	//Write style for scrHome_barRedInk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrHome_barRedInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_barRedInk, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_barRedInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrHome_barRedInk, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrHome_barRedInk, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_barRedInk, lv_color_hex(0xef1382), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_barRedInk, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_barRedInk, 11, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes scrHome_barYellowInk
	ui->scrHome_barYellowInk = lv_bar_create(ui->scrHome_contColorInk);
	lv_obj_set_style_anim_time(ui->scrHome_barYellowInk, 1000, 0);
	lv_bar_set_mode(ui->scrHome_barYellowInk, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->scrHome_barYellowInk, 0, 100);
	lv_bar_set_value(ui->scrHome_barYellowInk, 70, LV_ANIM_ON);
	lv_obj_set_pos(ui->scrHome_barYellowInk, 77, 0);
	lv_obj_set_size(ui->scrHome_barYellowInk, 26, 44);

	//Write style for scrHome_barYellowInk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrHome_barYellowInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_barYellowInk, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_barYellowInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrHome_barYellowInk, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrHome_barYellowInk, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_barYellowInk, lv_color_hex(0xe4ea09), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_barYellowInk, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_barYellowInk, 11, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes scrHome_barBlackInk
	ui->scrHome_barBlackInk = lv_bar_create(ui->scrHome_contColorInk);
	lv_obj_set_style_anim_time(ui->scrHome_barBlackInk, 1000, 0);
	lv_bar_set_mode(ui->scrHome_barBlackInk, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->scrHome_barBlackInk, 0, 100);
	lv_bar_set_value(ui->scrHome_barBlackInk, 55, LV_ANIM_ON);
	lv_obj_set_pos(ui->scrHome_barBlackInk, 115, -1);
	lv_obj_set_size(ui->scrHome_barBlackInk, 26, 44);

	//Write style for scrHome_barBlackInk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrHome_barBlackInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_barBlackInk, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scrHome_barBlackInk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for scrHome_barBlackInk, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->scrHome_barBlackInk, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scrHome_barBlackInk, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scrHome_barBlackInk, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->scrHome_barBlackInk, 11, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//The custom code of scrHome.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->scrHome);

	//Init events for screen.
	events_init_scrHome(ui);
}
