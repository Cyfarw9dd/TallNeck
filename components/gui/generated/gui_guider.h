/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *scrHome;
	bool scrHome_del;
	lv_obj_t *scrHome_contBG;
	lv_obj_t *scrHome_contMain;
	lv_obj_t *scrHome_contSetup;
	lv_obj_t *scrHome_imgIconSetup;
	lv_obj_t *scrHome_labelSetup;
	lv_obj_t *scrHome_contPrint;
	lv_obj_t *scrHome_imgIconPrint;
	lv_obj_t *scrHome_labelPrint;
	lv_obj_t *scrHome_contCopy;
	lv_obj_t *scrHome_imgIconCopy;
	lv_obj_t *scrHome_labelCopy;
	lv_obj_t *scrHome_contScan;
	lv_obj_t *scrHome_imgIconScan;
	lv_obj_t *scrHome_labelScan;
	lv_obj_t *scrHome_contTop;
	lv_obj_t *scrHome_imgIconWIFI;
	lv_obj_t *scrHome_imgIconCall;
	lv_obj_t *scrHome_imgIconEco;
	lv_obj_t *scrHome_imgIconPC;
	lv_obj_t *scrHome_labelDate;
	lv_obj_t *scrHome_labelPrompt;
	lv_obj_t *scrHome_contColorInk;
	lv_obj_t *scrHome_barBlueInk;
	lv_obj_t *scrHome_barRedInk;
	lv_obj_t *scrHome_barYellowInk;
	lv_obj_t *scrHome_barBlackInk;
	lv_obj_t *scrCopy;
	bool scrCopy_del;
	lv_obj_t *scrCopy_contBG;
	lv_obj_t *scrCopy_labelTitle;
	lv_obj_t *scrCopy_imgScanned;
	lv_obj_t *scrCopy_contPanel;
	lv_obj_t *scrCopy_imgBright;
	lv_obj_t *scrCopy_imgColor;
	lv_obj_t *scrCopy_sliderBright;
	lv_obj_t *scrCopy_sliderHue;
	lv_obj_t *scrCopy_btnNext;
	lv_obj_t *scrCopy_btnNext_label;
	lv_obj_t *scrCopy_btnBack;
	lv_obj_t *scrCopy_btnBack_label;
	lv_obj_t *scrCopy2;
	bool scrCopy2_del;
	lv_obj_t *scrCopy2_contBG;
	lv_obj_t *scrCopy2_btnBack;
	lv_obj_t *scrCopy2_btnBack_label;
	lv_obj_t *scrCopy2_labelTitle;
	lv_obj_t *scrCopy2_imgScanned;
	lv_obj_t *scrCopy2_btnNext;
	lv_obj_t *scrCopy2_btnNext_label;
	lv_obj_t *scrCopy2_contPanel;
	lv_obj_t *scrCopy2_labelCopies;
	lv_obj_t *scrCopy2_labelCounter;
	lv_obj_t *scrCopy2_btnPlus;
	lv_obj_t *scrCopy2_btnPlus_label;
	lv_obj_t *scrCopy2_btnMinus;
	lv_obj_t *scrCopy2_btnMinus_label;
	lv_obj_t *scrCopy2_labelColor;
	lv_obj_t *scrCopy2_labelVertical;
	lv_obj_t *scrCopy2_swColor;
	lv_obj_t *scrCopy2_swVertical;
	lv_obj_t *scrCopy2_contDDLpanel;
	lv_obj_t *scrCopy2_ddlistMode;
	lv_obj_t *scrCopy2_ddlistDPI;
	lv_obj_t *scrScan;
	bool scrScan_del;
	lv_obj_t *scrScan_contBG;
	lv_obj_t *scrScan_labelTitle;
	lv_obj_t *scrScan_imgScanned;
	lv_obj_t *scrScan_contPanel;
	lv_obj_t *scrScan_imgIconBright;
	lv_obj_t *scrScan_imgIconHue;
	lv_obj_t *scrScan_sliderBright;
	lv_obj_t *scrScan_sliderHue;
	lv_obj_t *scrScan_btnNext;
	lv_obj_t *scrScan_btnNext_label;
	lv_obj_t *scrScan_btnBack;
	lv_obj_t *scrScan_btnBack_label;
	lv_obj_t *scrPrintMenu;
	bool scrPrintMenu_del;
	lv_obj_t *scrPrintMenu_contBG;
	lv_obj_t *scrPrintMenu_labelTitle;
	lv_obj_t *scrPrintMenu_btnBack;
	lv_obj_t *scrPrintMenu_btnBack_label;
	lv_obj_t *scrPrintMenu_labelPrompt;
	lv_obj_t *scrPrintMenu_contMain;
	lv_obj_t *scrPrintMenu_contInternet;
	lv_obj_t *scrPrintMenu_imgInternet;
	lv_obj_t *scrPrintMenu_labelnternet;
	lv_obj_t *scrPrintMenu_contMobile;
	lv_obj_t *scrPrintMenu_imgMobile;
	lv_obj_t *scrPrintMenu_labelMobile;
	lv_obj_t *scrPrintMenu_contUSB;
	lv_obj_t *scrPrintMenu_imgUSB;
	lv_obj_t *scrPrintMenu_labelUSB;
	lv_obj_t *scrPrintUSB;
	bool scrPrintUSB_del;
	lv_obj_t *scrPrintUSB_contBG;
	lv_obj_t *scrPrintUSB_btnBack;
	lv_obj_t *scrPrintUSB_btnBack_label;
	lv_obj_t *scrPrintUSB_labelTitle;
	lv_obj_t *scrPrintUSB_btnNext;
	lv_obj_t *scrPrintUSB_btnNext_label;
	lv_obj_t *scrPrintUSB_contPanel;
	lv_obj_t *scrPrintUSB_labelCopies;
	lv_obj_t *scrPrintUSB_labelCounter;
	lv_obj_t *scrPrintUSB_btnPlus;
	lv_obj_t *scrPrintUSB_btnPlus_label;
	lv_obj_t *scrPrintUSB_btnMinus;
	lv_obj_t *scrPrintUSB_btnMinus_label;
	lv_obj_t *scrPrintUSB_labelColor;
	lv_obj_t *scrPrintUSB_labelVertical;
	lv_obj_t *scrPrintUSB_swColor;
	lv_obj_t *scrPrintUSB_swVertical;
	lv_obj_t *scrPrintUSB_contDDLpanel;
	lv_obj_t *scrPrintUSB_ddlistMode;
	lv_obj_t *scrPrintUSB_ddlistDPI;
	lv_obj_t *scrPrintUSB_listFiles;
	lv_obj_t *scrPrintUSB_listFiles_item0;
	lv_obj_t *scrPrintUSB_listFiles_item1;
	lv_obj_t *scrPrintUSB_listFiles_item2;
	lv_obj_t *scrPrintUSB_listFiles_item3;
	lv_obj_t *scrPrintUSB_listFiles_item4;
	lv_obj_t *scrPrintUSB_listFiles_item5;
	lv_obj_t *scrPrintUSB_listFiles_item6;
	lv_obj_t *scrPrintUSB_listFiles_item7;
	lv_obj_t *scrPrintUSB_listFiles_item8;
	lv_obj_t *scrPrintUSB_listFiles_item9;
	lv_obj_t *scrPrintUSB_listFiles_item10;
	lv_obj_t *scrPrintUSB_listFiles_item11;
	lv_obj_t *scrPrintUSB_listFiles_item12;
	lv_obj_t *scrPrintUSB_listFiles_item13;
	lv_obj_t *scrPrintUSB_listFiles_item14;
	lv_obj_t *scrPrintUSB_listFiles_item15;
	lv_obj_t *scrPrintUSB_listFiles_item16;
	lv_obj_t *scrPrintUSB_listFiles_item17;
	lv_obj_t *scrPrintMobile;
	bool scrPrintMobile_del;
	lv_obj_t *scrPrintMobile_contBG;
	lv_obj_t *scrPrintMobile_imgPrinter;
	lv_obj_t *scrPrintMobile_imgWave;
	lv_obj_t *scrPrintMobile_imgPhone;
	lv_obj_t *scrPrintMobile_labelPrompt;
	lv_obj_t *scrPrintMobile_btnNxet;
	lv_obj_t *scrPrintMobile_btnNxet_label;
	lv_obj_t *scrPrintInternet;
	bool scrPrintInternet_del;
	lv_obj_t *scrPrintInternet_contBG;
	lv_obj_t *scrPrintInternet_imgPrinter;
	lv_obj_t *scrPrintInternet_imgWave;
	lv_obj_t *scrPrintInternet_imgCloud;
	lv_obj_t *scrPrintInternet_labelPrompt;
	lv_obj_t *scrPrintInternet_btnBack;
	lv_obj_t *scrPrintInternet_btnBack_label;
	lv_obj_t *scrSetup;
	bool scrSetup_del;
	lv_obj_t *scrSetup_contBG;
	lv_obj_t *scrSetup_imgPrinter;
	lv_obj_t *scrSetup_imgWave;
	lv_obj_t *scrSetup_imgCloud;
	lv_obj_t *scrSetup_labelPrompt;
	lv_obj_t *scrSetup_btnBack;
	lv_obj_t *scrSetup_btnBack_label;
	lv_obj_t *scrLoader;
	bool scrLoader_del;
	lv_obj_t *scrLoader_contBG;
	lv_obj_t *scrLoader_arcLoader;
	lv_obj_t *scrLoader_tpLoader;
	lv_obj_t *scrLoader_labelPrompt;
	lv_obj_t *scrPrintFini;
	bool scrPrintFini_del;
	lv_obj_t *scrPrintFini_contBG;
	lv_obj_t *scrPrintFini_btnNxet;
	lv_obj_t *scrPrintFini_btnNxet_label;
	lv_obj_t *scrPrintFini_imgIconOk;
	lv_obj_t *scrPrintFini_labelPrompt;
	lv_obj_t *scrScanFini;
	bool scrScanFini_del;
	lv_obj_t *scrScanFini_contBG;
	lv_obj_t *scrScanFini_imgIconOk;
	lv_obj_t *scrScanFini_labelPrompt;
	lv_obj_t *scrScanFini_btnNxet;
	lv_obj_t *scrScanFini_btnNxet_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_scrHome(lv_ui *ui);
void setup_scr_scrCopy(lv_ui *ui);
void setup_scr_scrCopy2(lv_ui *ui);
void setup_scr_scrScan(lv_ui *ui);
void setup_scr_scrPrintMenu(lv_ui *ui);
void setup_scr_scrPrintUSB(lv_ui *ui);
void setup_scr_scrPrintMobile(lv_ui *ui);
void setup_scr_scrPrintInternet(lv_ui *ui);
void setup_scr_scrSetup(lv_ui *ui);
void setup_scr_scrLoader(lv_ui *ui);
void setup_scr_scrPrintFini(lv_ui *ui);
void setup_scr_scrScanFini(lv_ui *ui);

LV_IMG_DECLARE(_btn_bg_4_50x236);
LV_IMG_DECLARE(_setup_alpha_20x20);

LV_IMG_DECLARE(_btn_bg_3_50x236);
LV_IMG_DECLARE(_print_alpha_20x20);

LV_IMG_DECLARE(_btn_bg_1_50x236);
LV_IMG_DECLARE(_copy_alpha_18x78);

LV_IMG_DECLARE(_btn_bg_2_50x236);
LV_IMG_DECLARE(_scan_alpha_18x78);
LV_IMG_DECLARE(_wifi_alpha_16x49);
LV_IMG_DECLARE(_tel_alpha_14x47);
LV_IMG_DECLARE(_eco_alpha_14x43);
LV_IMG_DECLARE(_pc_alpha_15x47);
LV_IMG_DECLARE(_example_alpha_155x382);
LV_IMG_DECLARE(_bright_alpha_10x10);
LV_IMG_DECLARE(_hue_alpha_9x9);
LV_IMG_DECLARE(_example_alpha_120x297);
LV_IMG_DECLARE(_example_alpha_155x382);
LV_IMG_DECLARE(_bright_alpha_10x10);
LV_IMG_DECLARE(_hue_alpha_9x9);

LV_IMG_DECLARE(_btn_bg_4_50x236);
LV_IMG_DECLARE(_internet_alpha_20x20);

LV_IMG_DECLARE(_btn_bg_3_50x236);
LV_IMG_DECLARE(_mobile_alpha_17x78);

LV_IMG_DECLARE(_btn_bg_2_50x236);
LV_IMG_DECLARE(_usb_alpha_20x78);
LV_IMG_DECLARE(_printer2_alpha_43x167);
LV_IMG_DECLARE(_wave_alpha_10x65);
LV_IMG_DECLARE(_phone_alpha_27x137);
LV_IMG_DECLARE(_printer2_alpha_42x153);
LV_IMG_DECLARE(_no_internet_alpha_20x72);
LV_IMG_DECLARE(_cloud_alpha_37x100);
LV_IMG_DECLARE(_printer2_alpha_42x153);
LV_IMG_DECLARE(_no_internet_alpha_20x72);
LV_IMG_DECLARE(_cloud_alpha_37x100);
LV_IMG_DECLARE(_ready_alpha_55x55);
LV_IMG_DECLARE(_ready_alpha_55x55);

LV_FONT_DECLARE(lv_font_montserratMedium_10)
LV_FONT_DECLARE(lv_font_montserratMedium_12)


#ifdef __cplusplus
}
#endif
#endif
