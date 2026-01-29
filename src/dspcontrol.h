#ifndef _DSPCONTROL_H
#define _DSPCONTROL_H

#include <stdint.h>

#define DSP_ADRESS 0x34

#define MAIN_VOL_REG 0x01
#define SUB_VOL_REG 0x78
#define INPUT_MUX_REG 0x00

#define DELAY1_REG 0x54
#define DELAY2_REG 0x55
#define DELAY3_REG 0x56

#define LEFT_VOL_REG1_HI 0x01
#define LEFT_VOL_REG1_LO 0x8A
#define LEFT_VOL_REG2_HI 0x01
#define LEFT_VOL_REG2_LO 0xAE
#define LEFT_VOL_REG3_HI 0x01
#define LEFT_VOL_REG3_LO 0xB2

#define RIGHT_VOL_REG1_HI 0x01
#define RIGHT_VOL_REG1_LO 0xEA
#define RIGHT_VOL_REG2_HI 0x02
#define RIGHT_VOL_REG2_LO 0x0E
#define RIGHT_VOL_REG3_HI 0x02
#define RIGHT_VOL_REG3_LO 0x12

extern int8_t eqvalues[7];

void dsp_i2c_init(void);
void dsp_i2c_set_volume(int8_t level, int8_t dsp_write_reg);
void dsp_i2c_set_bass_volume(int16_t level);
void dsp_i2c_select_source(bool digital_in);
void dsp_i2c_set_delay(int8_t channel, int16_t delay);
void dsp_i2c_set_subwoofer_phase(bool inverted);
int8_t dsp_i2c_read_levelmeter(bool left_notright);
void dsp_i2c_read_equilizer(bool left_notright);

#endif