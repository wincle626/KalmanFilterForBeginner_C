#include "koolplot.h"

int main()
{
	Plotdata	x(-360, 360), y = sin(x) + 3*x;
	plot(x, y); 
	return 0;
}

