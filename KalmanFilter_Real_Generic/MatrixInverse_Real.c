/*
 * MatrixInverse_Real.c
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#include "MatrixInverse_Real.h"

void MatrixInverse_R_Real(float Matrix_in[XDIM][XDIM],
					float Matrix_out[XDIM][XDIM]){

	float Q[XDIM][XDIM],R[XDIM][XDIM];
	float Qi[XDIM][XDIM],Ri[XDIM][XDIM];
	QRD_Real(Matrix_in,Q,R);
	//TestM(Matrix_in);TestM(Q);TestM(R);
	UpperTriangularMatrixInverse_Real(R,Ri);
	OrthogonalMatrixInverse_Real(Q,Qi);
	//TestM(Qi);TestM(Ri);
	MatrixMultiply_R_Real(Ri,Qi,Matrix_out);
	//TestM(Matrix_out);

}
