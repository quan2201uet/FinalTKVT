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
		vTaskDelay(20);
	}
}


void readRawDataIMUTask::processTask(void)
{

	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
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




