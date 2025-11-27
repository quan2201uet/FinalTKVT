#include "BME280Task.h"


readBME280Task::readBME280Task(){}

void readBME280Task::init(void)
{
}

void readBME280Task::startTask()
{
	for(;;)
	{
		processTask();
		vTaskDelay(200);
	}
}


void readBME280Task::processTask(void)
{

	readData();
	if (xQueueSend(QueueBMEToLora, &_BME_data, 100) == pdPASS)
	{

	}

	if(xQueueSend(QueueBMEToMicroSD, &_BME_data, 100) == pdPASS)
	{

	}

}

void readBME280Task::readData(void)
{
//	dht11Start();
//	uint8_t float_Hum = 0;
//	uint8_t float_Tem = 0;
//	uint8_t CheckSum = 0;
//
//	_BME_data.humi = dht11ReadByte();
//	float_Hum = dht11ReadByte();
//	_BME_data.temp = dht11ReadByte();
//	float_Tem = dht11ReadByte();
//	CheckSum = dht11ReadByte();
}

//void readBME280Task::setToOutput()
//{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//	GPIO_InitStruct.Pin = GPIO_PIN_8;
//	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStruct.Pull = GPIO_PULLUP;
//	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//}
//
//void readBME280Task::setToInput()
//{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//	GPIO_InitStruct.Pin = GPIO_PIN_8;
//	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//	GPIO_InitStruct.Pull = GPIO_NOPULL;
//	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//}
//
//uint8_t readBME280Task::dht11ReadByte()
//{
//	uint8_t res = 0, i=0;
//
//	for(i = 0 ; i < 8 ;i++){
//		while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 0){} // Doi =1
//		vTaskDelay(1);
//		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 1){
//			// bit 1
//			res = (res << 1) | (1 << 0);
//		}else{
//			// bit 0
//			res = (res << 1) & ~(1 << 0);
//		}
//		while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 1){} // Doi =0
//	}
//
//	//res : 8 bit (1 byte)
//	return res;
//}
//
//void readBME280Task::dht11Start()
//{
//	setToOutput();
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 1);
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 0);
//	vTaskDelay(20);
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 1);
//	setToInput();
//	// Chua co thuat toan de check loi
//	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 1){} // Doi =0
//	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 0){} // Doi =1
//	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2) == 1){} // Doi =0
//}
//
//void readBME280Task::delay_us(uint16_t time_us )
//{
//	HAL_TIM_Base_Start(&htim2);
//	htim2.Instance->CNT = 0;
//	while(htim2.Instance->CNT < time_us){
//	}
//	HAL_TIM_Base_Stop(&htim2);
//}



