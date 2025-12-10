/*
 * uartSTM32.h
 *
 *  Created on: Nov 27, 2025
 *      Author: LAPTOP K1
 */

#ifndef DRIVERSTM32_INC_UARTSTM32_H_
#define DRIVERSTM32_INC_UARTSTM32_H_

#include "uartAbstract.h"
#include "main.h"

class uartSTM32 : public uartAbstract
{
public:
	uartSTM32(UART_HandleTypeDef*newUartInstance);
	~uartSTM32();

	void sendData(uint8_t*data,uint64_t length) override;
	void receiveData(uint8_t*data,uint64_t length) override;
private:
	UART_HandleTypeDef *uartInstance;
};


#endif /* DRIVERSTM32_INC_UARTSTM32_H_ */
