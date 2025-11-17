#include "common.h"

uint8_t counter = 0;
void softwareTimer(void)
{
	// timer = 50hz = 20ms
	counter++;
	xSemaphoreGive(semaIMUTask);

	if (counter == 10)
	{
		xSemaphoreGive(semaBME280Task);
		xSemaphoreGive(semaGPSTask);
	}
	else if (counter == 50)
	{
		xSemaphoreGive(semaLoraComunicationTask);
		xSemaphoreGive(semaPM25Task);
		xSemaphoreGive(semaPM25Task);
		counter = 0;
	}
}
