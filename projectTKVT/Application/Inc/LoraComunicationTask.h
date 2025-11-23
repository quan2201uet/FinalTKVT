#ifndef INC_LORACOMUNICATIONTASK_H_
#define INC_LORACOMUNICATIONTASK_H_

#include "common.h"
#include "mavlink.h"
#include "mavlink_types.h"
#include "mavlink_msg_sensor_data.h"

/* BEGIN INCLUE DEFINE */
#define SYSTEM_ID           20       // ID của thiết bị (STM32)
#define COMPONENT_ID        1        // ID của thành phần
#define MAVLINK_MAX_TX_BUFFER_LEN 300
/* END INCLUE DEFINE */

class LoraComunicationTask
{

public:
	LoraComunicationTask();

	void init(void);

	void startTask();

	void processTask();

	void giveData(void); // lấy dữ liệu từ các task khác


private:
	mavlink_message_t msg;
	uint16_t len_encoded;
	mavlink_sensor_data_t _Lora_data;
	uint8_t tx_mavlink_buffer[MAVLINK_MAX_TX_BUFFER_LEN];

	GPS_data_t _GPS_data;
	BME_data_t _BME_data;
	IMU_data_t _IMU_data;
	float pm;

};

#endif /* INC_LORACOMUNICATIONTASK_H_ */
