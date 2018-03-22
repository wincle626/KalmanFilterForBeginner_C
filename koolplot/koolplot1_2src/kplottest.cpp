#include "koolplot.h"

int main()
{
    Plotdata x(0, 1);
    Plotdata y = -0.5 * x + 78;
    plot(x, y);
    return 0;
}

