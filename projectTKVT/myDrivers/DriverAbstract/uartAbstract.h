#ifndef UARTABSTRACT_H
#define UARTABSTRACT_H

#include "stdint.h"

class uartAbstract
{
public:
	uartAbstract();
	virtual ~uartAbstract() = 0;

	virtual void sendData(uint8_t*data,uint64_t length) = 0;
	virtual void receiveData(uint8_t*data,uint64_t length) = 0;
};

inline uartAbstract::uartAbstract()
{

}

inline uartAbstract::~uartAbstract()
{

}
#endif
