#ifndef INC_PM25TASK_H_
#define INC_PM25TASK_H_

#include "common.h"

class readPM25Task
{
private:
	QueueHandle_t _QueuePM25ToMicroSD;
	QueueHandle_t _QueuePM25ToLora;
	float pm;
public:
	readPM25Task(QueueHandle_t QueuePM25ToMicroSD, QueueHandle_t QueuePM25ToLora);
	void initTask(void);
	static void startTask(void* pvParameters);
	void readData(void);
	void sendData(void);
};




#endif /* INC_PM25TASK_H_ */
