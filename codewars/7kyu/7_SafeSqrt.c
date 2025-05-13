#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

char *safeSqrt (double x)
{
    char* r = malloc(1005);
    if(x < 0){
        sprintf(r, "%s", "invalid input");
    }else {
        sprintf(r, "%.1f", sqrt(x));
    }

    return r;
}
