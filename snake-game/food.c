#include<stdio.h>
#include<time.h>

void foodDespawn()
{
    gotoxy(food_x,food_y);
    printf(" ");
    foodStep = 0;
    foodSpawned = 0;
}

void foodSpawn()
{
    again:
    srand(time(NULL));
    food_x = (rand() % fx2) + fx1;
    food_y = (rand() % fy2) + fy1;

    for(int i = 0; i < length; i++)
    {
        if(food_x == x[i] && food_y == y[i])
        {
            goto again;
        }
    }

    for(int i = 0; i < numWalls; i++)
    {
        if(food_x == wall_x[i])
        {
            if(food_y == wall_y[i]) goto again;
        }
    }

    if(food_x > fx2)
    {
        food_x = (rand() % fx2) + fx1;
        if(food_x > fx2) food_x = fx2;
    }
    if(food_y > fy2)
    {
        food_y = (rand() % fy2) + fy1;
        if(food_y > fy2) food_y = fy2;
    }
    foodSpawned = 1;
}