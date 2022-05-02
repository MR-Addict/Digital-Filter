/*
 * IIRFilter.c
 *
 *  Created on: 2022年5月2日
 *      Author: 27504
 */

#include "IIRFilter.h"

void IIRFilter_Init(IIRFilter *filt, float alpha) {
	filt->alpha = alpha;
	filt->out = 0.0f;
}

float IIRFilter_Update(IIRFilter *filt, float in) {
	filt->out = filt->alpha * filt->out + (1.0f - filt->alpha) * in;
	return filt->out;
}
