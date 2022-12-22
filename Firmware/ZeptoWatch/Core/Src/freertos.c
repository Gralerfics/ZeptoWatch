/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "common.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "ui.h"

#include "retarget.h"
#include "pikaScript.h"
#include "brightness.h"
#include "fshelper.h"
#include "mpu6050.h"
#include "msm261s.h"
#include "power.h"
#include "vibrator.h"
#include "battery.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#include "ui_helpers_user.h"
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId systemUIHandle;
osThreadId systemDetectingHandle;
osThreadId applicationExecHandle;
osThreadId systemScanningHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartSystemUI(void const * argument);
void StartSystemDetecting(void const * argument);
void StartApplicationExecuting(void const * argument);
void startSystemScanning(void const * argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
	*ppxIdleTaskStackBuffer = &xIdleStack[0];
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
	/* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

	// USB Initialization
	MX_USB_DEVICE_Init();
	// Retarget printf
	RetargetInit(&huart6);
	// Power Key Initialization
	Power_SetState(0);
	Power_SetTIMHandle(&htim7);
	// Screen Brightness Initialization - Dark
	Brightness_Start(&htim3, TIM_CHANNEL_1);
	Brightness_SetValueDirect(0);
	// Lvgl Initialization
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	ui_init();
	UI_Applications_InitList();
	HAL_TIM_Base_Start_IT(&htim2);
	// EEPROM Initialization
	ROM_Init();
	// File System Initialization
	FS_Mount();
	// Halt Applications
	Applications_HaltApplication();
	// IMU Initialization
	MPU_Initialize();
	// Microphone Initialization
	Microphone_StartSampling();
	// Vibrator Initialization
	Vibrator_Initialize(&htim4, TIM_CHANNEL_1);
	// Battery Initialization
	Battery_Init();
	Battery_StartSampling();

	// Scan 任务 Heap 大小大一些好像很重要
	// P.S. 改了 .ld 文件 195 行 ._user_heap_stack 的指向，由 RAM 改为 CCMRAM，在此记录

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityRealtime, 0, 64);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of systemUI */
  osThreadDef(systemUI, StartSystemUI, osPriorityHigh, 0, 2000);
  systemUIHandle = osThreadCreate(osThread(systemUI), NULL);

  /* definition and creation of systemDetecting */
  osThreadDef(systemDetecting, StartSystemDetecting, osPriorityNormal, 0, 1000);
  systemDetectingHandle = osThreadCreate(osThread(systemDetecting), NULL);

  /* definition and creation of applicationExec */
  osThreadDef(applicationExec, StartApplicationExecuting, osPriorityNormal, 0, 3000);
  applicationExecHandle = osThreadCreate(osThread(applicationExec), NULL);

  /* definition and creation of systemScanning */
  osThreadDef(systemScanning, startSystemScanning, osPriorityBelowNormal, 0, 1500);
  systemScanningHandle = osThreadCreate(osThread(systemScanning), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN StartDefaultTask */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
	}
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartSystemUI */
/**
* @brief Function implementing the systemUI thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartSystemUI */
__weak void StartSystemUI(void const * argument)
{
  /* USER CODE BEGIN StartSystemUI */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
	}
  /* USER CODE END StartSystemUI */
}

/* USER CODE BEGIN Header_StartSystemDetecting */
/**
* @brief Function implementing the systemDetecting thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartSystemDetecting */
__weak void StartSystemDetecting(void const * argument)
{
  /* USER CODE BEGIN StartSystemDetecting */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
	}
  /* USER CODE END StartSystemDetecting */
}

/* USER CODE BEGIN Header_StartApplicationExecuting */
/**
* @brief Function implementing the applicationExec thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartApplicationExecuting */
__weak void StartApplicationExecuting(void const * argument)
{
  /* USER CODE BEGIN StartApplicationExecuting */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
	}
  /* USER CODE END StartApplicationExecuting */
}

/* USER CODE BEGIN Header_startSystemScanning */
/**
* @brief Function implementing the systemScanning thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startSystemScanning */
__weak void startSystemScanning(void const * argument)
{
  /* USER CODE BEGIN startSystemScanning */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
	}
  /* USER CODE END startSystemScanning */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
