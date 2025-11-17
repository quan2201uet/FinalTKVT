#ifndef INC_IMUTASK_H_
#define INC_IMUTASK_H_

#include "common.h"

extern I2C_HandleTypeDef hi2c2;


class readRawDataIMUTask
{
private:
	QueueHandle_t _QueueIMUToMicroSD;
	QueueHandle_t _QueueIMUToLora;
	IMU_data_t _IMU_data;
public:
	readRawDataIMUTask(QueueHandle_t QueueIMUToMicroSD, QueueHandle_t QueueIMUToLora);

	void initTask(void);
	static void startTask(void* pvParameters);
	void readData(void);
	void senData(void);
};



#endif /* INC_IMUTASK_H_ */
