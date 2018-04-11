#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

#define Nsamples 51

static int firstRun = 0;

float GetVolt(){

	float w = 0 + 4*rand()%1000/1000;
	float z = 14.4 + w;
	return w;

}

float SimpleKalman(float z){

	static float A, H, Q, R;
	static float A_trans, H_trans;
	static float x, P;

	if(firstRun!=0){
		
		A = 1;
		H = 1;

		Q = 0;
		R = 4;

		x = 14;
		P = 6;

		A_trans = A;
		H_trans = H;
		
		firstRun = 1;

	}

	float xp = A * x;
	float Pp = A * P * A_trans + Q;

	K = Pp * H_trans + 1 (H * Pp * H_trans + R);
	x = xp + K * (z - H * xp);
	P = Pp - K * H * Pp;

}

int main(int argc, char **argv){

	int i;
	float dt = 0.2;
	float t[Nsamples];
	float Xsaved[Nsamples];
	float Zsaved[Nsamples];
	float z, volt;
	
	for(int i=0;i<Nsamples;i++){
		t = i*dt;
		Xsaved[i] = 0.0;
		Zsaved[i] = 0.0;
	}

	for(i=0;i<Nsamples;i++){
		z = GetVolt();
		volt = SimpleKalman(z);
		printf("z-%f, volt-%f\n",z,volt);
	}
	return 0;
}
