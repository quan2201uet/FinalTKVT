#ifndef INC_LORACOMUNICATIONTASK_H_
#define INC_LORACOMUNICATIONTASK_H_

#include "common.h"
#include "mavlink.h"
#include "mavlink_types.h"
#include "mavlink_msg_sensor_data.h"
#include "uartAbstract.h"

/* BEGIN INCLUE DEFINE */
#define SYSTEM_ID           20       // ID của thiết bị (STM32)
#define COMPONENT_ID        1        // ID của thành phần
#define MAVLINK_MAX_TX_BUFFER_LEN 300
/* END INCLUE DEFINE */

class LoraComunicationTask
{

public:
	LoraComunicationTask(uartAbstract * newUartProtocol);
	~LoraComunicationTask();
	void init(void);

	void startTask();

private:
	uartAbstract* uartProtocol {nullptr};
	mavlink_sensor_data_t _Lora_data;
	void getBMEDataFromQueue();
	void getGPSDataFromQueue();
	void getIMUDataFromQueue();
	void getPM25DataFromQueue();
	void processTask(QueueSetMemberHandle_t activeMember);

};

#endif /* INC_LORACOMUNICATIONTASK_H_ */
