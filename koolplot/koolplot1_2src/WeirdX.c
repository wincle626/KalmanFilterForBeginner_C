/*
 * File: WeirdX.c                    
 * -------------
 * This files demonstrates some uses of the koolplot library.
 *
 * How to: 
 * - draw data points on graphs with "addMark()" 
 *     and 
 * How to: 
 * - control the axes range with axesBotLeft() and axesTopRight()
 */

#include <koolplot.h>

int main()
{
    int i, j;    
    const char * header = "WeirdX: "; 
    
    /* Declare and define x and y axes */
    /* String holding graph window title */
    char winTitle[120];
    
    /* Define plot data. Y is a weird and wonderful function  */
    plotdata x(-16, 16),
             y = sin(x * x) * exp((x * x) / (2 * cosh(x / 2.4)));

    /* Extend y axis range to +24 -24 */
    axesBotLeft (x, y, -16,  -24);
    axesTopRight(x, y,  16, 24); 

    /* Add a few dummy data points to graph */
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            addMark(x, y, -12 + 12 * i, -16 + 16 * j); 
             
    /* Build the window title string */
    sprintf(winTitle, "%s a koolplot demo.", header);
    
    /* Plot now, you beauty! */
    plot (x, y, winTitle);

    return 0;    
}


