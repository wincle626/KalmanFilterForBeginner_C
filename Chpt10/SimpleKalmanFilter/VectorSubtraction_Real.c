/*
 * VectorSubtraction_Real.c
 *
 *  Created on: 28 Mar 2018
 *      Author: YunWu
 */

#include "VectorSubtraction_Real.h"

void VectorSubtraction_z_Real(float A[XDIM],
							float B[XDIM],
							float C[XDIM]){

	int i;
	for(i=0;i<XDIM;i++){
		C[i] = A[i] - B[i];
	}

}
