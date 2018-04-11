/*
 * MatrixSubtraction_Real.c
 *
 *  Created on: 28 Mar 2018
 *      Author: YunWu
 */

#include "MatrixSubtraction_Real.h"

void MatrixSubtraction_P_Real(float A[XSIZE][XSIZE],
							float B[XSIZE][XSIZE],
							float C[XSIZE][XSIZE]){

	int i,j;
	for(i=0;i<XSIZE;i++){
		for(j=0;j<XSIZE;j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}

}
