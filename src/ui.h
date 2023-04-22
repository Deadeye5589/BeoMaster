// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: AmpDisplay

#ifndef _AMPDISPLAY_UI_H
#define _AMPDISPLAY_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lvgl.h>

#include "ui_events.h"
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_KreisBG;
extern lv_obj_t * ui_ArcLevel;
extern lv_obj_t * ui_KreisKnopf;
extern lv_obj_t * ui_KreisLCD;
extern lv_obj_t * ui_BoxRechts;
extern lv_obj_t * ui_varRoller;
extern lv_obj_t * ui_SourceSelect;
extern lv_obj_t * ui_varAmpLevel;
extern lv_obj_t * ui_Dot1;
extern lv_obj_t * ui_Dot2;
extern lv_obj_t * ui_Dot3;
extern lv_obj_t * ui_Dot4;
extern lv_obj_t * ui_Dot5;
extern lv_obj_t * ui_Nulldb;
extern lv_obj_t * ui_Infdb;
extern lv_obj_t * ui_varTemperatur;
extern lv_obj_t * ui_GradCelsius;
extern lv_obj_t * ui_AmpTemp;
extern lv_obj_t * ui_ImageMute;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_mutesymbolscaled_png);    // assets\mutesymbolscaled.png


LV_FONT_DECLARE(ui_font_Digitaled);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif