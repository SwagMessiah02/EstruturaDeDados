#include <stdlib.h>
#include "comparators.h"

int comp_int(const int *a, const int *b)
{
    if(*a > *b)
        return 1;
    else if(*a < *b)
        return -1;
    else
        return 0;
}

int comp_char(const char *a, const char *b)
{
    const int c1 = (int)*a, c2 = (int)*b;

    if(c1 > c2)
        return 1;
    else if(c1 < c2)
        return -1;
    else
        return 0;
}

int comp_string(const char *a, const char *b)
{
    const double v1 = atof(a), v2 = atof(b);

    if(v1 < v2)
        return 1;
    else if(v1 > v2)
        return -1;
    else
        return 0;
}

