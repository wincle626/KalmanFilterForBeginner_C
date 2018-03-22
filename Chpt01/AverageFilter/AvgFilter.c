#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//#define DEBUG

static int firstrun = 0;

float AvgFilter(float x){
	
	static int k;
	static float prevavg;
	float alpha, avg;

	if(firstrun==0){

		k = 1;
		prevavg = 0;

		firstrun = 1;

	}

	alpha = (k - 1) / k;
	avg = alpha * prevavg + (1 - alpha) * x;

	prevavg = avg;
	k = k + 1;
#ifdef DEBUG
	printf("k=%d, prevavg=%f, avg=%f \n",k, prevavg, avg);
#endif

	return avg;

}

float GetVolt(){
	
	unsigned int randval;
	FILE *f;
	f = fopen("/dev/random", "r");
	fread(&randval, sizeof(randval), 1, f);
	fclose(f);
	float w = 0 + 4 * ((float)((int)randval % 1000) / 1000);
	float z = 14.4 + w;
#ifdef DEBUG
	printf("randval=%u, w=%f, z=%f\n", randval, w, z);
#endif
	return z;

}

int main(int argc, char **argv){
	
	int i;
	int Nsample = 100;
	float t[100];
	float Xmsaved[100];
	float Avgsaved[100];

	t[0] = 0.0;
	Xmsaved[0] = GetVolt();
	for(i=1;i<100;i++){

		t[i] = t[i-1] + 0.2;
		Xmsaved[i] = GetVolt();

	}	
	
	for(i=0;i<100;i++){
		
		Avgsaved[i] = AvgFilter(Xmsaved[i]);

	}

#ifdef DEBUG
	for(i=0;i<100;i++){
		
		printf("%dth input=%f, output=%f\n", i, Xmsaved[i], Avgsaved[i]);

	}
#endif	
	return 0;
}
