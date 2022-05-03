/*
 * FIRFilter.h
 *
 *  Created on: 2022年5月1日
 *      Author: 27504
 */

#ifndef INC_FIRFILTER_FIRFILTER_H_
#define INC_FIRFILTER_FIRFILTER_H_

#include "stdint.h"

typedef struct {
	float *buf;
	float *taps;
	uint8_t length;
	uint8_t putIndex;
} FIRFilter;

void FIRFilter_Init(FIRFilter*, float*, float*, uint8_t);
float FIRFilter_Update(FIRFilter*, float);

#endif /* INC_FIRFILTER_FIRFILTER_H_ */
