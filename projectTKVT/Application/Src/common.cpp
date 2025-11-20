#include "common.h"

constexpr uint16_t IMU_TASK_TIMER_COUNTER_MAX = 5;

constexpr uint16_t BME_TASK_TIMER_COUNTER_MAX = 200;

constexpr uint16_t LORA_TASK_TIMER_COUNTER_MAX = 1000;
constexpr uint16_t PM25_TASK_TIMER_COUNTER_MAX = 1000;

/* USING SEMAPHORE BEGIN*/
SemaphoreHandle_t semaBME280Task;
SemaphoreHandle_t semaGPSTask;
SemaphoreHandle_t semaIMUTask;
SemaphoreHandle_t semaLoraComunicationTask;
SemaphoreHandle_t semaMicroSDTask;
SemaphoreHandle_t semaPM25Task;
/* USING SEMAPHORE END*/

/* USING QUEUE BEGIN*/
QueueHandle_t QueueGPSToMicroSD;
QueueHandle_t QueueGPSToLora;

QueueHandle_t QueueBMEToMicroSD;
QueueHandle_t QueueBMEToLora;

QueueHandle_t QueueIMUToMicroSD;
QueueHandle_t QueueIMUToLora;

QueueHandle_t QueuePM25ToMicroSD;
QueueHandle_t QueuePM25ToLora;
/* USING QUEUE END*/

/* USING FUNCTION BEGIN*/
void initTask()
{
	// init sema
	semaBME280Task = xSemaphoreCreateBinary();
	semaGPSTask = xSemaphoreCreateBinary();
	semaIMUTask = xSemaphoreCreateBinary();
	semaLoraComunicationTask = xSemaphoreCreateBinary();
	semaMicroSDTask = xSemaphoreCreateBinary();
	semaPM25Task = xSemaphoreCreateBinary();


	// init Queue
	QueueBMEToLora = xQueueCreate(10, sizeof(BME_data_t));
	QueueBMEToMicroSD = xQueueCreate(10, sizeof(BME_data_t));

	QueueGPSToLora = xQueueCreate(10, sizeof(GPS_data_t));
	QueueGPSToMicroSD = xQueueCreate(10, sizeof(GPS_data_t));

	QueueIMUToLora = xQueueCreate(10, sizeof(IMU_data_t));
	QueueIMUToMicroSD = xQueueCreate(10, sizeof(IMU_data_t));

	QueuePM25ToLora = xQueueCreate(10, sizeof(float));
	QueuePM25ToMicroSD = xQueueCreate(10, sizeof(float));
}



/* USING FUNCTION END*/

