#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define ARROWKEYS 0xE0

#include<stdio.h>
#include<windows.h>

void drawPlayer();
void clearPlayer();
void createWalls();
void displayWalls();
void clearWalls();
void moveWalls();
void checkWalls();
void checkPlayer();

void gameLayout()
{
    system("cls");
    drawBorder();
    drawPlayer();
    createWalls();
    displayWalls();
}

void gameLoop()
{
    int key, value;

    do
    {
        clearWalls();
        moveWalls();
        checkWalls();
        displayWalls();
        checkPlayer();

        if(num_dodged >= 80) delay_time = 0.02;
        else if(num_dodged >= 60) delay_time = 0.04;
        else if(num_dodged >= 40) delay_time = 0.06;
        else if(num_dodged >= 20) delay_time = 0.08;

        delay(delay_time);
    } while(!kbhit());

    key = getch();
    if(key == ARROWKEYS)
    {
        value = getch();
        if(value == LEFT && x > 51)
        {
            clearPlayer();
            x--;
            drawPlayer();
        }
        else if(value == RIGHT && x < 60)
        {
            clearPlayer();
            x++;
            drawPlayer();
        }
    }

    gameLoop();
}