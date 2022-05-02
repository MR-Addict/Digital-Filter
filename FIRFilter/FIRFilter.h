/*
 * FIRFilter.h
 *
 *  Created on: 2022年5月1日
 *      Author: 27504
 */

#ifndef INC_FIRFILTER_FIRFILTER_H_
#define INC_FIRFILTER_FIRFILTER_H_

#include "stdio.h"

typedef struct {
	float out;
	float *buf;
	float *coeff;
	uint8_t order;
	uint8_t putIndex;
} FIRFilter;

void FIRFilter_Init(FIRFilter*, float*, float*, uint8_t);
float FIRFilter_Update(FIRFilter*, float);

#endif /* INC_FIRFILTER_FIRFILTER_H_ */
