#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float x, y, vx, vy;
int bar_x, paralysed, lives;
int abar_x, ai_play, atarget, targetCalc, predictCalc, predict;
int p_score, a_score;

#include"chan_init.c"
#include"chan_graphics.c"
#include"bar.c"
#include"ball.c"
#include"ai.c"
#include"gameEngine.c"

void init()
{
    lives = 3;
    bar_x = 55;
    paralysed = 0;

    abar_x = 55;
    ai_play = 0;
    atarget = 0;
    targetCalc = 0;

    p_score = 0;
    a_score = 0;
    
    gameLayout();
}

void main()
{
    init();
    gameLoop();
}

void pause()
{
    int a;
    if(y >= 20)
    {
        textMiddle("Game paused",8);
        textMiddle("Enter any number to continue: ",10);
        scanf("%d",&a);
        wipeLine(8);
        wipeLine(10);
    }
    else
    {
        textMiddle("Game puased",28);
        textMiddle("Enter any number to continue: ",30);
        scanf("%d",&a);
        wipeLine(28);
        wipeLine(30);
    }
}

void about()
{
    int a;
    if(y >= 20)
    {
        textMiddle("---> Ball Bounce <---",10);
        textMiddle("Coded by Chandan RT",12);
        textMiddle("Enter any number to continue: ",18);
        scanf("%d",&a);
        wipeLine(10);
        wipeLine(12);
        wipeLine(18);
    }
    else
    {
        textMiddle("---> Ball Bounce <---",25);
        textMiddle("Coded by Chandan RT",27);
        textMiddle("Enter any number to continue: ",33);
        scanf("%d",&a);
        wipeLine(25);
        wipeLine(27);
        wipeLine(33);
    }
}