#include <LoraComunicationTask.h>

LoraComunicationTask::LoraComunicationTask(){}

void LoraComunicationTask::init(void)
{

}


void LoraComunicationTask::startTask()
{
	QueueSetMemberHandle_t activeMember;
	for(;;)
	{
		activeMember = xQueueSelectFromSet(LoraTaskQueueSet, 10);
		processTask(activeMember);
	}
}

void LoraComunicationTask::processTask(QueueSetMemberHandle_t activeMember)
{
	if(activeMember == semaLoraComunicationTask)
	{
		if(xSemaphoreTake(semaLoraComunicationTask, 10) == pdPASS) // gửi bản tin với tần số 1HZ
		{
			len_encoded = mavlink_msg_sensor_data_encode(SYSTEM_ID, COMPONENT_ID, &msg, &_Lora_data);
			len_encoded = mavlink_msg_to_send_buffer(tx_mavlink_buffer, &msg);
			if (len_encoded > 0) {
				HAL_UART_Transmit(&huart1, tx_mavlink_buffer, len_encoded, 100);
			}
		}
	}
	else if(activeMember == QueueBMEToLora)
	{
		getBMEDataFromQueue();
	}
	else if (activeMember == QueueGPSToLora)
	{
		getGPSDataFromQueue();
	}
	else if (activeMember == QueueIMUToLora)
	{
		getIMUDataFromQueue();
	}
	else if (activeMember == QueuePM25ToLora)
	{
		getPM25DataFromQueue();
	}

}


/* USER FUNCTION CODE BEGIN */
void LoraComunicationTask::getBMEDataFromQueue()
{
	if(xQueueReceive(QueueBMEToLora, &_BME_data, 10) == pdPASS)
	{
		_Lora_data.temperature  = _BME_data.temp;
		_Lora_data.humidity     = _BME_data.humi;
		_Lora_data.pressure     = _BME_data.press;
	}
}

void LoraComunicationTask::getGPSDataFromQueue()
{
	if(xQueueReceive(QueueGPSToLora, &_GPS_data, 10) == pdPASS)
	{
		_Lora_data.utc_time  = _GPS_data.timeUTC;
		_Lora_data.latitude  = _GPS_data.lat;
		_Lora_data.longitude = _GPS_data.lon;
		_Lora_data.speed     = _GPS_data.speed;
		_Lora_data.course    = _GPS_data.course;
	}
}
void LoraComunicationTask::getIMUDataFromQueue()
{
	if(xQueueReceive(QueueIMUToLora, &_IMU_data, 10) == pdPASS)
	{
		_Lora_data.acc_x  = _IMU_data.ax;
		_Lora_data.acc_y  = _IMU_data.ay;
		_Lora_data.acc_z  = _IMU_data.az;

		_Lora_data.gyro_x = _IMU_data.gx;
		_Lora_data.gyro_y = _IMU_data.gy;
		_Lora_data.gyro_z = _IMU_data.gz;
	}
}

void LoraComunicationTask::getPM25DataFromQueue()
{
	if(xQueueReceive(QueuePM25ToLora, &pm, 10) == pdPASS)
	{
		_Lora_data.pm_diameter = pm;
	}
}
/* USER FUNCTION CODE END */



