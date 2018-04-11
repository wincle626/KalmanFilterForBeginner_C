/*
 * MatrixAddition_Real.h
 *
 *  Created on: 28 Mar 2018
 *      Author: YunWu
 */

#ifndef SRC_MATRIXADDITION_REAL_H_
#define SRC_MATRIXADDITION_REAL_H_

#include "System.h"

void MatrixAddition_Q_Real(float p[XSIZE][XSIZE],
						float q[XSIZE][XSIZE],
						float add[XSIZE][XSIZE]);
void MatrixAddition_R_Real(float k[XDIM][XDIM],
						float r[XDIM][XDIM],
						float add[XDIM][XDIM]);

#endif /* SRC_MATRIXADDITION_REAL_H_ */
