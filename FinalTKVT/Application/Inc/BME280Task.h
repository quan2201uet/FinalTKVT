#ifndef INC_BME280TASK_H_
#define INC_BME280TASK_H_

#include "common.h"
extern I2C_HandleTypeDef hi2c1;

class readBME280Task
{
private:
	QueueHandle_t _QueueBMEToMicroSD;
	QueueHandle_t _QueueBMEToLora;
	BME_data_t _BME_data;
public:
	readBME280Task(QueueHandle_t QueueBMEToMicroSD, QueueHandle_t QueueBMEToLora);
	void initTask(void);
	static void startTask(void* pvParameters);
	void readData(void);
	void sendData(void);
};




#endif /* INC_BME280TASK_H_ */
