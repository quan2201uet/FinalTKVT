#ifndef INC_PM25TASK_H_
#define INC_PM25TASK_H_

#include "common.h"

class readPM25Task
{
private:
	float pm;
	void readData(void);
	void processTask(QueueSetMemberHandle_t activeMember);
public:
	readPM25Task();
	void init(void);
	void startTask();
};
#endif /* INC_PM25TASK_H_ */
