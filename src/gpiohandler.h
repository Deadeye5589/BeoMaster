// Pin Cofiguration of the RP2040
// Defines Pin Names as given by schematic drawing
// Project name: AmpDisplay


#ifndef _GPIOHANDLER_H
#define _GPIOHANDLER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>


const int DISP_BL = 0;
const int DISP_RST2 = 1;
const int DISP_CLK2 = 2;
const int DISP_DIN2 = 3;
const int DISP_DC2 = 4;
const int DISP_CS2 = 5;
const int BT_RST = 6;
const int BT_MFB = 7;
const int DSP_RESET = 8;
const int DISP_RST1 = 9;
const int DISP_CLK1 = 10;
const int DISP_DIN1 = 11;
const int DISP_DC1 = 12;
const int DISP_CS1 = 13;
const int I2C_SDA = 14;
const int I2C_SCL = 15;
const int ENC1_A = 16;
const int ENC1_B = 17;
const int ENC1_SW = 18;
const int V_SENS = 19;
const int ENC2_A = 20;
const int ENC2_B = 21;
const int ENC2_SW = 22;
const int SSR1 = 23;
const int SSR2 = 24;
const int LED = 25;
const int AMP_TEMP = 26;
const int AMP_OC = 27;
const int AMP_MUTE = 28;
const int PWR_EN = 29;


void gpio_default(void);
void gpio_enable_bt(bool onoff);
void gpio_enable_dsp(bool onoff);
void gpio_enable_amp(bool onoff);
void gpio_power_down(bool onoff);
void gpio_disable_display(void);




#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif