/*
 * IIRFilter.h
 *
 *  Created on: 2022年5月2日
 *      Author: 27504
 */

#ifndef INC_IIRFILTER_IIRFILTER_H_
#define INC_IIRFILTER_IIRFILTER_H_

typedef struct {
	float alpha;
	float out;
} IIRFilter;

void IIRFilter_Init(IIRFilter*, float);
float IIRFilter_Update(IIRFilter*, float);

#endif /* INC_IIRFILTER_IIRFILTER_H_ */
