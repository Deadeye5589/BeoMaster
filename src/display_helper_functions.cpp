#include <Arduino.h>
#include <stdio.h>
#include "display_helpter_functions.h"
#include "memory.h"
#include "ui.h"
#include "ui2.h"
#include "dspcontrol.h"

/* PIO based WS2812 driver */
const uint NEOPIXELIO = LED; // Define your GPIO pin
const int NUMNEOPIXELS = 1; // Define number of neopixels

WS2812 neopixel = WS2812(NUMNEOPIXELS, NEOPIXELIO);

void display_set_volume_graphics(int8_t level){
  char buf[4];
  if(level == 100){
    sprintf(buf, "%02d", 0);
    lv_label_set_text(ui_varAmpLevel, buf);
    lv_obj_set_style_opa(ui_ImageMute, 255, 0);
  }
  else if (level==0){
    sprintf(buf, "%d", 0);
    lv_label_set_text(ui_varAmpLevel, buf);
  }
  else{
    lv_obj_set_style_opa(ui_ImageMute, 0, 0);
    sprintf(buf, "%02d", level*-1);
    lv_label_set_text(ui_varAmpLevel, buf);
  }
  lv_arc_set_value(ui_ArcLevel, 100-level);
  sprintf(buf, "%02d", level);
  lv_label_set_text(ui_varTemperatur,buf);
}

void display_load_right_screen(uint8_t screen){
  switch (screen)
  {
  case 1:
    lv_scr_load(ui2_Screen1);
    break;
  case 2:
    lv_scr_load(ui2_Screen2);
    break;
  case 3:
    lv_scr_load(ui2_Screen3);
    break;

  default:
    lv_scr_load(ui2_Screen1);
    break;
  }
}

void display_set_source(int8_t source){
 //Select USB inputs
    if(source == 2){
      digitalWrite(BT_RST, HIGH);
      dsp_i2c_select_source(true);
      neopixel.fillPixelColor(127,63,0);
    } 
    //Select BT input
    else if(source==1){
      digitalWrite(BT_RST, LOW);
      dsp_i2c_select_source(true);
      neopixel.fillPixelColor(0,0,127);

    }
    //Select Line input
    else{
      dsp_i2c_select_source(false);
      neopixel.fillPixelColor(0,127,0);
    }
    neopixel.show();          
    lv_roller_set_selected(ui_varRoller, source, LV_ANIM_ON);
}