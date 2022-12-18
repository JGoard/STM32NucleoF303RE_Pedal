/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/////////
//General #defines
/////////
#define INIT 0
#define FALSE 0
#define TRUE 1

/////////
//Menu State Machine
/////////
#define CLEAN 0
#define OVERDRIVE 1
#define DISTORTION 2 
#define FLANGER 3
#define DELAY 4


/////////
//Audio Signals into ADC or DAC
/////////
//NUMBER OF SAMPLE USER ACCESS PER DATA BLOCK
#define HTIM6_PERIOD 256
#define DATASIZE 128
//FULL DATABUFFFER SIZE
#define FULLBUFF 256
//Signal to ADC
#define SIG_IN_Pin GPIO_PIN_0 //A0
#define SIG_IN_GPIO_Port GPIOA
//Signal to DAC
#define SIG_OUT_Pin GPIO_PIN_4 //A2
#define SIG_OUT_GPIO_Port GPIOA
/////////
//Buttons 1-6
/////////
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC

#define B2_Pin GPIO_PIN_5
#define B2_GPIO_Port GPIOB

#define B2_Pin GPIO_PIN_5
#define B2_GPIO_Port GPIOB

#define B3_Pin GPIO_PIN_3
#define B3_GPIO_Port GPIOB

#define B4_Pin GPIO_PIN_10
#define B4_GPIO_Port GPIOA

#define B5_Pin GPIO_PIN_4
#define B5_GPIO_Port GPIOB

#define B6_Pin GPIO_PIN_7
#define B6_GPIO_Port GPIOC

#define B7_Pin GPIO_PIN_2
#define B7_GPIO_Port GPIOA
/////////
//Nokia 5110 LCD Pinout DEFINES on CN5 Header
/////////
#define LCD_CE_PIN     GPIO_PIN_9   //SCE CS - CHIP SELECT
#define LCD_DIN_PIN    GPIO_PIN_7   //D11 MOSI (DATA OUT TO LCD)
#define LCD_CLK_PIN    GPIO_PIN_5   //D13 SCLK (SPI CLK)
#define LCD_RST_PIN    GPIO_PIN_8   //D7 RST - ACTIVE LOW
#define LCD_DC_PIN     GPIO_PIN_6   //D12 D/C - MODE SELECT

#define LCD_PORT       GPIOA
//Rows for LCD Screen
#define FIRST_ROW       0
#define SECOND_ROW      1
#define THIRD_ROW       2
#define FOURTH_ROW      3
#define FIFTH_ROW       4
#define SIXTH_ROW       5
/////////
//State Machine Macros for DSP and Screen Changes
/////////
#define STATE_MAX 5
#define BUTTON_PRESSED  HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);

/////////
//DSP Macros for Initial Starting Effects
/////////
//Distortion/Overdrive Diode Signal Clipping
#define MAX_CLIP_LIMIT 2700
#define MIN_CLIP_LIMIT 1000
//Delay Constants
#define DELAY_INIT 48000



void menuStatemachine(void);

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
