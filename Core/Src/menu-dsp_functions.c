//===========================================================================
// File Name : menu_functions.c 
// Description: Functions intended to allow changes to LCD screen and DSP configuration
//              for guitar pedal
// Author: Josh Goard 
// Date: September 2022 
// Compiler: Built with STM32 NucleoF401RE DevBoard & platformio 
//===========================================================================

#include "stm32f3xx_hal.h"
#include "nokia5110_LCD.h"
#include "main.h"



extern volatile uint8_t currentState;
volatile int lcdClrScreenFlag = INIT;
extern volatile int debounceTimerValue;

//Create ADC//DAC Buffer
extern volatile uint32_t adc_val[FULLBUFF];
extern volatile uint32_t dac_val[FULLBUFF];
volatile uint32_t sound_array[FULLBUFF];                                                                                                     
//Pointers to the half-buffer which should be processed
static volatile uint32_t *inbufPtr;
static volatile uint32_t *outbufPtr;
/*For future integration of pushbuttons to adjust effect parameters*/
//Overdrive/Diode Clipping
volatile uint16_t maxClipLimit = MAX_CLIP_LIMIT;
volatile uint16_t minClipLimit = MIN_CLIP_LIMIT;
//Delay
volatile uint16_t delayConstant = DELAY_INIT;


void menuStatemachine(){

    switch (currentState){ //State Machine that changes from UI of button press to cycle through menu
      case CLEAN:
      if (lcdClrScreenFlag){
        LCD_clrScr();
        LCD_print("Clean Sig.", 1, 0);
        lcdClrScreenFlag--; //Allows for Screen to not be constantly rewrote to if state transition
      }                     //Has not occured
      break;

     case OVERDRIVE:
     if(lcdClrScreenFlag){
        LCD_clrScr();
        LCD_print("Overdrive Ch.",0 , 0);
        lcdClrScreenFlag--; 
     }
      break;

     case DISTORTION:
     if(lcdClrScreenFlag){
        LCD_clrScr();
        LCD_print("Distortion Ch.", 5, 0);
        lcdClrScreenFlag--;
     }
     break;

     case FLANGER:
     if(lcdClrScreenFlag){
        LCD_clrScr();
        LCD_print("Flange Ch.", 5, 0);
        lcdClrScreenFlag--;
     }
      break;

      case DELAY:
     if(lcdClrScreenFlag){
        LCD_clrScr();
        LCD_print("Distortion Ch.", 5, 0);
        lcdClrScreenFlag--;
     }
     break;
    default:
        currentState=INIT;
      break;
    }

}

//PLaceholder for DSP Function Block
void processDSP(void){

  switch (currentState){
  case CLEAN:
    processClean();
    break;
  case OVERDRIVE:
    processDistortion();
    break;
  case DISTORTION:
    processDistortion();
    break;
  case FLANGER:
    processFlanger();
    break;
  case DELAY:
    processDelay();
    break;  
  default:
    break;
  }
}

void processClean(void){ //Function simply passes through signal without any data processing outside of r/w to DMA
  for (int i = INIT; i < DATASIZE; i++){
      outbufPtr[i] = inbufPtr[i]; 
      }
}
/*Will eventually integrate hard clipping settings to be utilized by buttons on the front face of the pedal
Settings in mind mainly include setting hard clipping high and low limits*/
void processDistortion(void){
  for (int i = INIT; i < DATASIZE; i++){ //Proof of concept for hard clipping distorition
      if (inbufPtr[i] > maxClipLimit){ //Top sinusoid clipping limit
          outbufPtr[i] = maxClipLimit;  
      }
      else if (inbufPtr[i] < minClipLimit)//Lower sinusoid clipping limit
          outbufPtr[i] = minClipLimit;
      else 
          outbufPtr[i] = inbufPtr[i]; //Pass signal through not above or below min/max

      }
  
}

void processFlanger(void){
  for (int i = INIT; i < DATASIZE; i++){
      outbufPtr[i] = inbufPtr[i]; 
      }
  
}

void processDelay(void){
  for (int i = INIT; i < DATASIZE; i++){
      outbufPtr[i] = inbufPtr[i]; 
      i = i % delayConstant;
      }
  
}

__weak void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){//Used for 
  //First half of the ADC Buffer is now full
  inbufPtr = &adc_val[INIT];
  outbufPtr = &dac_val[DATASIZE];
}

__weak void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
  inbufPtr = &adc_val[DATASIZE];
  outbufPtr = &dac_val[INIT];
}