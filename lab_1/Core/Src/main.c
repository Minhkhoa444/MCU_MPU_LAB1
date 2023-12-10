/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdint.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define EX1
//#define EX2
//#define EX4
//#define EX5
//#define EX6
//#define EX10
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void display7SEG(int num) {
	if(num > 9) num = 9;
	uint16_t led_on_pins = GPIO_PIN_0, led_off_pins = GPIO_PIN_0;
	switch(num) {
	case 0:
		led_on_pins = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
		led_off_pins = GPIO_PIN_6;
		break;
	case 1:
		led_on_pins = GPIO_PIN_1 | GPIO_PIN_2;
		led_off_pins = GPIO_PIN_0 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
		break;
	case 2:
		led_on_pins = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_6;
		led_off_pins = GPIO_PIN_2 | GPIO_PIN_5;
		break;
	case 3:
		led_on_pins = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_6;
		led_off_pins = GPIO_PIN_4 | GPIO_PIN_5;
		break;
	case 4:
		led_on_pins = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_5 | GPIO_PIN_6;
		led_off_pins = GPIO_PIN_0 | GPIO_PIN_3 | GPIO_PIN_4;
		break;
	case 5:
		led_on_pins = GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_5 | GPIO_PIN_6;
		led_off_pins = GPIO_PIN_1 | GPIO_PIN_4;
		break;
	case 6:
		led_on_pins = GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
		led_off_pins = GPIO_PIN_1;
		break;
	case 7:
		led_on_pins = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2;
		led_off_pins = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
		break;
	case 8:
		led_on_pins = GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_1 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
		break;
	case 9:
		led_on_pins = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_5 | GPIO_PIN_6;
		led_off_pins = GPIO_PIN_4;
		break;
	default:
		led_on_pins = GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_1 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
	}
	HAL_GPIO_WritePin(GPIOB, led_on_pins, GPIO_PIN_RESET);
	if(num != 8) HAL_GPIO_WritePin(GPIOB, led_off_pins, GPIO_PIN_SET);
}

void clearAllClock(void) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 |
							GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |
							GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);
}

void setNumberOnClock(uint8_t num) {
	if(num > 11) num = 11;
	num += 4;	//	map LED0 to pin number 4
	HAL_GPIO_WritePin(GPIOA, (uint16_t)(1 << num), GPIO_PIN_RESET);	//	bitmasking
}

void clearNumberOnClock(uint8_t num) {
	if(num > 11) num = 11;
	num += 4;	//	map LED0 to pin number 4
	HAL_GPIO_WritePin(GPIOA, (uint16_t)(1 << num), GPIO_PIN_SET);	//	bitmasking
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
#if defined EX1 || defined EX2
  uint8_t led_red_state = GPIO_PIN_RESET;
  uint8_t led_yellow_state = GPIO_PIN_SET;
  uint8_t led_green_state = GPIO_PIN_SET;
  uint8_t counter = 0;
#elif defined EX4
  uint8_t counter = 0;
#elif defined EX5
  uint8_t counter = 5, state = 0;
#define GREEN_W GPIO_PIN_4
#define RED_N GPIO_PIN_5
#define YELLOW_N GPIO_PIN_6
#define GREEN_N GPIO_PIN_7
#define RED_E GPIO_PIN_8
#define YELLOW_E GPIO_PIN_9
#define GREEN_E GPIO_PIN_10
#define RED_S GPIO_PIN_11
#define YELLOW_S GPIO_PIN_12
#define GREEN_S GPIO_PIN_13
#define RED_W GPIO_PIN_14
#define YELLOW_W GPIO_PIN_15
#elif defined EX6
  uint16_t led_pin = 4;
#elif defined EX10
  uint8_t hour = 0, minute = 0, second = 0;
#endif
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	#if defined EX1
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, led_red_state);		//	PA5
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, led_yellow_state);	//	PA6
	  counter = (counter+1) % 2;
	  if(counter == 0) {  //  change LEDs state every 2s
		  led_red_state = ~led_red_state;
		  led_yellow_state = ~led_yellow_state;
	  }
	#elif defined EX2
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, led_red_state);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, led_yellow_state);
	  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, led_green_state);
	  counter += 1;
	  if(!led_red_state && counter >= 5) {	//	red led is still on
		  led_red_state = GPIO_PIN_SET;
		  led_yellow_state = GPIO_PIN_RESET;
		  counter = 0;
	  }
	  if(!led_yellow_state && counter >= 2) {	//	yellow led is still on
		  led_yellow_state = GPIO_PIN_SET;
		  led_green_state = GPIO_PIN_RESET;
		  counter = 0;
	  }
	  if(!led_green_state && counter >= 3) {	//	green led is still on
		  led_green_state = GPIO_PIN_SET;
		  led_red_state = GPIO_PIN_RESET;
		  counter = 0;
	  }
	#elif defined EX4
	  if(counter >= 10) counter = 0;
	  display7SEG(counter++);
	#elif defined EX5
	  if(state == 0) {
		  if(counter == 5) {
		  	  HAL_GPIO_WritePin(GPIOA, RED_N | RED_S, GPIO_PIN_RESET);
	  	  	  HAL_GPIO_WritePin(GPIOA, GREEN_W | GREEN_E, GPIO_PIN_RESET);
	  	  	  HAL_GPIO_WritePin(GPIOA, YELLOW_N | GREEN_N | RED_E |
	  	  			  	  	  	  	  YELLOW_E | YELLOW_S |
									  RED_W | YELLOW_W | GREEN_S, GPIO_PIN_SET);
	  	  }
	  	  if(counter == 2) {
		  	  HAL_GPIO_WritePin(GPIOA, YELLOW_E | YELLOW_W, GPIO_PIN_RESET);
		  	  HAL_GPIO_WritePin(GPIOA, GREEN_W | GREEN_E, GPIO_PIN_SET);
	  	  }
	  	  if(counter == 0) {
		  	  HAL_GPIO_WritePin(GPIOA, RED_E | RED_W, GPIO_PIN_RESET);
		  	  HAL_GPIO_WritePin(GPIOA, GREEN_N | GREEN_S, GPIO_PIN_RESET);
		  	  HAL_GPIO_WritePin(GPIOA, YELLOW_E | YELLOW_W, GPIO_PIN_SET);
		  	  HAL_GPIO_WritePin(GPIOA, RED_N | RED_S, GPIO_PIN_SET);
		  	  counter = 5;
		  	  state = 1;
	  	  }
	  	  display7SEG(counter);
	  	  counter -= 1;
	  }
	  else if(state == 1) {
		  if(counter == 5) {
			  HAL_GPIO_WritePin(GPIOA, RED_E | RED_W, GPIO_PIN_RESET);
		  	  HAL_GPIO_WritePin(GPIOA, GREEN_N | GREEN_S, GPIO_PIN_RESET);
		  	  HAL_GPIO_WritePin(GPIOA, RED_N | YELLOW_N | YELLOW_E |
		  			  	  	  	  	  GREEN_E | RED_S | YELLOW_S |
									  YELLOW_W | GREEN_W, GPIO_PIN_SET);
		  	  }
		  	  if(counter == 2) {
		  		  HAL_GPIO_WritePin(GPIOA, YELLOW_N | YELLOW_S, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOA, GREEN_N | GREEN_S, GPIO_PIN_SET);
		  	  }
		  	  if(counter == 0) {
		  		  HAL_GPIO_WritePin(GPIOA, RED_N | RED_S, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOA, GREEN_W | GREEN_E, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOA, YELLOW_N | YELLOW_S, GPIO_PIN_SET);
		  		  HAL_GPIO_WritePin(GPIOA, RED_E | RED_W, GPIO_PIN_SET);
		  		  counter = 5;
		  		  state = 0;
		  	  }
		  	  display7SEG(counter);
		  	  counter -= 1;
	  }
	#elif defined EX6
	  HAL_GPIO_TogglePin(GPIOA, (uint16_t)(1 << led_pin));
	  led_pin += 1;
	  if(led_pin > 15) led_pin = 4;
	#elif defined EX10
	  clearAllClock();
	  setNumberOnClock(hour);
	  setNumberOnClock(minute / 5);
	  setNumberOnClock(second / 5);
	  second = (second + 1) % 60;
	  minute = (minute + second / 59) % 60;
	  hour = (hour + minute / 59) % 12;
	#endif
	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RED_LED_Pin|YELLOW_LED_Pin|GREEN_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RED_LED_Pin YELLOW_LED_Pin GREEN_LED_Pin */
  GPIO_InitStruct.Pin = RED_LED_Pin|YELLOW_LED_Pin|GREEN_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
