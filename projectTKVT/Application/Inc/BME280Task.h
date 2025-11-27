#ifndef INC_BME280TASK_H_
#define INC_BME280TASK_H_

#include "common.h"
extern I2C_HandleTypeDef hi2c1;

class readBME280Task
{
private:
	BME_data_t _BME_data;
public:
	readBME280Task();
	void init(void);
	void startTask();

	void readData(void);
	void processTask(QueueSetMemberHandle_t activeMember);
};




#endif /* INC_BME280TASK_H_ */
