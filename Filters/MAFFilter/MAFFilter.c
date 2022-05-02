/*
 * MAFFilter.c
 *
 *  Created on: 2022年5月2日
 *      Author: 27504
 */

#include "MAFFilter.h"

float MAF_IMPULSE[MAF_LENGTH] = { 0 };

void MAFFilter_Init(MAFFilter *filt) {
	filt->out = 0.0f;
	filt->putIndex = 0;
	for (uint8_t i = 0; i < MAF_LENGTH; i++) {
		filt->buf[i] = 0.0f;
		MAF_IMPULSE[i] = 1.0 / MAF_LENGTH;
	}
}

float MAFFilter_Update(MAFFilter *filt, float in) {
	/* Store newest input value in circular buffer */
	filt->buf[filt->putIndex] = in;
	/* Compute filter output */
	uint8_t getIndex = filt->putIndex;
	filt->out = 0.0f;
	for (uint8_t i = 0; i < MAF_LENGTH; i++) {
		filt->out = filt->out + MAF_IMPULSE[i] * filt->buf[getIndex];
		if (getIndex == 0) {
			getIndex = MAF_LENGTH - 1;
		} else {
			getIndex--;
		}
	}
	/* Increment buffer index */
	filt->putIndex = (filt->putIndex + 1) % MAF_LENGTH;
	/* Return output */
	return filt->out;
}
