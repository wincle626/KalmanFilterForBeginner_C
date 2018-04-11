/*
 * VectorMatrixMultiply_Real.c
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#include "VectorMatrixMultiply_Real.h"

void VectorMatrixMultiply_Real(float A[XSIZE],
							float B[XSIZE][XSIZE],
							float C[XSIZE]){

	int i,j;
	for(i=0;i<XSIZE;i++){
		float sum = 0;
		for(j=0;j<XSIZE;j++){
			sum = sum + A[j] * B[j][i];
		}
		C[i] = sum;
	}

}

