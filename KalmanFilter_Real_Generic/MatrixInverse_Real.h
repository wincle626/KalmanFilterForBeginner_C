/*
 * MatrixInverse_Real.h
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#ifndef SRC_MATRIXINVERSE_REAL_H_
#define SRC_MATRIXINVERSE_REAL_H_

#include "QRD_Real.h"
#include "UpperTriangularMatrixInverse_Real.h"
#include "OrthogonalMatrixInverse_Real.h"
#include "MatrixMultiply_Real.h"

void MatrixInverse_R_Real(float Matrix_in[XDIM][XDIM],
					float Matrix_out[XDIM][XDIM]);

#endif /* SRC_MATRIXINVERSE_REAL_H_ */
