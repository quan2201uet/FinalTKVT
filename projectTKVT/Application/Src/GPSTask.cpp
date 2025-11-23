#include "GPSTask.h"

GPSDataAnalysisTask :: GPSDataAnalysisTask(){}

void GPSDataAnalysisTask::init(void)
{

}

void GPSDataAnalysisTask::startTask()
{
	for(;;)
	{
		processTask();

	}
}

void GPSDataAnalysisTask::processTask(void)
{

	xSemaphoreTake(semaGPSTask, portMAX_DELAY);
	readData();
	if (xQueueSend(QueueGPSToLora, &_GPS_data, 100) == pdPASS)
	{

	}
	if (xQueueSend(QueueGPSToMicroSD, &_GPS_data, 100) == pdPASS)
	{

	}

}
void GPSDataAnalysisTask::readData(void)
{
	HAL_UART_Receive(&huart2, &RxChar, 1, 10);

	if(idx < RX_BUFFER_SIZE-1) RxBuffer[idx++] = RxChar;
	// Kết thúc chuỗi NMEA
	if(RxChar == '\n')
	{
		RxBuffer[idx] = '\0'; // kết thúc chuỗi
		if(strstr(RxBuffer, "$GPx") != NULL)
		{
			parseGNRMC(RxBuffer, &_GPS_data);
		}

		// Reset buffer
		idx = 0;
		memset(RxBuffer, 0, RX_BUFFER_SIZE);
	}
}

void GPSDataAnalysisTask:: parseGNRMC(char *nmea, GPS_data_t *gps)
{
	char *token;
	int field = 0;

	token = strtok(nmea, ",");
	while(token != NULL)
	{
		field++;
		switch(field)
		{
		case 2: // Thời gian UTC (hhmmss.sss)
			gps->timeUTC = atof(token);
			break;

			//            case 3: // Trạng thái (A/V)
			//                gps->status = token[0];
			//                break;

		case 4: // Vĩ độ
			gps->lat = convertToDecimal(token);
			break;

		case 5: // Bắc/Nam
			gps->ns = token[0];
			if(gps->ns == 'S') gps->lat = -gps->lat;
			break;

		case 6: // Kinh độ
			gps->lon = convertToDecimal(token);
			break;

		case 7: // Đông/Tây
			gps->ew = token[0];
			if(gps->ew == 'W') gps->lon = -gps->lon;
			break;

		case 8: // Tốc độ (knots)
			gps->speed = atof(token);
			break;

		case 9: // Hướng di chuyển
			gps->course = atof(token);
			break;

			//            case 10: // Ngày (ddmmyy)
			//                if (strlen(token) == 6) {
			//                    char d[3], m[3], y[3];
			//                    strncpy(d, token, 2); d[2] = '\0';
			//                    strncpy(m, token + 2, 2); m[2] = '\0';
			//                    strncpy(y, token + 4, 2); y[2] = '\0';
			//                    gps->day = atoi(d);
			//                    gps->month = atoi(m);
			//                    gps->year = 2000 + atoi(y);
			//                }
			//                break;
		}

		token = strtok(NULL, ",");
	}
}

float GPSDataAnalysisTask::convertToDecimal(char *nmeaCoord)
{
	float val = atof(nmeaCoord);
	int degrees = (int)(val / 100);
	float minutes = val - (degrees * 100);
	return degrees + minutes / 60.0f;
}


