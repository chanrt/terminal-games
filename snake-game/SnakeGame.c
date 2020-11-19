#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int isArcade, level, goal, numWalls;

int gameOver, gameTime, gameStep;
int length;
float delay_time;

int *x, *y, *dir;
int *wall_x, *wall_y;

int food_x, food_y;
int fx1, fx2, fy1, fy2;
int foodStep, foodSpawned;

#include"chan_init.c"
#include"chan_graphics.c"
#include"levels.c"
#include"snake.c"
#include"food.c"
#include"gameEngine.c"

void gameOverMenu();

void init()
{
    x = mallocIntArray(1000);
    y = mallocIntArray(1000);
    dir = mallocIntArray(1000);

    makeConstant(x, 1000, 0);
    makeConstant(y, 1000, 0);
    makeConstant(dir, 1000, 0);

    length = 5;
    delay_time = 0.15;
    gameStep = 0;
    gameTime = 0;

    int start_x, start_y, start_dir;

    srand(time(NULL));
    if(!isArcade)
    {
        start_x = (rand() % 90) + 20;
        start_y = (rand() % 25) + 15;
        numWalls = 0;

        fx1 = 3;
        fx2 = 107;

        fy1 = 5;
        fy2 = 37;
    
        if(start_x > 90) start_dir = 3;
        else if(start_x < 10) start_dir = 4;
        else if(start_y > 25) start_dir = 1;
        else if(start_dir < 15) start_dir = 2;
        else start_dir = (rand() % 4) + 1;
    }
    else
    {
        if(level == 1)
        {   
            // actual level 1:

            start_x = 60;
            start_y = 15;
            numWalls = 0;

            fx1 = 3;
            fx2 = 107;

            fy1 = 5;
            fy2 = 37;

            start_dir = (rand() % 4) + 1;
            goal = 20;

            //test area: 

        }
        else if(level == 2)
        {
            start_x = 60;
            start_y = 15;
            numWalls = 156;

            fx1 = 28;
            fx2 = 75;

            fy1 = 6;
            fy2 = 33;

            wall_x = mallocIntArray(numWalls);
            wall_y = mallocIntArray(numWalls);

            makeWalls(2);

            start_dir = (rand() % 4) + 1;
            goal = 20;
        }
        else if(level == 3)
        {
            start_x = 60;
            start_y = 25;
            numWalls = 168;

            fx1 = 31;
            fx2 = 73;

            fy1 = 4;
            fy2 = 39;

            wall_x = mallocIntArray(numWalls);
            wall_y = mallocIntArray(numWalls);

            makeConstant(wall_x,numWalls,0);
            makeConstant(wall_y,numWalls,0);

            makeWalls(3);

            start_dir = (rand() % 4) + 1;
            goal = 20;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        x[i] = start_x;
        y[i] = start_y;
        dir[i] = start_dir;

        if(start_dir == 1) start_y++;
        else if(start_dir == 2) start_y--;
        else if(start_dir == 3) start_x++;
        else start_x--;
    }

    gameLayout();
}

void about()
{

}

void nextLevelMenu()
{
    int a;

    gotoxy(3,5);
    printf("Level complete!");
    gotoxy(3,8);
    printf("1: Next level");
    gotoxy(3,10);
    printf("2: Restart level");
    gotoxy(3,12);
    printf("3: Restart game");
    gotoxy(3,14);
    printf("4: Main menu");
    gotoxy(3,16);
    printf("5: Exit");
    gotoxy(3,19);
    printf("Your choice: ");
    scanf("%d",&a);

    if(a == 1) 
    {
        level++;
        init();
    }
}

void gameOverMenu()
{
    int a;

    gotoxy(3,5);
    printf("Game over!");
    gotoxy(3,8);
    printf("1: Play again");
    gotoxy(3,10);
    printf("2: Main Menu");
    gotoxy(3,12);
    printf("3: Exit");
    gotoxy(3,15);
    printf("Your choice: ");
    scanf("%d",&a);

    if(a == 1)
    {
        wipeScreen();
        level = 1;
        init();
        gameLoop();
    }
    else exit(1);
}

void menu()
{
    int a;
    system("cls");
    drawBorder();

    textMiddle("The Classic Snake game",10);
    textMiddle("1: Play Arcade mode",13);
    textMiddle("2: Play FreeStyle",15);
    textMiddle("3: About",17);
    textMiddle("4: Quit",19);
    textMiddle("Your choice: ",22);
    scanf("%d",&a);

    if(a == 2)
    {
        isArcade = 0;
        level = 0;
    }
    else if(a == 1)
    {
        isArcade = 1;
        level = 1;
    }
    else if(a == 3) about();
    else exit(1);
}

void main()
{
    menu();
    init();
    gameLoop();
}

