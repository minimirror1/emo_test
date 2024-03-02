/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
/* input */
#define ALM1_Pin GPIO_PIN_3
#define ALM1_GPIO_Port GPIOC
#define ALM2_Pin GPIO_PIN_2
#define ALM2_GPIO_Port GPIOC
#define ALM3_Pin GPIO_PIN_1
#define ALM3_GPIO_Port GPIOC
#define ALM4_Pin GPIO_PIN_0
#define ALM4_GPIO_Port GPIOC
#define ALM5_Pin GPIO_PIN_13
#define ALM5_GPIO_Port GPIOB
#define ALM6_Pin GPIO_PIN_12
#define ALM6_GPIO_Port GPIOB

#define SV1_EXTI0_Pin GPIO_PIN_0
#define SV1_EXTI0_GPIO_Port GPIOA
#define SV1_EXTI0_EXTI_IRQn EXTI0_IRQn
#define SV2_EXTI3_Pin GPIO_PIN_3
#define SV2_EXTI3_GPIO_Port GPIOA
#define SV2_EXTI3_EXTI_IRQn EXTI3_IRQn
#define SV3_EXTI6_Pin GPIO_PIN_6
#define SV3_EXTI6_GPIO_Port GPIOA
#define SV3_EXTI6_EXTI_IRQn EXTI9_5_IRQn
#define SV4_EXTI5_Pin GPIO_PIN_5
#define SV4_EXTI5_GPIO_Port GPIOC
#define SV4_EXTI5_EXTI_IRQn EXTI9_5_IRQn
#define SV5_EXTI2_Pin GPIO_PIN_2
#define SV5_EXTI2_GPIO_Port GPIOB
#define SV5_EXTI2_EXTI_IRQn EXTI2_IRQn
#define SV6_EXTI9_Pin GPIO_PIN_9
#define SV6_EXTI9_GPIO_Port GPIOE
#define SV6_EXTI9_EXTI_IRQn EXTI9_5_IRQn

/*out put*/
#define BR1_SIG_Pin GPIO_PIN_5
#define BR1_SIG_GPIO_Port GPIOE
#define BR2_SIG_Pin GPIO_PIN_0
#define BR2_SIG_GPIO_Port GPIOE
#define BR3_SIG_Pin GPIO_PIN_6
#define BR3_SIG_GPIO_Port GPIOB
#define BR4_SIG_Pin GPIO_PIN_6
#define BR4_SIG_GPIO_Port GPIOD
#define BR5_SIG_Pin GPIO_PIN_2
#define BR5_SIG_GPIO_Port GPIOD
#define BR6_SIG_Pin GPIO_PIN_11
#define BR6_SIG_GPIO_Port GPIOC


#define SV1_SIG_Pin GPIO_PIN_6
#define SV1_SIG_GPIO_Port GPIOE
#define SV2_SIG_Pin GPIO_PIN_1
#define SV2_SIG_GPIO_Port GPIOE
#define SV3_SIG_Pin GPIO_PIN_7
#define SV3_SIG_GPIO_Port GPIOB
#define SV4_SIG_Pin GPIO_PIN_7
#define SV4_SIG_GPIO_Port GPIOD
#define SV5_SIG_Pin GPIO_PIN_3
#define SV5_SIG_GPIO_Port GPIOD
#define SV6_SIG_Pin GPIO_PIN_12
#define SV6_SIG_GPIO_Port GPIOC


/*ServoOn LED*/
#define SV1_LD_G_Pin GPIO_PIN_1
#define SV1_LD_G_GPIO_Port GPIOA
#define SV1_LD_R_Pin GPIO_PIN_2
#define SV1_LD_R_GPIO_Port GPIOA
#define SV2_LD_G_Pin GPIO_PIN_4
#define SV2_LD_G_GPIO_Port GPIOA
#define SV2_LD_R_Pin GPIO_PIN_5
#define SV2_LD_R_GPIO_Port GPIOA
#define SV3_LD_G_Pin GPIO_PIN_7
#define SV3_LD_G_GPIO_Port GPIOA
#define SV3_LD_R_Pin GPIO_PIN_4
#define SV3_LD_R_GPIO_Port GPIOC
#define SV4_LD_G_Pin GPIO_PIN_0
#define SV4_LD_G_GPIO_Port GPIOB
#define SV4_LD_R_Pin GPIO_PIN_1
#define SV4_LD_R_GPIO_Port GPIOB
#define SV5_LD_G_Pin GPIO_PIN_7
#define SV5_LD_G_GPIO_Port GPIOE
#define SV5_LD_R_Pin GPIO_PIN_8
#define SV5_LD_R_GPIO_Port GPIOE
#define SV6_LD_G_Pin GPIO_PIN_10
#define SV6_LD_G_GPIO_Port GPIOE
#define SV6_LD_R_Pin GPIO_PIN_11
#define SV6_LD_R_GPIO_Port GPIOE

/*Brake LED*/
#define BR1_LD_Pin GPIO_PIN_14
#define BR1_LD_GPIO_Port GPIOB
#define BR2_LD_Pin GPIO_PIN_15
#define BR2_LD_GPIO_Port GPIOB
#define BR3_LD_Pin GPIO_PIN_8
#define BR3_LD_GPIO_Port GPIOD
#define BR4_LD_Pin GPIO_PIN_9
#define BR4_LD_GPIO_Port GPIOD
#define BR5_LD_Pin GPIO_PIN_8
#define BR5_LD_GPIO_Port GPIOC
#define BR6_LD_Pin GPIO_PIN_9
#define BR6_LD_GPIO_Port GPIOC

/*Status LED*/
#define STATE1_LD_G_Pin GPIO_PIN_3
#define STATE1_LD_G_GPIO_Port GPIOE
#define STATE1_LD_R_Pin GPIO_PIN_4
#define STATE1_LD_R_GPIO_Port GPIOE
#define STATE2_LD_G_Pin GPIO_PIN_8
#define STATE2_LD_G_GPIO_Port GPIOB
#define STATE2_LD_R_Pin GPIO_PIN_9
#define STATE2_LD_R_GPIO_Port GPIOB
#define STATE3_LD_G_Pin GPIO_PIN_4
#define STATE3_LD_G_GPIO_Port GPIOB
#define STATE3_LD_R_Pin GPIO_PIN_5
#define STATE3_LD_R_GPIO_Port GPIOB
#define STATE4_LD_G_Pin GPIO_PIN_4
#define STATE4_LD_G_GPIO_Port GPIOD
#define STATE4_LD_R_Pin GPIO_PIN_5
#define STATE4_LD_R_GPIO_Port GPIOD
#define STATE5_LD_G_Pin GPIO_PIN_0
#define STATE5_LD_G_GPIO_Port GPIOD
#define STATE5_LD_R_Pin GPIO_PIN_1
#define STATE5_LD_R_GPIO_Port GPIOD
#define STATE6_LD_G_Pin GPIO_PIN_15
#define STATE6_LD_G_GPIO_Port GPIOA
#define STATE6_LD_R_Pin GPIO_PIN_10
#define STATE6_LD_R_GPIO_Port GPIOC


/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
