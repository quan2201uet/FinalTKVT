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
	QueueHandle_t _QueueGPSToMicroSD;
	QueueHandle_t _QueueGPSToLora;
	GPS_data_t _GPS_data;

	uint8_t RxChar;
	char RxBuffer[RX_BUFFER_SIZE];
	uint16_t idx = 0;

public:
	GPSDataAnalysisTask (QueueHandle_t QueueGPSToMicroSD, QueueHandle_t QueueGPSToLora);

	void initTask(void);

	static void startTask (void* pvParameters);

	float convertToDecimal(char *nmeaCoord);

	void parseGNRMC(char *nmea, GPS_data_t *gps);

	void readData(void);

	void sendData(void);

};

#endif /* INC_GPSTASK_H_ */
