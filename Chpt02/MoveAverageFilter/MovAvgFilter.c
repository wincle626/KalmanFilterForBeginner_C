#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <graphics.h>

//#define DEBUG
#define SAVE
#define n 10

static int firstRun1 = 0;
static int firstRun2 = 0;
static int firstRun3 = 0;
static float *sonarAlt;

float MovAvgFilter1(float x){

#ifdef DEBUG
	printf("enter function %s\n",__func__);
#endif
	static float prevAvg;
	static float xbuf[n+1];
	float avg;
	int i;
	int k;

	if(firstRun1==0){

		for(i=0;i<n+1;i++){
			xbuf[i] = x;
		}
		k = 1;
		prevAvg = x;
		firstRun1 = 1;
		
#ifdef DEBUG
	printf("initialization finished\n");
#endif
	}
	
	for(i=0;i<n;i++){
		xbuf[i] = xbuf[i+1];
	}
	xbuf[n] = x;
#ifdef DEBUG
	printf("shifted\n");
#endif
	avg = prevAvg + (x - xbuf[0]) / n;

	prevAvg = avg;

#ifdef DEBUG
	printf("exit function %s\n",__func__);
#endif
	return avg;

}

float MovAvgFilter2(float x){
	
	int i;
	float sumofxbuf = 0;
	static float xbuf[n];
	float avg;

	if(firstRun2==0){

		for(i=0;i<n;i++){
                        xbuf[i] = x;
                }
		firstRun2 = 1;

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
	
	FILE *fp;
	float h;
	static int k;
	int i = 0;
	int size = 0;
	char line[100];

	if(firstRun3==0){

		fp = fopen("SonarAlt.txt","r");
		while(fgets(line,sizeof(line),fp)!=NULL){
			size = size + 1;	
		}
		fclose(fp);
#ifdef DEBUG
	printf("total line number is %d\n",size);
#endif
		
		sonarAlt = (float *) malloc(sizeof(float)*size);
		fp = fopen("SonarAlt.txt","r");
		while(fgets(line,sizeof(line),fp)!=NULL){
			sonarAlt[i] = (float) atof(line);
			i  = i + 1;
#ifdef DEBUG
	printf("current line index is %d\n",i);
#endif
		}
		fclose(fp);
		
		k = 0;
		firstRun3 = 1;
	}
	
	h = sonarAlt[k];
	k = k + 1;
#ifdef DEBUG
	printf("returned line index is %d\n",k);
#endif
	return h;

}

int main(int argc, char **argv){
	
	int k;
	int Nsample = 500;
	float x;
	float xm;
	float *Xsaved;
	float *Xmsaved;
	FILE *fp;

	Xsaved = (float *) malloc(sizeof(float)*Nsample);
	Xmsaved = (float *) malloc(sizeof(float)*Nsample);
	for(k=0;k<Nsample;k++){

		xm = GetSonar();
		x = MovAvgFilter1(xm);
		Xsaved[k] = x;
		Xmsaved[k] = xm;

	}

#ifdef DEBUG
	for(k=0;k<Nsample;k++){
		printf("%dth input:%f,  output: %f\n", k, Xmsaved[k], Xsaved[k]);		
	}
#endif

#ifdef SAVE
	fp = fopen("Xmsaved.txt","a+");
	for(k=0;k<Nsample;k++){
		fprintf(fp,"%f\n",Xmsaved[k]);
	}
	fclose(fp);
	fp = fopen("Xsaved.txt","a+");
	for(k=0;k<Nsample;k++){
		fprintf(fp,"%f\n",Xsaved[k]);
	}
	fclose(fp);
#endif
	
	return 0;
}
