/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f1xx_hal.h"

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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define SERVO1_Pin GPIO_PIN_0
#define SERVO1_GPIO_Port GPIOA
#define SERVO2_Pin GPIO_PIN_1
#define SERVO2_GPIO_Port GPIOA
#define SERVO3_Pin GPIO_PIN_2
#define SERVO3_GPIO_Port GPIOA
#define SERVO4_Pin GPIO_PIN_3
#define SERVO4_GPIO_Port GPIOA
#define MOTOR1_Pin GPIO_PIN_6
#define MOTOR1_GPIO_Port GPIOA
#define MOTOR2_Pin GPIO_PIN_7
#define MOTOR2_GPIO_Port GPIOA
#define MOTOR3_Pin GPIO_PIN_0
#define MOTOR3_GPIO_Port GPIOB
#define MOTOR4_Pin GPIO_PIN_1
#define MOTOR4_GPIO_Port GPIOB
#define M1A_Pin GPIO_PIN_2
#define M1A_GPIO_Port GPIOB
#define M1B_Pin GPIO_PIN_10
#define M1B_GPIO_Port GPIOB
#define M2A_Pin GPIO_PIN_11
#define M2A_GPIO_Port GPIOB
#define M2B_Pin GPIO_PIN_12
#define M2B_GPIO_Port GPIOB
#define M3A_Pin GPIO_PIN_13
#define M3A_GPIO_Port GPIOB
#define M3B_Pin GPIO_PIN_14
#define M3B_GPIO_Port GPIOB
#define M4A_Pin GPIO_PIN_15
#define M4A_GPIO_Port GPIOB
#define M4B_Pin GPIO_PIN_8
#define M4B_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
