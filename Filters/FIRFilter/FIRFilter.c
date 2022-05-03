/*
 * FIRFilter.c
 *
 *  Created on: 2022年5月1日
 *      Author: 27504
 */

#include "FIRFilter.h"

void FIRFilter_Init(FIRFilter *filt, float *taps, float *buf, uint8_t length) {
	filt->taps = taps;
	filt->buf = buf;
	filt->length = length;
	filt->putIndex = 0;
	for (uint8_t i = 0; i < length; i++) {
		filt->buf[i] = 0.0f;
	}
}

float FIRFilter_Update(FIRFilter *filt, float in) {
	/* Store newest input value in circular buffer */
	filt->buf[filt->putIndex] = in;
	/* Compute filter output */
	uint8_t getIndex = filt->putIndex;
	float out = 0;
	for (uint8_t i = 0; i < filt->length; i++) {
		out = out + filt->taps[i] * filt->buf[getIndex];
		if (getIndex == 0) {
			getIndex = filt->length - 1;
		} else {
			getIndex--;
		}
	}
	/* Increment buffer index */
	filt->putIndex = (filt->putIndex + 1) % filt->length;
	/* Return output */
	return out;
}
