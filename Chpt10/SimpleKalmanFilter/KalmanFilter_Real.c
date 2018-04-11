/*
 * KalmanFilter_Real.c
 *
 *  Created on: 26 Mar 2018
 *      Author: YunWu
 */

#include "MatrixInverse_Real.h"
#include "MatrixVectorMultiply_Real.h"
#include "VectorMatrixMultiply_Real.h"
#include "MatrixTranspose_Real.h"
#include "MatrixAddition_Real.h"
#include "MatrixSubtraction_Real.h"
#include "VectorAddition_Real.h"
#include "VectorSubtraction_Real.h"
#include "MatrixVectorMultiply_Real.h"
#include "VectorMatrixMultiply_Real.h"

void KalmanFilter_Init_x_Real(float x0[XSIZE], float x_init[XSIZE]){

	int i;
	for(i=0;i<XSIZE;i++){
		x_init[i] = x0[i];
	}

}

void KalmanFilter_Init_P_Real(float p0[XSIZE][XSIZE],
							float P_init[XSIZE][XSIZE]){

	int i,j;
	for(i=0;i<XSIZE;i++){
		for(j=0;j<XSIZE;j++){
			P_init[i][j] = p0[i][j];
		}
	}

}

void KalmanFilter_Init_A_Real(float a0[XDIM][XSIZE],
							float A[XSIZE][XSIZE]){

	int i,j;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XSIZE;j++){
			A[i][j] = a0[i][j];
		}
	}

}

void KalmanFilter_Init_H_Real(float h0[XDIM][XSIZE],
							float H[XDIM][XSIZE]){

	int i,j;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XSIZE;j++){
			H[i][j] = h0[i][j];
		}
	}

}

void KalmanFilter_Init_Q_Real(float q0[XSIZE][XSIZE],
							float Q[XSIZE][XSIZE]){

	int i,j;
	for(i=0;i<XSIZE;i++){
		for(j=0;j<XSIZE;j++){
			Q[i][j] = q0[i][j];
		}
	}

}

void KalmanFilter_Init_R_Real(float r0[XDIM][XDIM],
							float R[XDIM][XDIM]){

	int i,j;
	for(i=0;i<XDIM;i++){
		for(j=0;j<XDIM;j++){
			R[i][j] = r0[i][j];
		}
	}

}

void KalmanFilter_Predict_x_Real(float x_k_1[XSIZE],
								float A[XSIZE][XSIZE],
								float x_predict[XSIZE]){

	MatrixVectorMultiply_x1_Real(A,x_k_1,x_predict);

}

void KalmanFilter_Predict_P_Real(float P_k_1[XSIZE][XSIZE],
								float A[XSIZE][XSIZE],
								float Q[XSIZE][XSIZE],
								float P_predict[XSIZE][XSIZE]){

	float A_T[XSIZE][XSIZE];
	float P_tmp1[XSIZE][XSIZE];
	float P_tmp2[XSIZE][XSIZE];
	MatrixTranspose_P_Real(A,A_T);
	MatrixMultiply_P_Real(A,P_k_1,P_tmp1);
	MatrixMultiply_P_Real(P_tmp1,A_T,P_tmp2);
	MatrixAddition_Q_Real(P_tmp2,Q,P_predict);

}

void KalmanFitler_Gain_Real(float P_predict[XSIZE][XSIZE],
							float H[XDIM][XSIZE],
							float R[XDIM][XDIM],
							float K[XSIZE][XDIM]){

	float M_tmp1[XSIZE][XDIM];
	float M_tmp2[XDIM][XSIZE];
	float M_tmp3[XDIM][XDIM];
	float M_tmp4[XDIM][XDIM];
	float M_tmp5[XDIM][XDIM];
	float H_T[XSIZE][XDIM];
	MatrixTranspose_H_Real(H,H_T);
	MatrixMultiply_K0_Real(P_predict,H_T,M_tmp1);
	MatrixMultiply_K1_Real(H,P_predict,M_tmp2);
	MatrixMultiply_K3_Real(M_tmp2,H_T,M_tmp3);
	MatrixAddition_R_Real(M_tmp3,R,M_tmp4);
	MatrixInverse_R_Real(M_tmp4,M_tmp5);
	MatrixMultiply_K5_Real(M_tmp1,M_tmp5,K);

}

void KalmanFilter_Estimate_Real(float z[XSIZE],
								float H[XDIM][XSIZE],
								float x_predict[XSIZE],
								float K[XSIZE][XDIM],
								float x_est[XSIZE]){
	float v_tmp1[XDIM];
	float z_sub[XDIM];
	float v_tmp2[XSIZE];
	MatrixVectorMultiply_x2_Real(H,x_predict,v_tmp1);
	VectorSubtraction_z_Real(z,v_tmp1,z_sub);
	MatrixVectorMultiply_kz_Real(K,z_sub,v_tmp2);
	VectorAddition_x_Real(x_predict,v_tmp2,x_est);

}

void KalmanFilter_CoVarUpdate_Real(float P_predict[XSIZE][XSIZE],
								float K[XSIZE][XDIM],
								float H[XDIM][XSIZE],
								float P_k[XSIZE][XSIZE]){

	float M_tmp1[XSIZE][XSIZE];
	float M_tmp2[XSIZE][XSIZE];
	MatrixMultiply_K2_Real(K,H,M_tmp1);
	MatrixMultiply_P_Real(M_tmp1,P_predict,M_tmp2);
	MatrixSubtraction_P_Real(P_predict,M_tmp2,P_k);

}
