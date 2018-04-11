/*
 * UpperTriangularMatrixInverse_Real.c
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#include "UpperTriangularMatrixInverse_Real.h"

void UpperTriangularMatrixInverse_Real(float R[XDIM][XDIM],float Ri[XDIM][XDIM]){
	int i=0,j=0,k=0;
	// R inversion
	for(i=0;i<XDIM;i++){
		for(j=0;j<XDIM;j++){
			Ri[i][j]=0;
		}
	}
	for(i=0;i<XDIM;i++){
		Ri[i][i]=1/R[i][i];
		for(j=i+1;j<XDIM;j++){
			for(k=0;k<=j-1;k++){
				Ri[i][j] = Ri[i][j] + Ri[i][k] * R[k][j] / R[j][j];
			}
		}
	}
}
