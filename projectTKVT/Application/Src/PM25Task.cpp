#include "PM25Task.h"

readPM25Task::readPM25Task(){}

void readPM25Task::init (void)
{

}

void readPM25Task::startTask()
{
	for(;;)
	{
		processTask();
		vTaskDelay(1000);
	}
}

void readPM25Task::processTask(void)
{

	if (xQueueSend(QueuePM25ToMicroSD, &pm, 100) == pdPASS)
	{

	}

	if (xQueueSend(QueuePM25ToLora, &pm, 100) == pdPASS)
	{

	}
}

void readPM25Task::readData(void)
{
#pragma message ("Chưa viết hàm đọc Pm25")
}
