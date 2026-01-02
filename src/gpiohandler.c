// Pin Cofiguration of the RP2040
// Defines Pin Names as given by schematic drawing
// Project name: AmpDisplay

#include "gpiohandler.h"
#include <Arduino.h>

void gpio_default (){
     pinMode(DISP_BL, OUTPUT);
     digitalWrite(DISP_BL, HIGH);
    

    // pinMode(DISP_RST2, OUTPUT);
    // digitalWrite(DISP_RST2, LOW);

    pinMode(DISP_CLK2, OUTPUT);
    digitalWrite(DISP_CLK2, LOW);
    //gpio_set_slew_rate(DISP_CLK2, GPIO_SLEW_RATE_FAST);
    //gpio_set_drive_strength(DISP_CLK2,GPIO_DRIVE_STRENGTH_12MA);

    pinMode(DISP_DIN2, OUTPUT);
    digitalWrite(DISP_DIN2, LOW);
    //gpio_set_slew_rate(DISP_DIN2, GPIO_SLEW_RATE_FAST);
    //gpio_set_drive_strength(DISP_DIN2,GPIO_DRIVE_STRENGTH_12MA);

    // pinMode(DISP_DC2, OUTPUT);
    // digitalWrite(DISP_DC2, LOW);

    // pinMode(DISP_CS2, OUTPUT);
    // digitalWrite(DISP_CS2, LOW);

    pinMode(BT_RST, OUTPUT);
    digitalWrite(BT_RST, LOW);

    pinMode(BT_MFB, OUTPUT);
    digitalWrite(BT_MFB, HIGH);

    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);

    // pinMode(DISP_RST1, OUTPUT);
    // digitalWrite(DISP_RST1 , LOW);

    pinMode(DISP_CLK1, OUTPUT);
    digitalWrite(DISP_CLK1, LOW);
    //gpio_set_slew_rate(DISP_CLK1, GPIO_SLEW_RATE_FAST);
    //gpio_set_drive_strength(DISP_CLK1,GPIO_DRIVE_STRENGTH_12MA);

    pinMode(DISP_DIN1, OUTPUT);
    digitalWrite(DISP_DIN1, LOW);
    //gpio_set_slew_rate(DISP_DIN1, GPIO_SLEW_RATE_FAST);
    //gpio_set_drive_strength(DISP_DIN1,GPIO_DRIVE_STRENGTH_12MA);

    // pinMode(DISP_DC1, OUTPUT);
    // digitalWrite(DISP_DC1, LOW);

    // pinMode(DISP_CS1, OUTPUT);
    // digitalWrite(DISP_CS1, LOW);

    pinMode(I2C_SCL, INPUT);
    //digitalWrite(I2C_SCL, LOW);

    pinMode(I2C_SDA, INPUT);
    //digitalWrite(I2C_SDA, LOW);

    //pinMode(ENC1_A, INPUT);

    //pinMode(ENC1_B, INPUT);

    //pinMode(ENC1_SW, INPUT);

    pinMode(V_SENS, INPUT);

    //pinMode(ENC2_A, INPUT);

    //pinMode(ENC2_B, INPUT);

    //pinMode(ENC2_SW, INPUT);

    pinMode(SSR2, OUTPUT);
    digitalWrite(SSR2, LOW);

    pinMode(SSR1, OUTPUT);
    digitalWrite(SSR1, LOW);

    pinMode(AMP_MUTE, OUTPUT);
    digitalWrite(AMP_MUTE, HIGH);

    pinMode(AMP_TEMP, INPUT);

    pinMode(AMP_OC, INPUT);

    pinMode(DSP_RESET, OUTPUT);
    digitalWrite(DSP_RESET, LOW);

    pinMode(PWR_EN, OUTPUT);
    digitalWrite(PWR_EN, LOW);
}


void gpio_enable_bt(bool onoff){
    if(onoff){
        digitalWrite(BT_RST, LOW);
        digitalWrite(BT_MFB, LOW);
    }
    else{
        digitalWrite(BT_RST, HIGH);
        digitalWrite(BT_MFB, HIGH);
    }
}


void gpio_enable_dsp(bool onoff){
    if(onoff){
        digitalWrite(DSP_RESET, HIGH);
    }
    else{
        digitalWrite(DSP_RESET, LOW);
    }
}


void gpio_enable_amp(bool onoff){
    if(onoff){
        digitalWrite(AMP_MUTE, HIGH);
        delay(500);
        digitalWrite(SSR1, HIGH);
        digitalWrite(SSR2, HIGH);
        delay(5000);
        digitalWrite(AMP_MUTE, LOW);
    }
    else{
        digitalWrite(AMP_MUTE, HIGH);
        delay(500);
        digitalWrite(SSR1, LOW);
        digitalWrite(SSR2, LOW);
    }
}

void gpio_power_down(bool onoff){
    if(onoff){
        digitalWrite(PWR_EN, HIGH);
    }
    else{
        digitalWrite(PWR_EN, LOW);
    }
    
}

void gpio_disable_display(void){
    digitalWrite(DISP_BL, LOW);
    digitalWrite(DISP_RST1, LOW);
    digitalWrite(DISP_RST2, LOW);
}