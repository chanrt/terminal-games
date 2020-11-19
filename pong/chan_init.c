#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int *makeConstant(int *array, int size, int k)
{
    for(int i = 0; i < size; i++) array[i] = k;

    return array;
}

int *mallocIntArray(int size)
{
    int *array = (int *) malloc(size*sizeof(int));
    return array;
}

void delay(float n_seconds)
{
    int milli = 1000 * n_seconds;

    clock_t start = clock();

    while(clock() < start + milli);
}

void beep()
{
    
}