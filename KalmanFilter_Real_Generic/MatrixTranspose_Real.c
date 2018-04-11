/*
 * MatrixTranspose_Real.c
 *
 *  Created on: 28 Mar 2018
 *      Author: YunWu
 */

#include "MatrixTranspose_Real.h"

void MatrixTranspose_P_Real(float p[XSIZE][XSIZE],
						float p_T[XSIZE][XSIZE]){
	int i,j;
	for(i=0;i<XSIZE;i++){
		for(j=0;j<XSIZE;j++){
			p_T[j][i] = p[i][j];
		}
	}
}

void MatrixTranspose_H_Real(float h[XDIM][XSIZE],
						float h_T[XSIZE][XDIM]){
	int i,j;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XSIZE;j++){
			h_T[j][i] = h[i][j];
		}
	}
}
