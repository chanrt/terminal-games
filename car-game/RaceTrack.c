#include<stdio.h>

int *track;

void createTrack()
{
    track = mallocIntArray(38);

    track[0] = 52;
    int new_x;

    srand(time(NULL));
    for(int i = 1; i < 38; i++)
    {
        again1:
        new_x = (rand() % 3) + 1;
        
        if(new_x == 1 && track[i-1] > 2) track[i] = track[i-1] - 1;
        else if(new_x == 2) track[i] = track[i-1];
        else if(new_x == 3 && (track[i-1] + 18) < 109) track[i] = track[i-1] + 1;
        else goto again1;
    }
}

void drawTrack()
{
    for(int i = 0; i < 38; ++i)
    {
        gotoxy(track[i], 39 - i);
        printf("*");
        gotoxy(track[i] + 18, 39 - i);
        printf("*");
    }
}

void eraseTrack()
{
    for(int i = 0; i < 38; ++i)
    {
        gotoxy(track[i], 39 - i);
        printf(" ");
        gotoxy(track[i] + 18, 39 - i);
        printf(" ");
    }
}

void generateTrack()
{
    int new_x;
    for(int i = 0; i < 38; ++i)
    {
        track[i] = track[i+1];
    }

    again2:
    new_x = (rand() % 3) + 1;

    if(new_x == 1 && track[36] > 2) track[37] = track[36] - 1;
    else if(new_x == 2) track[37] = track[36];
    else if(new_x == 3 && (track[36] + 18) < 109) track[37] = track[36] + 1;
    else goto again2;
}

int checkCar()
{
    if(x < track[39-y] + 1)
    {
        x = track[39-y] + 1;
        return 1;
    }
    else if(x >= track[39-y] + 18)
    {
        x = track[39-y] + 17;
        return 1;
    }
    return 0;
}