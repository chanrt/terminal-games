#include<stdio.h>
#include<time.h>

void delay(float n_seconds)
{
    int milli = 1000 * n_seconds;

    clock_t start = clock();

    while(clock() < start + milli);
}

