#include "koolplot.h"

int main()
{
    plotdata x(-6, 6);
    plotdata y = sin(x) + x/5;
    plot(x, y);
    return 0;
}
