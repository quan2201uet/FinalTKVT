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
	readPM25Task();
	void init(void);
	void startTask();
	void readData(void);
	void processTask(void);
};




#endif /* INC_PM25TASK_H_ */
