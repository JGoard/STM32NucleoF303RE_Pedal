/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    spi.c
  * @brief   This file provides code for the configuration
  *          of the SPI instances.
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
/* Includes ------------------------------------------------------------------*/
#include "spi.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

SPI_HandleTypeDef hspi1;

/* SPI1 init function */
void MX_SPI1_Init(void)
{
GPIO_InitTypeDef GPIO_InitDef;

	SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOAEN);
  RCC->AHBENR |= (1UL << 0U);

  // PA9 --> SPI1 CHIP SELECT 
  // PA7 --> SPI1 MOSI  
  // PA13 --> SPI1 SCLK 
  
  GPIO_InitDef.Pin = (LCD_DC_PIN | LCD_CE_PIN | LCD_RST_PIN | LCD_DIN_PIN | LCD_CLK_PIN);
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LCD_PORT, &GPIO_InitDef);

}

void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
{

  // GPIO_InitTypeDef GPIO_InitStruct = {0};
  // if(spiHandle->Instance==SPI1)
  // {
  // /* USER CODE BEGIN SPI1_MspInit 0 */

  // /* USER CODE END SPI1_MspInit 0 */
  //   /* SPI1 clock enable */
  //   __HAL_RCC_SPI1_CLK_ENABLE();

  //   __HAL_RCC_GPIOA_CLK_ENABLE();
  //   /**SPI1 GPIO Configuration
  //   PA5     ------> SPI1_SCK
  //   PA6     ------> SPI1_MISO
  //   PA7     ------> SPI1_MOSI
  //   PA15     ------> SPI1_NSS
  //   */
  //   GPIO_InitStruct.Pin = LCD_CE_PIN|LCD_CLK_PIN|LCD_DC_PIN|LCD_DIN_PIN|LCD_RST_PIN;
  //   GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  //   GPIO_InitStruct.Pull = GPIO_NOPULL;
  //   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  //   GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  //   HAL_GPIO_Init(LCD, &GPIO_InitStruct);

  /* USER CODE BEGIN SPI1_MspInit 1 */

  /* USER CODE END SPI1_MspInit 1 */
  //}
}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* spiHandle)
{

  if(spiHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspDeInit 0 */

  /* USER CODE END SPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();

    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI
    PA15     ------> SPI1_NSS
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_15);

  /* USER CODE BEGIN SPI1_MspDeInit 1 */

  /* USER CODE END SPI1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
