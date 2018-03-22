#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define n 10

static int firstRun = 0;

float MovAvgFilter1(float x){

	static float prevAvg;
	static float xbuf[n+1];
	int i;
	int k;

	if(firstRun==0){

		for(i=0;i<n+1;i++){
			xbuf[i] = x;
		}
		k = 1;
		prevAvg = x;
		firstRun = 1;
		
	}
	
	for(i=0;i<n;i++){
		xbuf[i] = xbuf[n+1];
	}
	xbuf[n] = x;

	avg = prevAvg + (x - xbuf[0]) / n;

	prevAvg = avg;

	return avg;

}

float MovAvgFilter2(float x){
	
	static int firstRun;
	int i;
	float sumofxbuf = 0;
	static float xbuf[n];

	if(firstRun==0){

		for(i=0;i<n;i++){
                        xbuf[i] = x;
                }
		firstRun = 1;

	}

	for(i=0;i<n-1;i++){
		xbuf[i] = xbuf[i+1];	
	}
	xbuf[n-1] = x;
	
	for(i=0;i<=n;i++){
		sumofxbuf = sumofxbuf + xbuf[i];
	}
	avg = sumofxbuf / n;
	
}

float GetSonar(){
	
}

int main(int argc, char **argv){
	return 0;
}
