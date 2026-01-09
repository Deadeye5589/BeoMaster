#ifndef _DISPLAYHELPER_H
#define _DISPLAYHELPER_H

#include<stdint.h>
#include "pico-ws2812/ws2812.h"
#include "gpiohandler.h"

extern WS2812 neopixel; // Create your instance of the library

void display_set_volume_graphics(int8_t level);
void display_load_right_screen(uint8_t screen);
void display_set_source(int8_t source);

#endif