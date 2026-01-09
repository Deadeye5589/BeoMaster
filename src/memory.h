#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdint.h>

// 7-Bit Adress of the FRAM Chip with A1 pin set to 1
#define FRAM_ADDR 0x52

struct savedata{
    uint8_t screen_selected;
    int8_t source_selected;
    int8_t set_volume;
    uint16_t delay_left;
    uint16_t delay_right;
    uint16_t delay_sub;
    uint8_t subwoofer_volume;
    int8_t select_setting;
    bool invert_subwoofer;
    bool mirror_eq;
};

extern struct savedata memory;

void restore_settings(void);
void restore_last_display_view(void);
void restore_volume(void);
void restore_source(void);
void restore_delay(uint8_t channel);
void restore_subwoofer_level(void);
void restore_subwoofer_phase(void);


#endif