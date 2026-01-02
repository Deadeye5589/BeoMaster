#include <lvgl.h>
#include <Arduino_GFX_Library.h>
#include <EncoderButton.h>

#include "ui.h"
#include "ui2.h"
#include "gpiohandler.h"
#include "pico_sleep.h"
#include "pico_rosc.h"
#include "dspcontrol.h"
#include "pico-ws2812/ws2812.h"

#define INPUT_PU

uint8_t source = 0;
uint8_t screenselected = 1;

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

volatile int8_t encsource = 0;
volatile int8_t volsource = 0;
volatile int8_t encoder_resulution = 0;

const uint NEOPIXELIO = LED; // Define your GPIO pin
const int NUMNEOPIXELS = 1; // Define number of neopixels

WS2812 neopixel = WS2812(NUMNEOPIXELS, NEOPIXELIO); // Create your instance of the library

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
  screenselected++;
  if(screenselected > 3)
    screenselected = 1;
  switch (screenselected)
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

/* A function to handle the 'left' encoder event */
void onEb1Encoder(EncoderButton& eb) {
  //We get two increments per encoder click. Therefore we ignore half of the increments
  encoder_resulution -= eb.increment();
  if(encoder_resulution % 2 == 0)
   encsource += eb.increment();

  if (encsource > 2){
    encsource = 0;
  }
  else if(encsource < 0){
    encsource = 2;
  }
  //Select USB inputs
  if(encsource == 2){
    digitalWrite(BT_RST, HIGH);
    dsp_i2c_select_source(true);
  } 
  //Select BT input
  else if(encsource==1){
    digitalWrite(BT_RST, LOW);
    dsp_i2c_select_source(true);
  }
  //Select Line input
  else{
    dsp_i2c_select_source(false);
  }          
  lv_roller_set_selected(ui_varRoller, encsource, LV_ANIM_ON);
}


void onEb2Clicked(EncoderButton& eb) {
  
}


/* Long Press on left Encoder button will power down the Amp */
void onEb2LongClick(EncoderButton& eb) {
  gpio_enable_amp(false);
  delay(100);
  gpio_enable_bt(false);
  gpio_enable_dsp(false);
  gpio_power_down(true);
  gpio_disable_display();

  sleep_run_from_xosc();
  //we stay here until our wakeup signal was triggered
  sleep_goto_dormant_until_pin(ENC1_SW, false, false);

  //now continue by powering everything up again
  rosc_enable();
  clocks_init();

  rp2040.reboot();
}

/* A function to handle the 'right' encoder event */
void onEb2Encoder(EncoderButton& eb) {

  encoder_resulution += eb.increment();
  if(encoder_resulution % 2 == 0)
      volsource += eb.increment();

  if(volsource > 100){
    volsource = 100;
  }
  if(volsource < 0){
    volsource = 0;
  }
  char buf[4];
  if(volsource == 100){
    sprintf(buf, "%02d", 0);
    lv_label_set_text(ui_varAmpLevel, buf);
    lv_obj_set_style_opa(ui_ImageMute, 255, 0);
  }
  else if (volsource==0){
    sprintf(buf, "%d", 0);
    lv_label_set_text(ui_varAmpLevel, buf);
  }
  else{
    lv_obj_set_style_opa(ui_ImageMute, 0, 0);
    sprintf(buf, "%02d", volsource*-1);
    lv_label_set_text(ui_varAmpLevel, buf);
  }
  lv_arc_set_value(ui_ArcLevel, 100-volsource);
  sprintf(buf, "%02d", volsource);
  lv_label_set_text(ui_varTemperatur,buf);

  dsp_i2c_set_volume(volsource);

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

    gpio_enable_amp(false); 

    dsp_i2c_init();

    neopixel.begin();
    

    Serial.println("Setup done");
  }
}


void loop(){
  
  if (screenselected==1){
   lv_bar_set_value(ui2_VolTopSlider, 100 + dsp_i2c_read_levelmeter(true), LV_ANIM_ON);
   lv_bar_set_value(ui2_VolBotSlider, 100 + dsp_i2c_read_levelmeter(false), LV_ANIM_ON);
  }  
  else if(screenselected==2){
   dsp_i2c_read_equilizer(true);
   lv_bar_set_value(ui2_EQSlider1, eqvalues[0], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider2, eqvalues[1], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider3, eqvalues[2], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider4, eqvalues[3], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider5, eqvalues[4], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider6, eqvalues[5], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider7, eqvalues[6], LV_ANIM_ON);
   dsp_i2c_read_equilizer(false);
   lv_bar_set_value(ui2_EQSlider8, eqvalues[6], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider9, eqvalues[5], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider10, eqvalues[4], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider11, eqvalues[3], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider12, eqvalues[2], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider13, eqvalues[1], LV_ANIM_ON);
   lv_bar_set_value(ui2_EQSlider14, eqvalues[0], LV_ANIM_ON);
  } 

  lv_timer_handler(); /* let the GUI do its work */
  delay(5);

  eb1->update();
  eb2->update();

  neopixel.fillPixelColor(0,0,127);
  neopixel.show();
}