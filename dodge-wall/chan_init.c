#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// module 1: input functions

int takeInt()
{
    int n;
    scanf("%d",&n);
    return n;
}

float takeFloat()
{
    float f;
    scanf("%f",&f);
    return f;
}

char takeChar()
{
    char c;
    scanf("%c",&c);
    return c;
}

long takeLong()
{
    long n;
    scanf("%d",&n);
    return n;
}

double takeDouble()
{
    double n;
    scanf("%lf",&n);
    return n;
}

char *takeWord(int size)
{
    char *word = (char *) malloc((size + 1)*sizeof(char));
    scanf("%s",word);
    return word;
}

// module 2: malloc functions

int *mallocIntArray(int size)
{
    int *array = (int *) malloc(size*sizeof(int));
    return array;
}

float *mallocFloatArray(int size)
{
    float *array = (float *) malloc(size*sizeof(float));
    return array;
}

char *mallocString(int size)
{
    char *array = (char *) malloc((size + 1)*sizeof(char));
    return array;
}

// module 3: operations on integer arrays

int findMin(int *array, int size)
{
    int temp_min = INT_MAX;
    for(int i = 0; i < size; i++)
    {
        if(array[i] < temp_min) temp_min = array[i];
    }
    return temp_min;
}

int findMax(int *array, int size)
{
    int temp_max = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        if(array[i] > temp_max) temp_max = array[i];
    }
    return temp_max;
}

int *reverseIntArray(int *array, int size)
{
    int *reversed_array = mallocIntArray(size);
    int back_index = (--size);

    for(int i = 0; i < size; i++, back_index--) reversed_array[back_index] = array[i];
    return reversed_array;
}

int *makeConstant(int *array, int size, int k)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = k;
    }
    return array;
}

int isSorted(int *array, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        if(array[i] < array[i+1]) return 0;
    }
    return 1;
}

