#include "BME280Task.h"


readBME280Task::readBME280Task(){}

void readBME280Task::init(void)
{

}

void readBME280Task::startTask()
{
	for(;;)
	{
		processTask();
	}
}


void readBME280Task::processTask(void)
{

	xSemaphoreTake(semaBME280Task, portMAX_DELAY);
	readData();
	if (xQueueSend(QueueBMEToLora, &_BME_data, 100) == pdPASS)
	{

	}

	if(xQueueSend(QueueBMEToMicroSD, &_BME_data, 100) == pdPASS)
	{

	}

}

void readBME280Task::readData(void)
{
#pragma message ("chưa viết hàm đọc BME")
}





