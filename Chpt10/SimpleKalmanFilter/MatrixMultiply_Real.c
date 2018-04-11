/*
 * MatrixMultiply_Real.c
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#include "MatrixMultiply_Real.h"

void MatrixMultiply_P_Real(float A[XSIZE][XSIZE],
						float B[XSIZE][XSIZE],
						float C[XSIZE][XSIZE]){

	int i=0,j=0,k=0;
	for(i=0;i<XSIZE;i++){
		for(j=0;j<XSIZE;j++){
			C[i][j]=0;
			for(k=0;k<XSIZE;k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

}

void MatrixMultiply_R_Real(float A[XDIM][XDIM],
						float B[XDIM][XDIM],
						float C[XDIM][XDIM]){

	int i=0,j=0,k=0;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XDIM;j++){
			C[i][j]=0;
			for(k=0;k<XDIM;k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

}

void MatrixMultiply_K0_Real(float A[XSIZE][XSIZE],
						float B[XSIZE][XDIM],
						float C[XSIZE][XDIM]){

	int i=0,j=0,k=0;
	for(i=0;i<XSIZE;i++){
		for(j=0;j<XDIM;j++){
			C[i][j]=0;
			for(k=0;k<XSIZE;k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

}

void MatrixMultiply_K1_Real(float A[XDIM][XSIZE],
						float B[XSIZE][XSIZE],
						float C[XDIM][XSIZE]){

	int i=0,j=0,k=0;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XSIZE;j++){
			C[i][j]=0;
			for(k=0;k<XSIZE;k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

}

void MatrixMultiply_K2_Real(float A[XSIZE][XDIM],
						float B[XDIM][XSIZE],
						float C[XSIZE][XSIZE]){

	int i=0,j=0,k=0;
	for(i=0;i<XSIZE;i++){
		for(j=0;j<XSIZE;j++){
			C[i][j]=0;
			for(k=0;k<XDIM;k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

}

void MatrixMultiply_K3_Real(float A[XDIM][XSIZE],
						float B[XSIZE][XDIM],
						float C[XDIM][XDIM]){

	int i=0,j=0,k=0;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XDIM;j++){
			C[i][j]=0;
			for(k=0;k<XSIZE;k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

}

void MatrixMultiply_K4_Real(float A[XDIM][XDIM],
						float B[XDIM][XDIM],
						float C[XDIM][XDIM]){

	int i=0,j=0,k=0;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XDIM;j++){
			C[i][j]=0;
			for(k=0;k<XDIM;k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

}

void MatrixMultiply_K5_Real(float A[XSIZE][XDIM],
						float B[XDIM][XDIM],
						float C[XSIZE][XDIM]){

	int i=0,j=0,k=0;
	for(i=0;i<XSIZE;i++){
		for(j=0;j<XDIM;j++){
			C[i][j]=0;
			for(k=0;k<XDIM;k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

}

