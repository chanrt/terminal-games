#include<stdio.h>

void makeWalls(int level)
{
    if(level == 2)
    {
        makeHorizontalWall(0,49,27,76,5);
        makeHorizontalWall(50,99,27,76,34);
        makeVerticalWall(100,127,6,33,27);
        makeVerticalWall(128,155,6,33,76);
    }

    if(level == 3)
    {
        makeVerticalWall(0,35,4,39,30);
        makeVerticalWall(36,71,4,39,74);
        makeVerticalWall(72,82,4,14,36);
        makeVerticalWall(83,93,4,14,68);
        makeVerticalWall(94,104,29,39,36);
        makeVerticalWall(105,115,29,39,68);

        makeHorizontalWall(116,128,37,49,14);
        makeHorizontalWall(129,141,55,67,14);
        makeHorizontalWall(142,154,37,49,29);
        makeHorizontalWall(155,167,55,67,29);
    }
}

void putWalls()
{
    for(int i = 0; i < numWalls; i++)
    {
        if(wall_x[i] != 0)
        {
            gotoxy(wall_x[i],wall_y[i]);
            printf("0");
        }
    }
}