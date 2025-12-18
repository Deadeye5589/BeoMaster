#ifndef _DSPCONTROL_H
#define _DSPCONTROL_H

#include <stdint.h>

void dsp_i2c_init(void);
void dsp_i2c_set_volume(int8_t level);

#endif