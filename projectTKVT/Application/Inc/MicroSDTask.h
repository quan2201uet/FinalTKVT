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

	void processTask();

	void giveData(void); // lấy dữ liệu từ các task khác


private:
	mavlink_sensor_data_t _Lora_data;
	GPS_data_t _GPS_data;
	BME_data_t _BME_data;
	IMU_data_t _IMU_data;
	float pm;
};


#endif /* INC_MICROSDTASK_H_ */
