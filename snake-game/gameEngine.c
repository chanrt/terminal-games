#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void gameOverMenu();

void gameLayout()
{
    system("cls");

    drawBorder();
    drawHorizontalLine(3);
    putSnake();

    gotoxy(1,3);
    printf("+");
    gotoxy(110,3);
    printf("+");

    putWalls();

    gotoxy(2,2);
    printf("Game starts in 2 seconds");
    delay(2);
    wipeLine(2);

    if(isArcade)
    {
        gotoxy(2,2);
        printf("Level: %d\tTarget: %d",level, goal);
        gotoxy(75,2);
        if(level == 1) printf("Level name: Classic");
        else if(level == 2) printf("Level: Box");
    }
    else
    {
        gotoxy(2,2);
        printf("FreeStyle Mode");
    }

    gotoxy(45,2);
    printf("Snake length: %d",length);
}

void gameLoop()
{
    int key, value;

    do
    {
        EraseSnake();
        MoveSnake();

        if(foodStep == 3)
        {
            foodSpawn();
        }
        if(foodStep == 75)
        {
            foodDespawn();
        }
        if(gameStep == 5)
        {
            gameStep = 0;
            delay_time = delay_time - ( 0.1 * delay_time);
        }
        gameOver = checkSnake();
        if(gameOver) gameOverMenu();

        foodStep++;
        gameTime++;

        putSnake();

        delay(delay_time);
    } while(!kbhit());

    key = getch();

    if(key == 0xE0)
    {
        value = getch();

        if(value == UP && dir[0] != 2) dir[0] = 1;
        else if(value == DOWN && dir[0] != 1) dir[0] = 2;
        else if(value == LEFT && dir[0] != 4) dir[0] = 3;
        else if(value == RIGHT && dir[0] != 3) dir[0] = 4;
    }

    gameLoop();
}