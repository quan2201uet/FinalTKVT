/*
 * uartSTM32.cpp
 *
 *  Created on: Nov 27, 2025
 *      Author: LAPTOP K1
 */
#include "uartSTM32.h"


uartSTM32::uartSTM32(UART_HandleTypeDef*newUartInstance)
{
	uartInstance = newUartInstance;
}

uartSTM32::~uartSTM32()
{

}

void uartSTM32::sendData(uint8_t*data,uint64_t length)
{
	HAL_UART_Transmit(uartInstance, data, length, 100);
}

void uartSTM32::receiveData(uint8_t*data,uint64_t length)
{

}
