/*
 * MatrixVectorMultiply_Real.h
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#ifndef SRC_MATRIXVECTORMULTIPLY_REAL_H_
#define SRC_MATRIXVECTORMULTIPLY_REAL_H_

#include "System.h"

void MatrixVectorMultiply_x1_Real(float A[XSIZE][XSIZE],
							float B[XSIZE],
							float C[XSIZE]);
void MatrixVectorMultiply_x2_Real(float A[XSIZE][XSIZE],
							float B[XSIZE],
							float C[XSIZE]);
void MatrixVectorMultiply_kz_Real(float A[XSIZE][XDIM],
							float B[XDIM],
							float C[XSIZE]);

#endif /* SRC_MATRIXVECTORMULTIPLY_REAL_H_ */
