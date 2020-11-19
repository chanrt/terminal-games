#include<stdio.h>

void init();
void nextLevelMenu();

void growth()
{
    if(dir[length - 1] == 1)
    {
        x[length] = x[length - 1];
        y[length] = y[length - 1] + 1;
        dir[length] = 1;
    }
    if(dir[length - 1] == 2)
    {
        x[length] = x[length - 1];
        y[length] = y[length - 1] - 1;
        dir[length] = 2;
    }
    if(dir[length - 1] == 3)
    {
        x[length] = x[length - 1] + 1;
        y[length] = y[length - 1];
        dir[length] = 3;
    }
    if(dir[length - 1] == 4)
    {
        x[length] = x[length - 1] - 1;
        y[length] = y[length - 1];
        dir[length] = 4;
    }
    length++;
    gameStep++;

    gotoxy(45,2);
    printf("Snake length: %d",length);
    if(isArcade && length == goal) nextLevelMenu();
}

void EraseSnake()
{
    for(int i = 0; i < length; i++)
    {
        gotoxy(x[i],y[i]);
        printf(" ");
    }
}

void MoveSnake()
{
    int prev_dir = dir[0];
    int temp_dir;

    for(int i = 0; i < length; i++)
    {
        if(dir[i] == 1) y[i]--;
        else if(dir[i] == 2) y[i]++;
        else if(dir[i] == 3) x[i]--;
        else x[i]++;

        if(dir[i] != prev_dir)
        {
            temp_dir = dir[i];
            dir[i] = prev_dir;
            prev_dir = temp_dir;
        }
        else prev_dir = dir[i];
    }

    if(x[0] == food_x && y[0] == food_y && foodSpawned == 1)
    {
        foodSpawned = 0;
        foodStep = 0;
        growth();
    }
}

void putSnake()
{
    for(int i = 0; i < length; i++)
    {
        if(x[i] > 109) x[i] = 2;
        if(x[i] < 1) x[i] = 109;
        if(y[i] > 39) y[i] = 4;
        if(y[i] < 4) y[i] = 39;

        if(i == 0)
        {
            gotoxy(x[0],y[0]);
            if(dir[0] == 1) printf("^");
            else if(dir[0] == 2) printf("v");
            else if(dir[0] == 3) printf("<");
            else printf(">");
        }
        else
        {
            gotoxy(x[i],y[i]);
            printf("*");
        }
    }

    if(foodSpawned == 1)
    {
        gotoxy(food_x, food_y);
        printf("o");
    }
}

int checkSnake()
{
    for(int i = 1; i < length; i++)
    {
        if(x[0] == x[i])
        {
            if(y[0] == y[i])
                return 1;
        }
    }

    for(int i = 0; i < numWalls; i++)
    {
        if(wall_x[i] == x[0])
        {
            if(wall_y[i] == y[0]) return 1;
        }
    }

    return 0;
}