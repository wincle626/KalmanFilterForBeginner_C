/*
 * QRD_Real.c
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#include "QRD_Real.h"

void QRD_Real(float Matrix_in[XDIM][XDIM],
			float Q[XDIM][XDIM],
			float R[XDIM][XDIM]){
	// Initialisation
	int i = 0,j = 0,k = 0;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XDIM;j++){
			Q[i][j] = Matrix_in[i][j];
			R[i][j] = 0;
		}
	}

	// Phase 1: get the norm
	float norm[XDIM];
	for(i=0;i<XDIM;i++){
		norm[i] = 0;
		for(j=0;j<XDIM;j++){
			float mul = Matrix_in[j][i] * Matrix_in[j][i];
			norm[i] = norm[i] + mul;
		}
	}

	// Phase 2: get the Q&R
	for(i=0;i<XDIM;i++){
		// derive R
		R[i][i] = sqrt(norm[i]);
		for(k=0;k<XDIM;k++){
			Q[k][i]=Q[k][i]/R[i][i];
		}
		for(j=i+1;j<XDIM;j++){
			float tmp;
			for(k=0;k<XDIM;k++){
				// update R
				R[i][j] = R[i][j] + Q[k][i] * Q[k][j];
			}
			for(k=0;k<XDIM;k++){
				// update Q
				Q[k][j] = Q[k][j] - Q[k][i] * R[i][j];
			}
			// update norm
			norm[j] = norm[j] - R[i][j] * R[i][j];
		}
	}
}
