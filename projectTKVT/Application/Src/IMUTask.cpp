#include "IMUTask.h"

readRawDataIMUTask::readRawDataIMUTask(){}


void readRawDataIMUTask :: init(void)
{

}

void readRawDataIMUTask::startTask ()
{
	for(;;)
	{
		processTask();
	}
}


void readRawDataIMUTask::processTask(void)
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

void readRawDataIMUTask::readData(void)
{
#pragma message ("chua viet ham doc IMU")
}




