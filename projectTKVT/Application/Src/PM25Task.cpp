#include "PM25Task.h"

readPM25Task::readPM25Task(){}

void readPM25Task::init (void)
{

}

void readPM25Task::startTask()
{
	QueueSetMemberHandle_t activeMember;
	for(;;)
	{
		activeMember = xQueueSelectFromSet(PM25TaskQueueSet, 10);
		processTask(activeMember);
	}
}

void readPM25Task::processTask(QueueSetMemberHandle_t activeMember)
{
	if (activeMember == semaPM25Task)
	{
		xSemaphoreTake(semaPM25Task, 10);
		if (xQueueSend(QueuePM25ToMicroSD, &pm, 10) == pdPASS)
		{

		}

		if (xQueueSend(QueuePM25ToLora, &pm, 10) == pdPASS)
		{

		}
	}
}

void readPM25Task::readData(void)
{
#pragma message ("Chưa viết hàm đọc Pm25")
}
