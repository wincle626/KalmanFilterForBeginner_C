/*
 * MatrixTranspose_Real.h
 *
 *  Created on: 28 Mar 2018
 *      Author: YunWu
 */

#ifndef SRC_MATRIXTRANSPOSE_REAL_H_
#define SRC_MATRIXTRANSPOSE_REAL_H_

#include "System.h"

void MatrixTranspose_P_Real(float p[XSIZE][XSIZE],
						float p_T[XSIZE][XSIZE]);
void MatrixTranspose_H_Real(float h[XDIM][XSIZE],
						float h_T[XSIZE][XDIM]);

#endif /* SRC_MATRIXTRANSPOSE_REAL_H_ */
