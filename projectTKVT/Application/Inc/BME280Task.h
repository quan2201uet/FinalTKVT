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
	void processTask(void);

	void setToOutput(void);
	void setToInput(void);
	uint8_t dht11ReadByte(void);
	void dht11Start(void);
	void delay_us( uint16_t time_us );
};




#endif /* INC_BME280TASK_H_ */
