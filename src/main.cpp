#include <lvgl.h>
#include "ui.h"
#include "ui2.h"
#include <Arduino_GFX_Library.h>
#include <EncoderButton.h>

#define INPUT_PU

uint8_t source = 0;
long myTimer = 0;
long myDirection= 0;

/*Define 1st Display Pins and Classes*/
//#define GFX_BL 0
//#define GFX_BL 8

Arduino_DataBus *bus = new Arduino_RPiPicoSPI(12 /* DC */, 13 /* CS */, 10 /* SCK */, 11 /* MOSI */, UINT8_MAX /* MISO */, spi1 /* spi */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 9 /* RST */, 3 /* rotation */, true /* IPS */, 170, 320, 35, 0, 35, 0);

Arduino_DataBus *bus2 = new Arduino_RPiPicoSPI(4 /* DC */, 5 /* CS */, 2 /* SCK */, 3 /* MOSI */, UINT8_MAX /* MISO */, spi0 /* spi */);
Arduino_GFX *gfx2 = new Arduino_ST7789(bus2, 1 /* RST */, 1 /* rotation */, true /* IPS */, 170, 320, 35, 0, 35, 0);

static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *disp_draw_buf;
static lv_disp_drv_t disp_drv;

static lv_disp_draw_buf_t draw_buf2;
static lv_color_t *disp_draw_buf2;
static lv_disp_drv_t disp_drv2;

EncoderButton *eb1; //(16, 17, 18);
EncoderButton *eb2; //(20, 21, 19);

volatile int8_t encsource = 0;
volatile int8_t volsource = 0;


/* Display flushing */
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


/* Display flushing */
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
  Serial.print("eb1 clickCount: ");
  Serial.println(eb.clickCount());
}

/**
 * A function to handle the 'encoder' event
 */
void onEb1Encoder(EncoderButton& eb) {
  encsource += eb.increment();
  if (encsource > 2){
    encsource = 0;
  }
  else if(encsource < 0){
    encsource = 2;
  }    
  lv_roller_set_selected(ui_varRoller, encsource, LV_ANIM_ON);
}


void onEb2Clicked(EncoderButton& eb) {
  Serial.print("eb2 clickCount: ");
  Serial.println(eb.clickCount());
}

/**
 * A function to handle the 'encoder' event
 */
void onEb2Encoder(EncoderButton& eb) {
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
}



void setup(){
  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  // while(!Serial);

#ifdef GFX_EXTRA_PRE_INIT
  GFX_EXTRA_PRE_INIT();
#endif

  // Init Display
  gfx->begin();
  gfx->fillScreen(BLACK);

  gfx2->begin();
  gfx2->fillScreen(BLACK);

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

    /* Initialize the display */
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_t * disp1 = lv_disp_drv_register(&disp_drv);

    /* Initialize the (dummy) input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);


        /* Initialize the display */
    lv_disp_drv_init(&disp_drv2);
    disp_drv2.hor_res = screenWidth;
    disp_drv2.ver_res = screenHeight;
    disp_drv2.flush_cb = my_disp2_flush;
    disp_drv2.draw_buf = &draw_buf;
    lv_disp_t * disp2 =  lv_disp_drv_register(&disp_drv2);

    /* Initialize the (dummy) input device driver */
    static lv_indev_drv_t indev_drv2;
    lv_indev_drv_init(&indev_drv2);
    indev_drv2.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv2);

      /* Create Graphis */
    ui_init();
    lv_disp_set_default(disp2);
    ui2_init();

    eb1 = new EncoderButton(16, 17, 18);
    eb2 = new EncoderButton(21, 20, 19);

    eb1->setClickHandler(onEb1Clicked);
    eb1->setEncoderHandler(onEb1Encoder);
    eb1->useQuadPrecision(1);

    eb2->setClickHandler(onEb2Clicked);
    eb2->setEncoderHandler(onEb2Encoder);
    eb2->useQuadPrecision(1);

    Serial.println("Setup done");
  }
}


void loop(){
  
  if(myTimer==100){
    myDirection = 0;
  }
  if(myTimer==0){
    myDirection = 1;
  }
  if(myDirection){
    myTimer++;
  }
  else myTimer--;

  lv_bar_set_value(ui2_Bar1, myTimer, LV_ANIM_ON);
  lv_bar_set_value(ui2_Bar2, 100-myTimer, LV_ANIM_ON);

  lv_timer_handler(); /* let the GUI do its work */
  delay(5);

  eb1->update();
  eb2->update();
}