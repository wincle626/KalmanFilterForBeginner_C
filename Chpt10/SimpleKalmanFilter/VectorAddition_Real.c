/*
 * VectorAddition_Real.c
 *
 *  Created on: 28 Mar 2018
 *      Author: YunWu
 */

#include "VectorAddition_Real.h"

void VectorAddition_x_Real(float A[XSIZE],
						float B[XSIZE],
						float C[XSIZE]){

	int i;
	for(i=0;i<XSIZE;i++){
		C[i] = A[i] + B[i];
	}

}
