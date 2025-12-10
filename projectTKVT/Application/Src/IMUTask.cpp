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
	QueueSetMemberHandle_t activeMember;
	for(;;)
	{
		activeMember = xQueueSelectFromSet(IMUTaskQueueSet, 10);
		processTask(activeMember);
	}
}


void readRawDataIMUTask::processTask(QueueSetMemberHandle_t activeMember)
{
	if(activeMember == semaIMUTask)
	{
		xSemaphoreTake(semaIMUTask,10);
		readData();
		if(xQueueSend(QueueIMUToLora, &_IMU_data, 10) == pdPASS)
		{

		}

		if(xQueueSend(QueueIMUToMicroSD, &_IMU_data, 10) == pdPASS)
		{

		}
	}
}

void readRawDataIMUTask::readData(void)
{
	MPU6050ReadA();
	MPU6050ReadG();
}


void readRawDataIMUTask::MPU6050ReadG()
{
	uint8_t dataG[6];
	uint16_t data16_G[3];
	HAL_I2C_Mem_Read(&hi2c2,ADD, 0x43,1, dataG,6,1000);
	data16_G[0] = (int16_t)(dataG[0] << 8 | dataG[1]);
	data16_G[1] = (int16_t)(dataG[2] << 8 | dataG[3]);
	data16_G[2] = (int16_t)(dataG[4] << 8 | dataG[5]);
	_IMU_data.gx = (float)data16_G[0]/131.0;
	_IMU_data.gy = (float)data16_G[1]/131.0;
	_IMU_data.gz = (float)data16_G[2]/131.0;
}

void readRawDataIMUTask::MPU6050ReadA()
{
	uint8_t dataA[6];
	uint16_t data16_A[3];
	HAL_I2C_Mem_Read(&hi2c2,ADD, 0x3B,1, dataA,6,1000);
	data16_A[0] = (int16_t)(dataA[0] << 8 | dataA[1]);
	data16_A[1] = (int16_t)(dataA[2] << 8 | dataA[3]);
	data16_A[2] = (int16_t)(dataA[4] << 8 | dataA[5]);
	_IMU_data.ax = (float)data16_A[0]/16384.0;
	_IMU_data.ay = (float)data16_A[1]/16384.0;
	_IMU_data.az = (float)data16_A[2]/16384.0;
}

void readRawDataIMUTask::filter()
{
	//	float pitchG = pitch + GX*(10000/1000000.0f);
	//	float rollG = roll + GY*(10000/1000000.0f);
	//
	//	float pitchA = atan2(AY, sqrt(AX*AX + AZ * AZ))*RTD;
	//	float rollA = atan2(AX, sqrt(AY*AY + AZ*AZ))*RTD;
	//
	//	pitch = 0.98*pitchG + 0.02*pitchA;
	//	roll = 0.98*rollG + 0.02*rollA;
}

