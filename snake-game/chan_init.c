#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

void makeHorizontalConstant(int n1, int n2, int y)
{
    for(int i = n1; i <= n2; i++)
    {
        wall_y[i] = y;
    }
}

void makeVerticalConstant(int n1, int n2, int x)
{
    for(int i = n1; i <= n2; i++)
    {
        wall_x[i] = x;
    }
}

void makeHorizontalWall(int start_index, int end_index, int x_start, int x_end, int y)
{
    for(int i = start_index; i <= end_index && x_start <= x_end ; i++, x_start++)
    {
        wall_x[i] = x_start;
    }
    makeHorizontalConstant(start_index, end_index, y);
}

void makeVerticalWall(int start_index, int end_index, int y_start, int y_end, int x)
{
    for(int i = start_index; i <= end_index && y_start <= y_end ; i++, y_start++)
    {
        wall_y[i] = y_start;
    }
    makeVerticalConstant(start_index, end_index, x);
}