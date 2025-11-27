/*
 * myMain.h
 *
 *  Created on: Nov 20, 2025
 *      Author: LAPTOP K1
 */

#ifndef INC_MYMAIN_H_
#define INC_MYMAIN_H_

#ifdef __cplusplus
extern "C" {
#endif


void startIMUTask();
void startBMETask();
void startGPSTask();
void startPM25Task();
void startMICROTask();
void startLoraTask();

void startAllTask();
void controlSemaphore();


#ifdef __cplusplus
}
#endif

#endif /* INC_MYMAIN_H_ */
