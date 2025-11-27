#include "MicroSDTask.h"

void logDataTask::init()
{
	counter = 0;
}

void logDataTask::startTask()
{
	fr = f_mount(&fs, "", 1);
	for(;;)
	{
		processTask();
	}
}

void logDataTask::processTask()
{
	giveData();
	if(counter == 1000)
	{
		if(fr == FR_OK){
			fr = f_open(&fil, "log.txt", FA_CREATE_ALWAYS | FA_WRITE);
			if(fr == FR_OK){
				// ghi đầu mục cho dữ liệu

				fr = f_write(&fil, &_Lora_data, sizeof(_Lora_data), &bw);
				f_write(&fil, "\n", 1, &bw);

				f_sync(&fil);
				f_close(&fil);
			}
		}
		counter = 0;
	}
}

void logDataTask::giveData()
{
	if(xQueueReceive(QueueBMEToMicroSD, &_BME_data, 10) == pdPASS)
	{
		_Lora_data.temperature  = _BME_data.temp;
		_Lora_data.humidity     = _BME_data.humi;
		_Lora_data.pressure     = _BME_data.press;
	}

	if(xQueueReceive(QueueGPSToMicroSD, &_GPS_data, 10) == pdPASS)
	{
		_Lora_data.utc_time  = _GPS_data.timeUTC;
		_Lora_data.latitude  = _GPS_data.lat;
		_Lora_data.longitude = _GPS_data.lon;
		_Lora_data.speed     = _GPS_data.speed;
		_Lora_data.course    = _GPS_data.course;
	}

	if(xQueueReceive(QueueIMUToMicroSD, &_IMU_data, 10) == pdPASS)
	{
		_Lora_data.acc_x  = _IMU_data.ax;
		_Lora_data.acc_y  = _IMU_data.ay;
		_Lora_data.acc_z  = _IMU_data.az;

		_Lora_data.gyro_x = _IMU_data.gx;
		_Lora_data.gyro_y = _IMU_data.gy;
		_Lora_data.gyro_z = _IMU_data.gz;
	}

	if(xQueueReceive(QueuePM25ToMicroSD, &pm, 10) == pdPASS)
	{
		_Lora_data.pm_diameter = pm;
	}
}
