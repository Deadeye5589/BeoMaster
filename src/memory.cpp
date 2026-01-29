#include "dspcontrol.h"
#include "memory.h"
#include "display_helpter_functions.h"

struct savedata memory = {
    memory.screen_selected = 1,
    memory.source_selected = 0,
    memory.set_volume = 0,
    memory.delay_left = 1,
    memory.delay_right = 1,
    memory.delay_sub = 1,
    memory.subwoofer_volume = 0,
    memory.select_setting = 6,
    memory.invert_subwoofer = 0,
    memory.mirror_eq = 0
};


void restore_settings(void){
 restore_volume();
 restore_source();
 restore_delay(1);
 restore_delay(2);
 restore_delay(3);
 restore_subwoofer_phase();
 restore_last_display_view();
}

void restore_last_display_view(void){
 display_load_right_screen(memory.screen_selected);
}


void restore_volume(void){
 display_set_volume_graphics(memory.set_volume);
 dsp_i2c_set_volume(memory.set_volume, MAIN_VOL_REG);
}

void restore_source(void){
 display_set_source(memory.source_selected);
}

void restore_delay(uint8_t channel){
 dsp_i2c_set_delay(1, memory.delay_left);
 dsp_i2c_set_delay(2, memory.delay_right);
 dsp_i2c_set_delay(3, memory.delay_sub);
}

void restore_subwoofer_level(void){
 dsp_i2c_set_volume(memory.set_volume, SUB_VOL_REG);
}

void restore_subwoofer_phase(void){

}