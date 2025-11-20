#include "myMain.h"

#include "IMUTask.h"
#include "BME280Task.h"
#include "GPSTask.h"
#include "LoraComunicationTask.h"
#include "PM25Task.h"
#include "MicroSDTask.h"

readRawDataIMUTask *IMUTask;
readBME280Task *BMETask;
GPSDataAnalysisTask *GPSTask;
LoraComunicationTask * LoraTask;
logDataTask *MicroSDTask;
readPM25Task *PM25Task;


/* INTINAL DEFINE TICK RATE SEMAPHOR BEGIN */
constexpr uint16_t IMU_TASK_TIMER_COUNTER_MAX = 5;

constexpr uint16_t BME_TASK_TIMER_COUNTER_MAX = 200;
constexpr uint16_t GPS_TASK_TIMER_COUNTER_MAX = 200;

constexpr uint16_t LORA_TASK_TIMER_COUNTER_MAX = 1000;
constexpr uint16_t PM25_TASK_TIMER_COUNTER_MAX = 1000;
constexpr uint16_t MICR_TASK_TIMER_COUNTER_MAX = 1000;



constexpr uint16_t IMU_TASK_TIMER_MOD = 1;

constexpr uint16_t BME_TASK_TIMER_MOD = 10;
constexpr uint16_t GPS_TASK_TIMER_MOD = 20;

constexpr uint16_t PM25_TASK_TIMER_MOD = 0;
constexpr uint16_t MICR_TASK_TIMER_MOD = 100;
constexpr uint16_t LORA_TASK_TIMER_MOD = 200;

constexpr uint16_t COUNTER_TIMER_MAX = 60200;


/* INTINAL DEFINE TICK RATE SEMAPHOR END */


/* DEFINE FUNCTION BEGIN CODE */
void startIMUTask(void*parameter);
void startBMETask(void*parameter);
void startGPSTask(void*parameter);
void startPM25Task(void*parameter);
void startMICRTask(void*parameter);
void startLoraTask(void*parameter);
/*DEFINE FUNCTION END CODE */


// counter
uint16_t counterSemaphore = 0;

void controlSemaphore()
{
	counterSemaphore++;
	// IMU
	if (counterSemaphore % IMU_TASK_TIMER_COUNTER_MAX == IMU_TASK_TIMER_MOD)
	{
		xSemaphoreGive(semaIMUTask);
	}

	// BME
	if(counterSemaphore % BME_TASK_TIMER_COUNTER_MAX == BME_TASK_TIMER_MOD)
	{
		xSemaphoreGive(semaBME280Task);
	}

	//GPS
	if(counterSemaphore % GPS_TASK_TIMER_COUNTER_MAX == GPS_TASK_TIMER_MOD)
	{
		xSemaphoreGive(semaGPSTask);
	}

	//PM25
	if(counterSemaphore % PM25_TASK_TIMER_COUNTER_MAX == PM25_TASK_TIMER_MOD)
	{
		xSemaphoreGive(semaPM25Task);
	}

	//MICRO SD
	if(counterSemaphore % MICR_TASK_TIMER_COUNTER_MAX == MICR_TASK_TIMER_MOD)
	{
		xSemaphoreGive(semaMicroSDTask);
	}

	//Lora
	if (counterSemaphore % LORA_TASK_TIMER_COUNTER_MAX == LORA_TASK_TIMER_MOD)
	{
		xSemaphoreGive(semaLoraComunicationTask);
	}

	// reset counter
	if (counterSemaphore == COUNTER_TIMER_MAX)
	{
		counterSemaphore = 0;
	}
}


void startAllTask()
{
	xTaskCreate(startIMUTask, "IMU-Task", 128, NULL, 1, NULL);
	xTaskCreate(startBMETask, "BME-Task", 128, NULL, 1, NULL);
	xTaskCreate(startGPSTask, "GPS-Task", 128, NULL, 1, NULL);
	xTaskCreate(startPM25Task, "PM25-Task", 128, NULL, 1, NULL);
	xTaskCreate(startMICRTask, "Micro-Task", 128, NULL, 1, NULL);
	xTaskCreate(startLoraTask, "Lora-Task", 128, NULL, 1, NULL);
}


/* FUNCTION START TASK CODE BEGIN */
void startIMUTask(void*parameter)
{
	IMUTask->startTask();
}
void startBMETask(void*parameter)
{
	BMETask->startTask();
}
void startGPSTask(void*parameter)
{
	GPSTask->startTask();
}
void startLoraTask(void*parameter)
{
	LoraTask->startTask();
}
void startPM25Task(void*parameter)
{
	PM25Task->startTask();
}
void startMICRTask(void*parameter)
{
	MicroSDTask->startTask();
}
/* FUNCTION START TASK CODE END */








