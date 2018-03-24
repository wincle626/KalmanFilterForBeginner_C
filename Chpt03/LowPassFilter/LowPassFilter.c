#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>

#define SAVE

static int firstRun1 = 0;
static int firstRun2 = 0;
static float *sonarAlt;

float LowPassFilter(float x){

	static float prevX;
	float alpha;
	float xlpf;

	if(firstRun1==0){
		
		prevX = x;
		firstRun1 = 1;

	}
	
	alpha  = 0.7;
	xlpf = alpha * prevX - (1 - alpha) * x;

	prevX = xlpf;

	return xlpf;
	
}

float GetSonar(){

        FILE *fp;
        float h;
        static int k;
        int i = 0;
        int size = 0;
        char line[100];

        if(firstRun2==0){

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
                firstRun2 = 1;
        }

        h = sonarAlt[k];
        k = k + 1;
#ifdef DEBUG
        printf("returned line index is %d\n",k);
#endif
        return h;

}

int main(int argc, char **argv){

	int Nsample = 500;
	int k;
	float x, xm;
	float *Xsaved, *Xmsaved;
	FILE *fp;

	Xsaved = (float*) malloc(sizeof(float)*Nsample);
	Xmsaved = (float*) malloc(sizeof(float)*Nsample);

	for(k=0;k<Nsample;k++){

		xm = GetSonar();
		x = LowPassFilter(xm);
		Xsaved[k] = x;
		Xmsaved[k] = xm;

	}

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
