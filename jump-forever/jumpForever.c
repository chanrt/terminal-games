#define JUMP 72

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int x,y;
int fall, platform, new_ground;
int *b, *old;

#include"chan_init.c"
#include"chan_graphics.c"
#include"dynamics.c"
#include"gameEngine.c"

void init()
{
    b = mallocIntArray(108);
    b = makeConstant(b, 108, 21);
    old = mallocIntArray(108);

    x = 5;
    y = 20;
    fall = 0;
    platform = 0;
    new_ground = 0;

    gameLayout();
}

void main()
{
    init();
    gameLoop();
}