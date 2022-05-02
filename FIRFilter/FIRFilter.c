/*
 * FIRFilter.c
 *
 *  Created on: 2022年5月1日
 *      Author: 27504
 */

#include "FIRFilter.h"

void FIRFilter_Init(FIRFilter *filt, float *coeff, float *buf, uint8_t order) {
	filt->out = 0.0f;
	filt->coeff = coeff;
	filt->buf = buf;
	filt->order = order;
	filt->putIndex = 0;
	for (uint8_t i = 0; i < order; i++) {
		filt->buf[i] = 0.0f;
	}
}

float FIRFilter_Update(FIRFilter *filt, float in) {
	/* Store newest input value in circular buffer */
	filt->buf[filt->putIndex] = in;
	/* Compute filter output */
	uint8_t getIndex = filt->putIndex;
	filt->out = 0.0f;
	for (uint8_t i = 0; i < filt->order; i++) {
		filt->out = filt->out + filt->coeff[i] * filt->buf[getIndex];
		if (getIndex == 0) {
			getIndex = filt->order - 1;
		} else {
			getIndex--;
		}
	}
	/* Increment buffer index */
	filt->putIndex = (filt->putIndex + 1) % filt->order;
	/* Return output */
	return filt->out;
}
