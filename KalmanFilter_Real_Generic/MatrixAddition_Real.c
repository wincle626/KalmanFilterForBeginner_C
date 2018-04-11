/*
 * MatrixAddition_Real.c
 *
 *  Created on: 28 Mar 2018
 *      Author: YunWu
 */

#include "MatrixAddition_Real.h"

void MatrixAddition_Q_Real(float p[XSIZE][XSIZE],
						float q[XSIZE][XSIZE],
						float add[XSIZE][XSIZE]){
	int i,j;
	for(i=0;i<XSIZE;i++){
		for(j=0;j<XSIZE;j++){
			add[i][j] = p[i][j] + q[i][j];
		}
	}
}

void MatrixAddition_R_Real(float k[XDIM][XDIM],
						float r[XDIM][XDIM],
						float add[XDIM][XDIM]){
	int i,j;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XDIM;j++){
			add[i][j] = k[i][j] + r[i][j];
		}
	}
}
