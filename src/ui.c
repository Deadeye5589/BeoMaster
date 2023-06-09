// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: AmpDisplay

#include "ui.h"
#include "ui_helpers.h"


///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_Screen1;
lv_obj_t *ui_KreisBG;
lv_obj_t *ui_ArcLevel;
lv_obj_t *ui_KreisKnopf;
lv_obj_t *ui_KreisLCD;
lv_obj_t *ui_varRoller;
lv_obj_t *ui_SourceSelect;
lv_obj_t *ui_varAmpLevel;
lv_obj_t *ui_Dot1;
lv_obj_t *ui_Dot2;
lv_obj_t *ui_Dot3;
lv_obj_t *ui_Dot4;
lv_obj_t *ui_Dot5;
lv_obj_t *ui_Nulldb;
lv_obj_t *ui_Infdb;
lv_obj_t *ui_varTemperatur;
lv_obj_t *ui_GradCelsius;
lv_obj_t *ui_AmpTemp;
lv_obj_t *ui_ImageMute;
lv_obj_t *ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM );    /// Flags
lv_obj_set_scrollbar_mode(ui_Screen1, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_bg_img_src( ui_Screen1, &ui_img_display_left_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_KreisBG = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_KreisBG, 130);
lv_obj_set_height( ui_KreisBG, 130);
lv_obj_set_x( ui_KreisBG, -70 );
lv_obj_set_y( ui_KreisBG, 0 );
lv_obj_set_align( ui_KreisBG, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_KreisBG, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_KreisBG, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_radius(ui_KreisBG, 360, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_KreisBG, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_KreisBG, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_KreisBG, lv_color_hex(0x182029), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_KreisBG, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_KreisBG, 6, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_KreisBG, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_KreisBG, 100, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_KreisBG, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_KreisBG, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_KreisBG, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_KreisBG, 3, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ArcLevel = lv_arc_create(ui_Screen1);
lv_obj_set_width( ui_ArcLevel, 120);
lv_obj_set_height( ui_ArcLevel, 120);
lv_obj_set_x( ui_ArcLevel, -70 );
lv_obj_set_y( ui_ArcLevel, 0 );
lv_obj_set_align( ui_ArcLevel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ArcLevel, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_ArcLevel, LV_SCROLLBAR_MODE_OFF);
lv_arc_set_value(ui_ArcLevel, 100);
lv_arc_set_bg_angles(ui_ArcLevel,0,300);
lv_arc_set_rotation(ui_ArcLevel,120);
lv_obj_set_style_arc_color(ui_ArcLevel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_ArcLevel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_pad_left(ui_ArcLevel, -2, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_ArcLevel, -2, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_ArcLevel, -2, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_ArcLevel, -2, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_KreisKnopf = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_KreisKnopf, 100);
lv_obj_set_height( ui_KreisKnopf, 100);
lv_obj_set_x( ui_KreisKnopf, -70 );
lv_obj_set_y( ui_KreisKnopf, 0 );
lv_obj_set_align( ui_KreisKnopf, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_KreisKnopf, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_KreisKnopf, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_radius(ui_KreisKnopf, 90, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_KreisKnopf, lv_color_hex(0x525562), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_KreisKnopf, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_KreisKnopf, lv_color_hex(0x393841), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_main_stop(ui_KreisKnopf, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_stop(ui_KreisKnopf, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_dir(ui_KreisKnopf, LV_GRAD_DIR_VER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_KreisKnopf, lv_color_hex(0x293039), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_KreisKnopf, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_KreisKnopf, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_KreisKnopf, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_KreisKnopf, 100, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_KreisKnopf, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_KreisKnopf, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_KreisKnopf, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_KreisKnopf, 5, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_KreisLCD = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_KreisLCD, 80);
lv_obj_set_height( ui_KreisLCD, 80);
lv_obj_set_x( ui_KreisLCD, -70 );
lv_obj_set_y( ui_KreisLCD, 0 );
lv_obj_set_align( ui_KreisLCD, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_KreisLCD, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_KreisLCD, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_radius(ui_KreisLCD, 90, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_KreisLCD, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_KreisLCD, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_varRoller = lv_roller_create(ui_Screen1);
lv_roller_set_options( ui_varRoller, "Line\nBT\nUSB", LV_ROLLER_MODE_INFINITE );
lv_obj_set_width( ui_varRoller, 60);
lv_obj_set_height( ui_varRoller, 90);
lv_obj_set_x( ui_varRoller, 106 );
lv_obj_set_y( ui_varRoller, 5 );
lv_obj_set_align( ui_varRoller, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_varRoller, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags

ui_SourceSelect = lv_textarea_create(ui_Screen1);
lv_obj_set_width( ui_SourceSelect, 80);
lv_obj_set_height( ui_SourceSelect, 50);
lv_obj_set_x( ui_SourceSelect, 106 );
lv_obj_set_y( ui_SourceSelect, -56 );
lv_obj_set_align( ui_SourceSelect, LV_ALIGN_CENTER );
lv_textarea_set_text(ui_SourceSelect,"Select\nSource");
lv_textarea_set_placeholder_text(ui_SourceSelect,"Placeholder...");
lv_obj_clear_flag( ui_SourceSelect, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_SourceSelect, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_text_color(ui_SourceSelect, lv_color_hex(0x747F92), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SourceSelect, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_SourceSelect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SourceSelect, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_SourceSelect, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SourceSelect, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_SourceSelect, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_varAmpLevel = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_varAmpLevel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_varAmpLevel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_varAmpLevel, -70 );
lv_obj_set_y( ui_varAmpLevel, 0 );
lv_obj_set_align( ui_varAmpLevel, LV_ALIGN_CENTER );
lv_label_set_text(ui_varAmpLevel,"0");
lv_obj_clear_flag( ui_varAmpLevel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_varAmpLevel, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_text_color(ui_varAmpLevel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_varAmpLevel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_varAmpLevel, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_varAmpLevel, &ui_font_Digitaled, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Dot1 = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Dot1, 4);
lv_obj_set_height( ui_Dot1, 4);
lv_obj_set_x( ui_Dot1, -70 );
lv_obj_set_y( ui_Dot1, -70 );
lv_obj_set_align( ui_Dot1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Dot1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_Dot1, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_bg_color(ui_Dot1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Dot1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Dot1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Dot2 = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Dot2, 4);
lv_obj_set_height( ui_Dot2, 4);
lv_obj_set_x( ui_Dot2, -2 );
lv_obj_set_y( ui_Dot2, -20 );
lv_obj_set_align( ui_Dot2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Dot2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_Dot2, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_bg_color(ui_Dot2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Dot2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Dot2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Dot3 = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Dot3, 4);
lv_obj_set_height( ui_Dot3, 4);
lv_obj_set_x( ui_Dot3, -138 );
lv_obj_set_y( ui_Dot3, -20 );
lv_obj_set_align( ui_Dot3, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Dot3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_Dot3, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_bg_color(ui_Dot3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Dot3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Dot3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Dot4 = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Dot4, 4);
lv_obj_set_height( ui_Dot4, 4);
lv_obj_set_x( ui_Dot4, -22 );
lv_obj_set_y( ui_Dot4, 54 );
lv_obj_set_align( ui_Dot4, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Dot4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_Dot4, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_bg_color(ui_Dot4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Dot4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Dot4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Dot5 = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Dot5, 4);
lv_obj_set_height( ui_Dot5, 4);
lv_obj_set_x( ui_Dot5, -118 );
lv_obj_set_y( ui_Dot5, 54 );
lv_obj_set_align( ui_Dot5, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Dot5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_Dot5, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_bg_color(ui_Dot5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Dot5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Dot5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Nulldb = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Nulldb, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Nulldb, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Nulldb, -3 );
lv_obj_set_y( ui_Nulldb, 60 );
lv_obj_set_align( ui_Nulldb, LV_ALIGN_CENTER );
lv_label_set_text(ui_Nulldb,"0 dB");
lv_obj_clear_flag( ui_Nulldb, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_Nulldb, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_text_font(ui_Nulldb, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Infdb = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Infdb, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Infdb, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Infdb, -136 );
lv_obj_set_y( ui_Infdb, 60 );
lv_obj_set_align( ui_Infdb, LV_ALIGN_CENTER );
lv_label_set_text(ui_Infdb,"- Inf");
lv_obj_clear_flag( ui_Infdb, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_Infdb, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_text_font(ui_Infdb, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_varTemperatur = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_varTemperatur, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_varTemperatur, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_varTemperatur, 119 );
lv_obj_set_y( ui_varTemperatur, 60 );
lv_obj_set_align( ui_varTemperatur, LV_ALIGN_CENTER );
lv_label_set_text(ui_varTemperatur,"31");
lv_obj_clear_flag( ui_varTemperatur, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_varTemperatur, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_text_color(ui_varTemperatur, lv_color_hex(0x747F92), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_varTemperatur, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_varTemperatur, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_GradCelsius = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_GradCelsius, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_GradCelsius, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_GradCelsius, 135 );
lv_obj_set_y( ui_GradCelsius, 60 );
lv_obj_set_align( ui_GradCelsius, LV_ALIGN_CENTER );
lv_label_set_text(ui_GradCelsius,"°C");
lv_obj_clear_flag( ui_GradCelsius, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_GradCelsius, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_text_color(ui_GradCelsius, lv_color_hex(0x747F92), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_GradCelsius, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_GradCelsius, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AmpTemp = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_AmpTemp, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_AmpTemp, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_AmpTemp, 91 );
lv_obj_set_y( ui_AmpTemp, 60 );
lv_obj_set_align( ui_AmpTemp, LV_ALIGN_CENTER );
lv_label_set_text(ui_AmpTemp,"Temp:");
lv_obj_clear_flag( ui_AmpTemp, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_AmpTemp, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_text_color(ui_AmpTemp, lv_color_hex(0x747F92), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AmpTemp, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_AmpTemp, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImageMute = lv_img_create(ui_Screen1);
lv_img_set_src(ui_ImageMute, &ui_img_mutesymbolscaled_png);
lv_obj_set_width( ui_ImageMute, 80);
lv_obj_set_height( ui_ImageMute, 80);
lv_obj_set_x( ui_ImageMute, -70 );
lv_obj_set_y( ui_ImageMute, 0 );
lv_obj_set_align( ui_ImageMute, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ImageMute, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_img_set_zoom(ui_ImageMute,180);
lv_obj_set_scrollbar_mode(ui_ImageMute, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_opa(ui_ImageMute, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

}

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Screen1_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_Screen1);
}
