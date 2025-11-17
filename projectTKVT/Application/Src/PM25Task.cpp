#include "PM25Task.h"

readPM25Task::readPM25Task
	(QueueHandle_t QueuePM25ToMicroSD, QueueHandle_t QueuePM25ToLora)
	: _QueuePM25ToMicroSD(QueuePM25ToMicroSD), _QueuePM25ToLora(QueuePM25ToLora){}

void readPM25Task::initTask (void)
{
	xTaskCreate(readPM25Task::startTask, "Task_PM25", 128, this, 1, NULL);
}

void readPM25Task::startTask(void* pvParameters)
{
	readPM25Task *self = static_cast<readPM25Task*> (pvParameters);
	self->readPM25Task::sendData();
}

void readPM25Task::readData(void)
{

}

void readPM25Task::sendData(void)
{
	for(;;)
	{
		xSemaphoreTake(semaPM25Task, portMAX_DELAY);

		if (xQueueSend(_QueuePM25ToMicroSD, &pm, 100) == pdPASS)
		{

		}

		if (xQueueSend(_QueuePM25ToLora, &pm, 100) == pdPASS)
		{

		}
	}
}
