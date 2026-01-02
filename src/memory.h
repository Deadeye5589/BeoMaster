#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdint.h>

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

#endif