/*
 * GPSTask.h
 *
 *  Created on: Nov 7, 2025
 *      Author: LAPTOP K1
 */

#ifndef INC_GPSTASK_H_
#define INC_GPSTASK_H_


#include "common.h"
#include "string.h"
#include <stdlib.h>
extern UART_HandleTypeDef huart2;
#define RX_BUFFER_SIZE 128

class GPSDataAnalysisTask
{
private:
	float convertToDecimal(char *nmeaCoord);
	void parseGNRMC(char *nmea, GPS_data_t *gps);
	void readData(void);
	void processTask(QueueSetMemberHandle_t activeMember);
	GPS_data_t _GPS_data;
public:
	GPSDataAnalysisTask ();

	void init(void);

	void startTask ();



};

#endif /* INC_GPSTASK_H_ */
