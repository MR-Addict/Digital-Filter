/*
 * MAFFilter.h
 *
 *  Created on: 2022年5月2日
 *      Author: 27504
 */

#ifndef INC_MAFFILTER_MAFFILTER_H_
#define INC_MAFFILTER_MAFFILTER_H_

#include "stdint.h"

#define MAF_LENGTH 10

typedef struct {
	float buf[MAF_LENGTH];
	uint8_t putIndex;
} MAFFilter;

void MAFFilter_Init(MAFFilter*);
float MAFFilter_Update(MAFFilter*, float);

#endif /* INC_MAFFILTER_MAFFILTER_H_ */
