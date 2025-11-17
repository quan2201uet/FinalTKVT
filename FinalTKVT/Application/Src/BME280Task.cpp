#include "BME280Task.h"


readBME280Task::readBME280Task
	(QueueHandle_t QueueBMEToMicroSD, QueueHandle_t QueueBMEToLora)
	: _QueueBMEToMicroSD(QueueBMEToMicroSD), _QueueBMEToLora(QueueBMEToLora){}


void readBME280Task::sendData(void)
{
	for(;;)
	{
		xSemaphoreTake(semaBME280Task, portMAX_DELAY);
		readData();
		if (xQueueSend(_QueueBMEToLora, &_BME_data, 100) == pdPASS)
		{

		}

		if(xQueueSend(_QueueBMEToMicroSD, &_BME_data, 100) == pdPASS)
		{

		}
	}
}

void readBME280Task::readData(void)
{
	_BME_data.humi = 3.0;
}

void readBME280Task::initTask(void)
{
	xTaskCreate(readBME280Task::startTask, "Task_GPS", 128, this, 1, NULL);
}

void readBME280Task::startTask(void* pvParameters)
{
	readBME280Task *self = static_cast<readBME280Task*> (pvParameters);
	self->readBME280Task::sendData();
}

