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
		vTaskDelay(200);
	}
}


void readBME280Task::processTask(void)
{

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





