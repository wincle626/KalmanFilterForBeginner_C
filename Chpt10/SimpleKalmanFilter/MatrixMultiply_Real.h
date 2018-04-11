/*
 * MatrixMultiply_Real.h
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#ifndef SRC_MATRIXMULTIPLY_REAL_H_
#define SRC_MATRIXMULTIPLY_REAL_H_

#include "System.h"

void MatrixMultiply_P_Real(float A[XSIZE][XSIZE],
						float B[XSIZE][XSIZE],
						float C[XSIZE][XSIZE]);
void MatrixMultiply_K0_Real(float A[XSIZE][XSIZE],
						float B[XSIZE][XDIM],
						float C[XSIZE][XDIM]);
void MatrixMultiply_K1_Real(float A[XDIM][XSIZE],
						float B[XSIZE][XSIZE],
						float C[XDIM][XSIZE]);
void MatrixMultiply_K2_Real(float A[XSIZE][XDIM],
						float B[XDIM][XSIZE],
						float C[XSIZE][XSIZE]);
void MatrixMultiply_K3_Real(float A[XDIM][XSIZE],
						float B[XSIZE][XDIM],
						float C[XDIM][XDIM]);
void MatrixMultiply_K4_Real(float A[XDIM][XDIM],
						float B[XDIM][XDIM],
						float C[XDIM][XDIM]);
void MatrixMultiply_K5_Real(float A[XSIZE][XDIM],
						float B[XDIM][XDIM],
						float C[XSIZE][XDIM]);

#endif /* SRC_MATRIXMULTIPLY_REAL_H_ */
