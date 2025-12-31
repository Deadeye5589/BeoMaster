// Functions to control ADAU1701 DSP via I2C
#include "gpiohandler.h"
#include <Arduino.h>
#include <Wire.h>

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

static uint8_t LEFT_EQ_LO_REG[7]={
  0xBA,
  0x62,
  0x0A,
  0xB2,
  0x5A,
  0x02,
  0xAA
};

static uint8_t LEFT_EQ_HI_REG[7]={
  0x02,
  0x03,
  0x04,
  0x04,
  0x05,
  0x06,
  0x06
};

static uint8_t RIGHT_EQ_LO_REG[7]={
  0x5E,
  0x06,
  0xAE,
  0x56,
  0xFE,
  0xA6,
  0x4E
};

static uint8_t RIGHT_EQ_HI_REG[7]={
  0x07,
  0x08,
  0x08,
  0x09,
  0x09,
  0x0A,
  0x0B
};


// Values for Audio Gain from 0 to -100 dB as logarithmic progression
static uint8_t dsp_volume[101][4]={
  {0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x23},
  {0x00, 0x00, 0x00, 0x5E},
  {0x00, 0x00, 0x00, 0x95},
  {0x00, 0x00, 0x00, 0xA7},
  {0x00, 0x00, 0x00, 0xEC},
  {0x00, 0x00, 0x01, 0x2A},
  {0x00, 0x00, 0x01, 0xA4},
  {0x00, 0x00, 0x01, 0xD8},
  {0x00, 0x00, 0x02, 0x52},
  {0x00, 0x00, 0x03, 0xAD},
  {0x00, 0x00, 0x04, 0xA1},
  {0x00, 0x00, 0x05, 0x32},
  {0x00, 0x00, 0x05, 0xD4},
  {0x00, 0x00, 0x06, 0x8A},
  {0x00, 0x00, 0x07, 0x56},
  {0x00, 0x00, 0x08, 0x3B},
  {0x00, 0x00, 0x09, 0x3C},
  {0x00, 0x00, 0x08, 0x3B},
  {0x00, 0x00, 0x09, 0x3C},
  {0x00, 0x00, 0x08, 0x3B},
  {0x00, 0x00, 0x0A, 0x5D},
  {0x00, 0x00, 0x0B, 0xA0},
  {0x00, 0x00, 0x0D, 0x0C},
  {0x00, 0x00, 0x0E, 0xA3},
  {0x00, 0x00, 0x10, 0x6C},
  {0x00, 0x00, 0x12, 0x6D},
  {0x00, 0x00, 0x14, 0xAD},
  {0x00, 0x00, 0x17, 0x33},
  {0x00, 0x00, 0x1A, 0x07},
  {0x00, 0x00, 0x1D, 0x34},
  {0x00, 0x00, 0x20, 0xC5},
  {0x00, 0x00, 0x24, 0xC4},
  {0x00, 0x00, 0x29, 0x41},
  {0x00, 0x00, 0x2E, 0x49},
  {0x00, 0x00, 0x33, 0xEF},
  {0x00, 0x00, 0x3A, 0x45},
  {0x00, 0x00, 0x41, 0x61},
  {0x00, 0x00, 0x49, 0x5C},
  {0x00, 0x00, 0x52, 0x4F},
  {0x00, 0x00, 0x5C, 0x5A},
  {0x00, 0x00, 0x67, 0x9F},
  {0x00, 0x00, 0x74, 0x44},
  {0x00, 0x00, 0x82, 0x74},
  {0x00, 0x00, 0x92, 0x5F},
  {0x00, 0x00, 0xA4, 0x3B},
  {0x00, 0x00, 0xB8, 0x45},
  {0x00, 0x00, 0xCE, 0xC1},
  {0x00, 0x00, 0xE7, 0xFB},
  {0x00, 0x00, 0xCE, 0xC1},
  {0x00, 0x00, 0xE7, 0xFB},
  {0x00, 0x00, 0xCE, 0xC1},
  {0x00, 0x00, 0xE7, 0xFB},
  {0x00, 0x00, 0xCE, 0xC1},
  {0x00, 0x00, 0xE7, 0xFB},
  {0x00, 0x00, 0xCE, 0xC1},
  {0x00, 0x01, 0x04, 0x49},
  {0x00, 0x00, 0xE7, 0xFB},
  {0x00, 0x00, 0xCE, 0xC1},
  {0x00, 0x01, 0x24, 0x0C},
  {0x00, 0x01, 0x47, 0xAE},
  {0x00, 0x01, 0x6F, 0xAA},
  {0x00, 0x01, 0x9C, 0x86},
  {0x00, 0x01, 0xCE, 0xDC},
  {0x00, 0x02, 0x07, 0x56},
  {0x00, 0x02, 0x46, 0xB5},
  {0x00, 0x02, 0x8D, 0xCF},
  {0x00, 0x02, 0xDD, 0x96},
  {0x00, 0x03, 0x37, 0x18},
  {0x00, 0x03, 0x9B, 0x87},
  {0x00, 0x04, 0x0C, 0x37},
  {0x00, 0x04, 0x8A, 0xA7},
  {0x00, 0x05, 0x18, 0x84},
  {0x00, 0x05, 0xB7, 0xB1},
  {0x00, 0x06, 0x6A, 0x4A},
  {0x00, 0x07, 0x32, 0xAE},
  {0x00, 0x08, 0x13, 0x85},
  {0x00, 0x09, 0x0F, 0xCC},
  {0x00, 0x0A, 0x2A, 0xDB},
  {0x00, 0x0B, 0x68, 0x73},
  {0x00, 0x0C, 0xCC, 0xCD},
  {0x00, 0x0E, 0x5C, 0xA1},
  {0x00, 0x10, 0x1D, 0x3F},
  {0x00, 0x12, 0x14, 0x9A},
  {0x00, 0x14, 0x49, 0x61},
  {0x00, 0x16, 0xC3, 0x11},
  {0x00, 0x19, 0x8A, 0x13},
  {0x00, 0x1C, 0xA7, 0xD7},
  {0x00, 0x20, 0x26, 0xF3},
  {0x00, 0x24, 0x13, 0x47},
  {0x00, 0x28, 0x7A, 0x27},
  {0x00, 0x2D, 0x6A, 0x86},
  {0x00, 0x32, 0xF5, 0x2D},
  {0x00, 0x39, 0x2C, 0xEE},
  {0x00, 0x40, 0x26, 0xE7},
  {0x00, 0x47, 0xFA, 0xCD},
  {0x00, 0x50, 0xC3, 0x36},
  {0x00, 0x5A, 0x9D, 0xF8},
  {0x00, 0x65, 0xAC, 0x8C},
  {0x00, 0x72, 0x14, 0x83},
  {0x00, 0x80, 0x00, 0x00}
};

int8_t eqvalues[7]={0, 0, 0, 0, 0, 0, 0};

// Inializes the I2C bus on pins PA14 and PA15 
void dsp_i2c_init(void){
    Wire1.setSDA(I2C_SDA);
    Wire1.setSCL(I2C_SCL);
    Wire1.setClock(384000);
    Wire1.begin();
}


// Write the volume registers of the DSP
// Input value is the current volume leve set via 
// the left encoder
void dsp_i2c_set_volume(int8_t level){

  //Sanity check so we won't run out of our look up table array
  if (level < 0 || level > 101)
    return;

  // create a tranmssion buffer for the IC2 sequence 
  // initalizes with full scale gain 
  // set register adress for left channel gain
  byte buffer[6]={0x00, MAIN_VOL_REG, 0x00, 0x80, 0x00, 0x00};
  // look up the desired volume
  buffer[2]=dsp_volume[100-level][0];
  buffer[3]=dsp_volume[100-level][1];
  buffer[4]=dsp_volume[100-level][2];
  buffer[5]=dsp_volume[100-level][3];
  // Base adress of the DSP = 0x34
  Wire1.beginTransmission(DSP_ADRESS);
  // transmitt buffer
  Wire1.write(buffer, 6);
  Wire1.endTransmission();

  // repeat same volume settings for rigth audio channel
  buffer[1]=MAIN_VOL_REG+0x01;
  Wire1.beginTransmission(DSP_ADRESS);
  Wire1.write(buffer, 6);
  Wire1.endTransmission();
}

void dsp_i2c_set_bass_volume(int8_t level){

}


void dsp_i2c_select_source(bool digital_in){
  byte buffer[6]={0x00, INPUT_MUX_REG, 0x00, 0x00, 0x00, 0x00};

  if(digital_in){
    buffer[5]=0x01;
  }
  
  // Base adress of the DSP = DSP_ADRESS)
  Wire1.beginTransmission(DSP_ADRESS);
  // transmitt buffer
  Wire1.write(buffer, 6);
  Wire1.endTransmission();

}


void dsp_i2c_set_delay(int8_t channel, int8_t delay){
  byte buffer[6]={0x00, 0x00, 0x00, 0x00, 0x00, 0x01};

  //Left channel delay
  if(channel==1){
    buffer[1]=DELAY1_REG;
  }
  //Right chanel delay
  else if(channel==2){
    buffer[1]=DELAY2_REG;
  }
  //Subwoofer delay
  else if(channel==3){
    buffer[1]=DELAY3_REG;
  }
  else
   return;

  // Base adress of the DSP = DSP_ADRESS)
  Wire1.beginTransmission(DSP_ADRESS);
  // transmitt buffer
  Wire1.write(buffer, 6);
  Wire1.endTransmission();

}

// Function to read otu the numeric level detectors implemented in the DSP flow
// Will return a dbFS value with full scale equal to 1
// Reads out left or right channel according to register settings from trap.dat file
int8_t dsp_i2c_read_levelmeter(bool left_notright){
  byte transmitbuffer[4]={0x08, 0x1A, 0x00, 0x00};    //I2C commands that will be send to the DSP
  byte readbuffer[3]={0x00, 0x00, 0x00};              //Readback from the Trap Register of the DSP
  uint32_t readout = 0;                               //Create a 0.28 integer fixed point value from the readbuffer
  float divreadout = 0;                               //Convert to 5.23 by dividing the fixed point with 2^23
  int8_t logreadout = 0;                              //Convert to logarithm 

  if(left_notright){
    transmitbuffer[2]=LEFT_VOL_REG1_HI;
    transmitbuffer[3]=LEFT_VOL_REG1_LO;
  }
  else{
    transmitbuffer[2]=RIGHT_VOL_REG1_HI;
    transmitbuffer[3]=RIGHT_VOL_REG1_LO;
  }

  Wire1.beginTransmission(DSP_ADRESS);
  // transmitt buffer
  Wire1.write(transmitbuffer, 4);
  Wire1.endTransmission();
  Wire1.beginTransmission(DSP_ADRESS);
  Wire1.write(transmitbuffer, 2);
  Wire1.endTransmission(false);
  //Wait 2 DSP cycles to have correct values
  delay(10);
  Wire1.requestFrom(DSP_ADRESS,3);
  //Read Gen1x trap value register
  readbuffer[0]=Wire1.read();
  readbuffer[1]=Wire1.read();
  readbuffer[2]= Wire1.read();
  Wire1.endTransmission();

  //Shift Gen1x values 4 bits to make room for low niblle wich adds up the 5.19 values to 5.23
  //This will increase the useable dB scale from -40 to -60 dB
  readout = readout | (readbuffer[0]<<20);
  readout = readout | (readbuffer[1]<<12);
  readout = readout | (readbuffer[2]<<4);

  //Now switch over to Gen1_x4 register from which we need the lower nibble of the highest byte
  if(left_notright){
    transmitbuffer[2]=LEFT_VOL_REG2_HI;
    transmitbuffer[3]=LEFT_VOL_REG2_LO;
  }
  else{
    transmitbuffer[2]=RIGHT_VOL_REG2_HI;
    transmitbuffer[3]=RIGHT_VOL_REG2_LO;
  }

  Wire1.beginTransmission(DSP_ADRESS);
  // transmitt transmitbuffer
  Wire1.write(transmitbuffer, 4);
  Wire1.endTransmission();
  Wire1.beginTransmission(DSP_ADRESS);
  Wire1.write(transmitbuffer, 2);
  Wire1.endTransmission(false);
  delay(10);
  Wire1.requestFrom(DSP_ADRESS,3);
  //reuse the readbuffer since we already copied the needed data in the previous readout
  readbuffer[0]=Wire1.read();
  readbuffer[1]=Wire1.read();
  readbuffer[2]= Wire1.read();
  Wire1.endTransmission();

  //Build the final  5.23 floating point number and convert to dBFS
  readout = readout | (readbuffer[0] & 0x0000000F); //Mask out high bits and only copy low nibble
  divreadout = readout / 8388608.0f;                //divide by 2^23 to archive 5.23 format
  if(divreadout <= 0){                              //Mute equals 0 in registers. Log of 0 is not valid
    return -100;                                    //Therefore set to -100 dB FS
  }
  else{
    logreadout = 10*log10(divreadout);              //calculate dBFS value  
    return logreadout;
  }
}

void dsp_i2c_read_equilizer(bool left_notright){
 byte transmitbuffer[4]={0x08, 0x1A, 0x00, 0x00};    //I2C commands that will be send to the DSP
 byte readbuffer[3]={0x00, 0x00, 0x00};

 for(int8_t i=0; i<6; i++){
   uint32_t readout = 0; 
   if(left_notright){
    transmitbuffer[2]=LEFT_EQ_HI_REG[i];
    transmitbuffer[3]=LEFT_EQ_LO_REG[i];
   }
   else{
    transmitbuffer[2]=RIGHT_EQ_HI_REG[i];
    transmitbuffer[3]=RIGHT_EQ_LO_REG[i];
   }

  Wire1.beginTransmission(DSP_ADRESS);
  // transmitt buffer
  Wire1.write(transmitbuffer, 4);
  Wire1.endTransmission();
  Wire1.beginTransmission(DSP_ADRESS);
  Wire1.write(transmitbuffer, 2);
  Wire1.endTransmission(false);
  //Wait 2 DSP cycles to have correct values
  delay(10);
  Wire1.requestFrom(DSP_ADRESS,3);
  //Read Gen1x trap value register
  readbuffer[0]=Wire1.read();
  readbuffer[1]=Wire1.read();
  readbuffer[2]= Wire1.read();
  Wire1.endTransmission();

  readout=(readbuffer[0]<<16||readbuffer[1]<<8||readbuffer[2]);
  eqvalues[i]=(readout / 524288)*100;
 }

return;
}