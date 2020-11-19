#include<stdio.h>
#include<time.h>

// walls at y = 33, 27, 21, 15, 9, 3

void gameOver();

void createWalls()
{
    int new_x;
    srand(time(NULL));
    for(int i = 0; i < 6; i++)
    {
        again1:
        new_x = (rand() % 59) + 51;
        if(new_x > 59 || new_x < 51) goto again1;
        else
        {
            wall_opaque[i] = new_x;
        }  
    }

    srand(time(NULL));
    for(int i = 0; i < 31; i++)
    {
        again2:
        new_x = (rand() % 59) + 51;
        if(new_x > 59 || new_x < 51) goto again2;
        else
        {
            wall_buffer[i] = new_x;
        }  
    }
}

void displayWalls()
{
    for(int i = 0; i < 6; i++)
    {
        gotoxy(wall_opaque[i], wall_layer[0]);
        printf("*");
    }

    for(int i = 1; i < 6; i++)
    {
        for(int j = (i - 1) * 6; j < (i - 1) * 6 + 6; j++)
        {
            gotoxy(wall_buffer[j], wall_layer[i]);
            printf("*");
        }
    }
}

void clearWalls()
{
    for(int i = 0; i < 6; i++)
    {
        gotoxy(wall_opaque[i], wall_layer[0]);
        printf(" ");
    }

    for(int i = 1; i < 6; i++)
    {
        for(int j = (i - 1) * 6; j < (i - 1) * 6 + 6; j++)
        {
            gotoxy(wall_buffer[j], wall_layer[i]);
            printf(" ");
        }
    }
}

void moveWalls()
{
    for(int i = 0; i < 6; i++)
    {
        wall_layer[i] = wall_layer[i] + 1;
    }
}

void checkWalls()
{
    if(wall_layer[0] == 39)
    {
        //gotoxy(1,1);
        //printf("New layer");

        num_dodged++;

        for(int i = 0; i < 5; i++)
        {
            wall_layer[i] = wall_layer[i+1];
        }
        wall_layer[5] = 3;
        for(int j = 0; j < 6; j++)
        {
            wall_opaque[j] = wall_buffer[j];
        }
        for(int k = 0; k < 24; k++)
        {
            wall_buffer[k] = wall_buffer[k+6];
        }

        int new_x;
        srand(time(NULL));

        for(int l = 25; l < 31; l++)
        {
            again3:
            new_x = (rand() % 59) + 51;
            if(new_x > 59 || new_x < 51) goto again3;
            else
            {
                wall_buffer[l] = new_x;
            }  
        }
    }
}

void checkPlayer()
{
    if(wall_layer[0] == 38)
    {
        for(int i = 0; i < 6; i++)
        {
            if(wall_opaque[i] == x) gameOver();
        }
    }
}