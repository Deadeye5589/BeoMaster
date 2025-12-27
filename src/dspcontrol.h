#ifndef _DSPCONTROL_H
#define _DSPCONTROL_H

#include <stdint.h>

void dsp_i2c_init(void);
void dsp_i2c_set_volume(int8_t level);
void dsp_i2c_set_bass_volume(int8_t level);
void dsp_i2c_select_source(bool digital_in);
void dsp_i2c_set_delay(int8_t channel, int8_t delay);
int8_t dsp_i2c_read_levelmeter(bool left_notright);
int8_t dps_i2c_read_equilizer();

#endif