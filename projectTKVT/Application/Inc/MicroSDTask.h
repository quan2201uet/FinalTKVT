#ifndef INC_MICROSDTASK_H_
#define INC_MICROSDTASK_H_

#include "common.h"
#include "mavlink.h"
#include "mavlink_types.h"
#include "mavlink_msg_sensor_data.h"

class logDataTask
{
public:
	logDataTask();
	void init(void);
	void startTask();
private:
	mavlink_sensor_data_t _MicroSD_data;
	void processTask(QueueSetMemberHandle_t activeMember);
	void getBMEDataFromQueue();
	void getGPSDataFromQueue();
	void getIMUDataFromQueue();
	void getPM25DataFromQueue();
};


#endif /* INC_MICROSDTASK_H_ */
