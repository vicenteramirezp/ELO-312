/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern enum estado estado_boton;
extern int switches[2];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //TASK 0
	/*
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin)  ;
	HAL_Delay(2000);
	*/

	// TASK 1
	  /*
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin)  ;
	enum estado  {Prendido,Apagado}; //el boton esta en alto cuando no esta siendo apretado
	enum estado estado_boton= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
	if (estado_boton==Apagado){
		HAL_Delay(500);
	};
	*/
	//TASK 2
	  /*
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin)  ;
	if (estado_boton==Apagado){
			HAL_Delay(500);
		};
	*/
	//TASK 3
	  /*
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	int arreglo[3];
	arreglo[0]=200;
	arreglo[1]=1000;
	arreglo[2]=3000;
	int numero_arreglo=(int) estado_boton;
	HAL_Delay(arreglo[numero_arreglo]);
	*/
	// TASK 4
	 int arreglo_leds[8]={1,1,1,1,0,0,0,0};
	 HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, arreglo_leds[0]);
	 HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, arreglo_leds[1]);
	 HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, arreglo_leds[2]);
	 HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, arreglo_leds[3]);
	 HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, arreglo_leds[4]);
	 HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, arreglo_leds[5]);
	 HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, arreglo_leds[6]);
	 HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, arreglo_leds[7]);

	 while(estado_boton==Play){
		 	 if (switches[0]==0 && switches[1]==0){

		 		 arreglo_leds=arreglo_leds !& 1;
		 		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, arreglo_leds[0]);
		 			 HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, arreglo_leds[1]);
		 			 HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, arreglo_leds[2]);
		 			 HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, arreglo_leds[3]);
		 			 HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, arreglo_leds[4]);
		 			 HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, arreglo_leds[5]);
		 			 HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, arreglo_leds[6]);
		 			 HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, arreglo_leds[7]);
		 	 }
		 	if (switches[0]==0 && switches[1]==1){

		 		arreglo_leds=arreglo_leds>>1;
		 		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, arreglo_leds[0]);
		 			 HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, arreglo_leds[1]);
		 			 HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, arreglo_leds[2]);
		 			 HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, arreglo_leds[3]);
		 			 HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, arreglo_leds[4]);
		 			 HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, arreglo_leds[5]);
		 			 HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, arreglo_leds[6]);
		 			 HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, arreglo_leds[7]);
		 			 	 }
		 	if (switches[0]==1 && switches[1]==0){
		 		arreglo_leds=arreglo_leds<<1;
		 		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, arreglo_leds[0]);
		 			 HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, arreglo_leds[1]);
		 			 HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, arreglo_leds[2]);
		 			 HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, arreglo_leds[3]);
		 			 HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, arreglo_leds[4]);
		 			 HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, arreglo_leds[5]);
		 			 HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, arreglo_leds[6]);
		 			 HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, arreglo_leds[7]);
		 			 	 }


		 	 }
		 }

	  };

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
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
