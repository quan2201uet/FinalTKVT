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

void startAllTask()
{
	initTask();

	IMUTask =  new readRawDataIMUTask();
	BMETask = new readBME280Task();
	GPSTask = new GPSDataAnalysisTask();
	LoraTask = new LoraComunicationTask();
	//MicroSDTask = new logDataTask();
	PM25Task = new readPM25Task();
}


// counter
uint16_t counterSemaphore = 0;

void controlSemaphore()
{
	counterSemaphore++;
	// IMU
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	if (counterSemaphore % IMU_TASK_TIMER_COUNTER_MAX == IMU_TASK_TIMER_MOD)
	{
		//xSemaphoreGiveFromISR(semaIMUTask, &xHigherPriorityTaskWoken);
		xSemaphoreGive(semaIMUTask);
	}

	// BME
	if(counterSemaphore % BME_TASK_TIMER_COUNTER_MAX == BME_TASK_TIMER_MOD)
	{
		xSemaphoreGiveFromISR(semaBME280Task, &xHigherPriorityTaskWoken);
	}

	//GPS
	if(counterSemaphore % GPS_TASK_TIMER_COUNTER_MAX == GPS_TASK_TIMER_MOD)
	{
		xSemaphoreGiveFromISR(semaGPSTask, &xHigherPriorityTaskWoken);
	}

	//PM25
	if(counterSemaphore % PM25_TASK_TIMER_COUNTER_MAX == PM25_TASK_TIMER_MOD)
	{
		xSemaphoreGiveFromISR(semaPM25Task, &xHigherPriorityTaskWoken);
	}

	//MICRO SD
	if(counterSemaphore % MICR_TASK_TIMER_COUNTER_MAX == MICR_TASK_TIMER_MOD)
	{
		xSemaphoreGiveFromISR(semaMicroSDTask, &xHigherPriorityTaskWoken);
	}

	//Lora
	if (counterSemaphore % LORA_TASK_TIMER_COUNTER_MAX == LORA_TASK_TIMER_MOD)
	{
		xSemaphoreGiveFromISR(semaLoraComunicationTask, &xHigherPriorityTaskWoken);
	}

	// reset counter
	if (counterSemaphore == COUNTER_TIMER_MAX)
	{
		counterSemaphore = 0;
	}
}



/* FUNCTION START TASK CODE BEGIN */
void startIMUTask()
{
	IMUTask->startTask();
}
void startBMETask()
{
	BMETask->startTask();
}
void startGPSTask()
{
	GPSTask->startTask();
}
void startLoraTask()
{
	LoraTask->startTask();
}
void startPM25Task()
{
	PM25Task->startTask();
}
void startMICRTask()
{
	MicroSDTask->startTask();
}
/* FUNCTION START TASK CODE END */








