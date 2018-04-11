/*
 * OrthogonalMatrixInverse_Real.c
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#include "OrthogonalMatrixInverse_Real.h"

void OrthogonalMatrixInverse_Real(float Q[XDIM][XDIM],float Qi[XDIM][XDIM]){
	int i=0,j=0;
	// Q inversion
	for(i=0;i<XDIM;i++){
		Qi[i][i]=0;
		for(j=i+1;j<XDIM;j++){
			Qi[i][j] = Q[j][i];
		}
		for(j=0;j<=i;j++){
			Qi[i][j] = Q[j][i];
		}
	}
}
