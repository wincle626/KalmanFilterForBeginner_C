/*
 * MatrixVectorMultiply_Real.c
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#include "MatrixVectorMultiply_Real.h"

void MatrixVectorMultiply_x1_Real(float A[XSIZE][XSIZE],
							float B[XSIZE],
							float C[XSIZE]){

	int i,j;
	for(i=0;i<XSIZE;i++){
		float sum = 0;
		for(j=0;j<XSIZE;j++){
			sum = sum + A[i][j] * B[j];
		}
		C[i] = sum;
	}

}

void MatrixVectorMultiply_x2_Real(float A[XDIM][XSIZE],
							float B[XSIZE],
							float C[XDIM]){

	int i,j;
	for(i=0;i<XDIM;i++){
		float sum = 0;
		for(j=0;j<XSIZE;j++){
			sum = sum + A[i][j] * B[j];
		}
		C[i] = sum;
	}

}

void MatrixVectorMultiply_kz_Real(float A[XSIZE][XDIM],
							float B[XDIM],
							float C[XSIZE]){

	int i,j;
	for(i=0;i<XSIZE;i++){
		float sum = 0;
		for(j=0;j<XDIM;j++){
			sum = sum + A[i][j] * B[j];
		}
		C[i] = sum;
	}

}

