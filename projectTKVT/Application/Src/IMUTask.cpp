#include "IMUTask.h"


readRawDataIMUTask::readRawDataIMUTask(){}


void readRawDataIMUTask :: init(void)
{
	uint8_t check;
	uint8_t mData;
	HAL_I2C_Mem_Read(&hi2c2,ADD, 0x75,1, &check,1,1000);
	if(check == 0x68){
		mData = 0x00;
		HAL_I2C_Mem_Write(&hi2c2, ADD,0x6B,1,&mData,1,1000);
		mData = 0x07;
		HAL_I2C_Mem_Write(&hi2c2, ADD,0x19,1,&mData,1,1000);
		mData = 0x00;
		HAL_I2C_Mem_Write(&hi2c2, ADD,0x1B,1,&mData,1,1000);
		mData = 0x00;
		HAL_I2C_Mem_Write(&hi2c2, ADD,0x1C,1,&mData,1,1000);
	}
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
	readDataA();
	readDataG();
	if(xQueueSend(QueueIMUToLora, &_IMU_data, 100) == pdPASS)
	{

	}

	if(xQueueSend(QueueIMUToMicroSD, &_IMU_data, 100) == pdPASS)
	{

	}

}

void readRawDataIMUTask::readDataG(void)
{
	uint8_t dataG[6];
	uint16_t data16[3];

	HAL_I2C_Mem_Read(&hi2c2,ADD, 0x43,1, dataG,6,1000);
	data16[0] = (int16_t)(dataG[0] << 8 | dataG[1]);
	data16[1] = (int16_t)(dataG[2] << 8 | dataG[3]);
	data16[2] = (int16_t)(dataG[4] << 8 | dataG[5]);
	_IMU_data.gx = (float)data16[0]/131.0;
	_IMU_data.gy = (float)data16[1]/131.0;
	_IMU_data.gz = (float)data16[2]/131.0;
}

void readRawDataIMUTask::readDataA()
{
	uint8_t dataA[6];
	uint16_t ax, ay, az;

	HAL_I2C_Mem_Read(&hi2c2,ADD, 0x3B,1, dataA,6,1000);
	ax = (int16_t)(dataA[0] << 8 | dataA[1]);
	ay = (int16_t)(dataA[2] << 8 | dataA[3]);
	az = (int16_t)(dataA[4] << 8 | dataA[5]);
	_IMU_data.ax = (float)ax/16384.0;
	_IMU_data.ay = (float)ay/16384.0;
	_IMU_data.az = (float)az/16384.0;
}



