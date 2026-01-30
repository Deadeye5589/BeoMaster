#include <lvgl.h>
#include <Arduino_GFX_Library.h>
#include <EncoderButton.h>
#include <I2C_eeprom.h>

#include "ui.h"
#include "ui2.h"
#include "display_helpter_functions.h"
#include "gpiohandler.h"
#include "pico_sleep.h"
#include "pico_rosc.h"
#include "dspcontrol.h"
#include "pico-ws2812/ws2812.h"
#include "memory.h"

volatile bool in_setup_function = 0;
volatile int16_t setup_function_value = 0;

/* Create Arduino GFX data busses and devices */
Arduino_DataBus *bus = new Arduino_RPiPicoSPI(DISP_DC1 /* DC */, DISP_CS1 /* CS */, DISP_CLK1 /* SCK */, DISP_DIN1 /* MOSI */, UINT8_MAX /* MISO */, spi1 /* spi */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, DISP_RST1 /* RST */, 3 /* rotation */, true /* IPS */, 170, 320, 35, 0, 35, 0);

Arduino_DataBus *bus2 = new Arduino_RPiPicoSPI(DISP_DC2 /* DC */, DISP_CS2 /* CS */, DISP_CLK2 /* SCK */, DISP_DIN2 /* MOSI */, UINT8_MAX /* MISO */, spi0 /* spi */);
Arduino_GFX *gfx2 = new Arduino_ST7789(bus2, DISP_RST2 /* RST */, 1 /* rotation */, true /* IPS */, 170, 320, 35, 0, 35, 0);

static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *disp_draw_buf;
static lv_disp_drv_t disp_drv;

static lv_disp_draw_buf_t draw_buf2;
static lv_color_t *disp_draw_buf2;
static lv_disp_drv_t disp_drv2;

/* Create encoder instances */
EncoderButton *eb1; //(20, 21, 22);
EncoderButton *eb2; //(16, 17, 18);

volatile int8_t encoder_resulution = 0;

/* Initialize FRAM classes */
I2C_eeprom fram(FRAM_ADDR, I2C_DEVICESIZE_24LC256, &Wire1);

/* Display flushing 1st display */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p){
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

  lv_disp_flush_ready(disp);
}


/* Display flushing 2nd display */
void my_disp2_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p){
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  gfx2->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx2->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

  lv_disp_flush_ready(disp);
}


void onEb1Clicked(EncoderButton& eb) {
  if(memory.screen_selected == 1 || memory.screen_selected == 2 || (memory.screen_selected == 3 && memory.select_setting == 6)){
  memory.screen_selected++;
  if(  memory.screen_selected > 3)
      memory.screen_selected = 1;
  display_load_right_screen(memory.screen_selected);
  }
  else{
    in_setup_function = !in_setup_function;
  }
}

/* A function to handle the 'right side' encoder event 
 Normall used to select source on left display, but in case
 the settings screen is select the same encoder will cycle 
 trough the settings instead */
void onEb1Encoder(EncoderButton& eb) {
  char buf[4];

  if(memory.screen_selected==3 && !in_setup_function){
    encoder_resulution += eb.increment();
    if(encoder_resulution % 2 == 0){
    memory.select_setting += eb.increment();
    }
    else return;

    if (memory.select_setting >= 6){
      memory.select_setting = 6;
    }
    else if(memory.select_setting <= 0){
      memory.select_setting = 0;
    }
    
    switch (memory.select_setting)
    {
    case 0:
      lv_label_set_text(ui2_Label4, "Adjust Delay Left Channel");
      setup_function_value = memory.delay_left;
      sprintf(buf, "%02d", memory.delay_left);
      lv_label_set_text(ui2_Label1, buf);
    break;

    case 1:
      lv_label_set_text(ui2_Label4, "Adjust Delay Right Channel");
      setup_function_value = memory.delay_right;
      sprintf(buf, "%02d", memory.delay_right);
      lv_label_set_text(ui2_Label1, buf); 
    break;

     case 2:
      lv_label_set_text(ui2_Label4, "Adjust Delay Subwoofer");
      setup_function_value = memory.delay_sub;
      sprintf(buf, "%02d", memory.delay_sub);
      lv_label_set_text(ui2_Label1, buf); 
    break;

    case 3:
      lv_label_set_text(ui2_Label4, "Adjust Subwoofer Volume");
      setup_function_value = memory.subwoofer_volume;
      if(setup_function_value == 0){
        lv_label_set_text(ui2_Label1, "0");
      }
      else{
        sprintf(buf, "%02d", memory.subwoofer_volume*-1);
        lv_label_set_text(ui2_Label1, buf);
      }
    break;

    case 4:
      lv_label_set_text(ui2_Label4, "Invert Subwoofer Phase");
      setup_function_value = memory.invert_subwoofer;
      if(memory.invert_subwoofer)
        lv_label_set_text(ui2_Label1, "-180°");
      else
        lv_label_set_text(ui2_Label1, "0°");
    break;

    case 5:
      lv_label_set_text(ui2_Label4, "Mirror EQ Display");  
      setup_function_value = memory.mirror_eq;
      if(memory.mirror_eq)
        lv_label_set_text(ui2_Label1, "True");
      else
        lv_label_set_text(ui2_Label1, "False"); 
    break;
    
    default:
      lv_label_set_text(ui2_Label4, "Adjust Settings"); 
      lv_label_set_text(ui2_Label1, "Save");
      break;
    }

    lv_roller_set_selected(ui2_Roller2, memory.select_setting, LV_ANIM_ON);
  }

  else if(memory.screen_selected==3 && in_setup_function){
    char buf[4];
    encoder_resulution += eb.increment();
    if(encoder_resulution % 2 == 0){
      setup_function_value += eb.increment();
    }
    else return;

    switch (memory.select_setting)
    {
    // Left channel delay
    case 0:
      if(setup_function_value > 500){
        setup_function_value = 500;
      }

      if(setup_function_value < 1){
          setup_function_value = 1;
      }
      memory.delay_left = setup_function_value;
      sprintf(buf, "%02d", memory.delay_left);
      lv_label_set_text(ui2_Label1, buf);
      dsp_i2c_set_delay(1,memory.delay_left);
      break;
    // Right channel delay
    case 1:
      if(setup_function_value > 500){
      setup_function_value = 500;
      }

      if(setup_function_value < 1){
          setup_function_value = 1;
      }
      memory.delay_right = setup_function_value;
      sprintf(buf, "%02d", memory.delay_right);
      lv_label_set_text(ui2_Label1, buf);
      dsp_i2c_set_delay(2,memory.delay_right);
      break;
    // Subwoofer delay
    case 2:
      if(setup_function_value > 500){
         setup_function_value = 500;
          }

      if(setup_function_value < 1){
             setup_function_value = 1;
      }
      memory.delay_sub = setup_function_value;
      sprintf(buf, "%02d", memory.delay_sub);
      lv_label_set_text(ui2_Label1, buf);
      dsp_i2c_set_delay(3,memory.delay_sub);
      break;
    // Subwoofer volume
    case 3:
      if(setup_function_value > 100){
      setup_function_value = 100;
      }

      if(setup_function_value < 0){
          setup_function_value = 0;
      }

      memory.subwoofer_volume = setup_function_value;
      if(memory.subwoofer_volume == 0){
        lv_label_set_text(ui2_Label1, "0");
      }
      else{
        sprintf(buf, "%02d", memory.subwoofer_volume*-1);
        lv_label_set_text(ui2_Label1, buf);
      }
      dsp_i2c_set_volume(memory.subwoofer_volume, SUB_VOL_REG, 0);
      break;
    // Invert subwoofer phase
    case 4:
      memory.invert_subwoofer = !memory.invert_subwoofer;
      if(memory.invert_subwoofer)
        lv_label_set_text(ui2_Label1, "-180°");
      else
        lv_label_set_text(ui2_Label1, "0°");
      dsp_i2c_set_subwoofer_phase(memory.invert_subwoofer);
      break;
    // Mirror EQ display
    case 5:
      memory.mirror_eq = !memory.mirror_eq;
      if(memory.mirror_eq)
        lv_label_set_text(ui2_Label1, "True");
      else
        lv_label_set_text(ui2_Label1, "False");
      break;
    
    default:
      break;
    }
  }
  
  else {
    //We get two increments per encoder click. Therefore we ignore half of the increments
    encoder_resulution += eb.increment();
    if(encoder_resulution % 2 == 0){
    memory.source_selected += eb.increment();
    }
    if (memory.source_selected > 2){
      memory.source_selected = 0;
    }
    else if(memory.source_selected < 0){
      memory.source_selected = 2;
    }
   display_set_source(memory.source_selected);
  }
}


void onEb2Clicked(EncoderButton& eb) {
  
}


/* Long Press on left Encoder button will power down the Amp */
void onEb2LongClick(EncoderButton& eb) {
  //shutdown amolifiers
  gpio_enable_amp(false);

  //save current settings in FRAM
  fram.writeBlock(0, (uint8_t *) &memory, sizeof(memory));
  delay(100);

  //Power down DSP and Blue Tooth
  gpio_enable_bt(false);
  gpio_enable_dsp(false);
  gpio_power_down(true);

  //Switch off displays
  gpio_disable_display();

  //Set LED to low red as standby indicator
  neopixel.fillPixelColor(5,0,0);
  neopixel.show();

  //RP2040 to enter sleep mode
  sleep_run_from_xosc();

  //we stay here until our wakeup signal was triggered
  sleep_goto_dormant_until_pin(ENC1_SW, false, false);

  //now continue by enabling RP2040 clock tree
  rosc_enable();
  clocks_init();

  //Finally reboot RP2040 to bring everything back to life
  rp2040.reboot();
}

/* A function to handle the 'right' encoder event */

void onEb2Encoder(EncoderButton& eb) {

  encoder_resulution += eb.increment();
  if(encoder_resulution % 2 == 0)
      memory.set_volume += eb.increment();
  else return;

  if(memory.set_volume > 100){
    memory.set_volume = 100;
  }

  if(memory.set_volume < 0){
    memory.set_volume = 0;
  }

  display_set_volume_graphics(memory.set_volume);
  dsp_i2c_set_volume(memory.set_volume, MAIN_VOL_REG, 1);
}

/* Interupt if 230V is removed to avoid popping noise from speakers */
void MainsPowerFailing(void) {
  gpio_enable_amp(false);
}

void setup(){
  gpio_default();
  attachInterrupt(V_SENS, MainsPowerFailing, FALLING);
  Serial.begin(115200);

#ifdef GFX_EXTRA_PRE_INIT
  GFX_EXTRA_PRE_INIT();
#endif

  // Init Display
  gfx->begin();
  gfx->fillScreen(RGB565_BLACK);

  gfx2->begin();
  gfx2->fillScreen(RGB565_BLACK);

#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif
  
  lv_init();

  screenWidth = gfx->width();
  screenHeight = gfx->height();

  disp_draw_buf = (lv_color_t *)malloc(sizeof(lv_color_t) * screenWidth * 32);
  disp_draw_buf2 = (lv_color_t *)malloc(sizeof(lv_color_t) * screenWidth * 32);

  if (!disp_draw_buf)
  {
    Serial.println("LVGL disp_draw_buf allocate failed!");
  }
  else if (!disp_draw_buf2)
  {
    Serial.println("LVGL disp_draw_buf2 allocate failed!");
  }
  else
  {
    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * 32);
    lv_disp_draw_buf_init(&draw_buf2, disp_draw_buf2, NULL, screenWidth * 32);

    /* Initialize the 1st display */
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_t * disp1 = lv_disp_drv_register(&disp_drv);

    /* Initialize the 1st (dummy) input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);


        /* Initialize the 2nd display */
    lv_disp_drv_init(&disp_drv2);
    disp_drv2.hor_res = screenWidth;
    disp_drv2.ver_res = screenHeight;
    disp_drv2.flush_cb = my_disp2_flush;
    disp_drv2.draw_buf = &draw_buf;
    lv_disp_t * disp2 =  lv_disp_drv_register(&disp_drv2);

    /* Initialize the 2nd (dummy) input device driver */
    static lv_indev_drv_t indev_drv2;
    lv_indev_drv_init(&indev_drv2);
    indev_drv2.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv2);

    /* Create Graphis */
    ui_init();
    lv_disp_set_default(disp2);
    ui2_init();
    
    /* Create encoder classes */
    eb1 = new EncoderButton(ENC2_B, ENC2_A, ENC2_SW);
    eb2 = new EncoderButton(ENC1_B, ENC1_A, ENC1_SW);

    eb1->setClickHandler(onEb1Clicked);
    eb1->setEncoderHandler(onEb1Encoder);
    eb1->useQuadPrecision(1);

    eb2->setClickHandler(onEb2Clicked);
    eb2->setEncoderHandler(onEb2Encoder);
    eb2->setLongClickHandler(onEb2LongClick);
    eb2->useQuadPrecision(1);

    gpio_enable_dsp(true);
    gpio_enable_bt(true);
    delay(2500);

    dsp_i2c_init();

    neopixel.begin();
    
    fram.begin();
    fram.readBlock(0, (uint8_t *) &memory, sizeof(memory));
    restore_settings();

    Serial.println("Setup done");

    gpio_enable_amp(true); 
  }
}


void loop(){
  
  if (memory.screen_selected==1){
   lv_bar_set_value(ui2_VolTopSlider, 100 + dsp_i2c_read_levelmeter(true), LV_ANIM_ON);
   lv_bar_set_value(ui2_VolBotSlider, 100 + dsp_i2c_read_levelmeter(false), LV_ANIM_ON);
  }  
  else if(memory.screen_selected==2){
   dsp_i2c_read_equilizer(true);
   lv_bar_set_value(ui2_EQSlider1, eqvalues[0], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider2, eqvalues[1], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider3, eqvalues[2], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider4, eqvalues[3], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider5, eqvalues[4], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider6, eqvalues[5], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider7, eqvalues[6], LV_ANIM_ON);
   dsp_i2c_read_equilizer(false);
   if(memory.mirror_eq){
    lv_bar_set_value(ui2_EQSlider8, eqvalues[6], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider9, eqvalues[5], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider10, eqvalues[4], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider11, eqvalues[3], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider12, eqvalues[2], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider13, eqvalues[1], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider14, eqvalues[0], LV_ANIM_ON);
   }
   else{
    lv_bar_set_value(ui2_EQSlider8, eqvalues[0], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider9, eqvalues[1], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider10, eqvalues[2], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider11, eqvalues[3], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider12, eqvalues[4], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider13, eqvalues[5], LV_ANIM_ON);
    lv_bar_set_value(ui2_EQSlider14, eqvalues[6], LV_ANIM_ON);
   }
  } 

  lv_timer_handler(); /* let the GUI do its work */
  delay(5);

  eb1->update();
  eb2->update();
}