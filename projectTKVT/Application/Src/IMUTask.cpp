#include "IMUTask.h"

readRawDataIMUTask::readRawDataIMUTask
	(QueueHandle_t QueueIMUToMicroSD, QueueHandle_t QueueIMUToLora)
	:_QueueIMUToMicroSD(QueueIMUToMicroSD), _QueueIMUToLora(QueueBMEToLora){}


void readRawDataIMUTask :: initTask(void)
{
	xTaskCreate(readRawDataIMUTask::startTask, "task_imu", 128, this, 1, NULL);
}

void readRawDataIMUTask::startTask (void* pvParameters)
{
	readRawDataIMUTask *self = static_cast<readRawDataIMUTask*> (pvParameters);
	self->readRawDataIMUTask :: senData();
}


void readRawDataIMUTask::senData(void)
{
	for (;;)
	{
		xSemaphoreTake(semaIMUTask, portMAX_DELAY);

		readData();
		if(xQueueSend(QueueIMUToLora, &_IMU_data, 100) == pdPASS)
		{

		}

		if(xQueueSend(QueueIMUToMicroSD, &_IMU_data, 100) == pdPASS)
		{

		}
	}
}

void readRawDataIMUTask::readData(void)
{

}




