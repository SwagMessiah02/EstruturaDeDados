#include <stdio.h>
#include "printers.h"

void print_int(const int *a)
{
    printf("%d ", *a);
}

void print_char(const char *a)
{
    printf("%c ", *a);
}

void print_string(const char *s)
{
    printf("%s ", s);
}
