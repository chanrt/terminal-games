#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int x;
// player x ranges from 51 to 60
// player y is 38

int *wall_buffer;
int *wall_opaque;
int *wall_layer;
int num_dodged;
float delay_time;

#include"chan_graphics.c"
#include"chan_misc.c"
#include"chan_init.c"

#include"gameEngine.c"
#include"walls.c"

void main();

void drawPlayer()
{
    gotoxy(x, 38);
    printf("A");
}

void clearPlayer()
{
    gotoxy(x, 38);
    printf(" ");
}

void init()
{
    delay_time = 0.1;
    num_dodged = 0;
    printf("Dodge the Wall!");
    x = 55;

    wall_buffer = mallocIntArray(30);
    wall_opaque = mallocIntArray(6);
    wall_layer = mallocIntArray(6);

    wall_layer[0] = 33;
    wall_layer[1] = 27;
    wall_layer[2] = 21;
    wall_layer[3] = 15;
    wall_layer[4] = 9;
    wall_layer[5] = 3;

    gameLayout();

    gotoxy(1,1);
    printf("Game starts in 2 seconds");
    delay(2);
    
    for(int i = 0; i < 30; i++)
    {
        gotoxy(i, 1);
        printf(" ");
    }

    gameLoop();
}

void gameOver()
{
    int a;
    gotoxy(3,1);
    printf("Game Over!");
    printf("\n\n\n1: Play again");
    printf("\n\n2: Exit",9);
    printf("\n\n\nYour choice: ");
    scanf("%d",&a);

    if(a == 1)
    {
        x = 55;
        delay_time = 0.1;
        num_dodged = 0;

        wall_layer[0] = 33;
        wall_layer[1] = 27;
        wall_layer[2] = 21;
        wall_layer[3] = 15;
        wall_layer[4] = 9;
        wall_layer[5] = 3;

        gameLayout();

        gotoxy(1,1);
        printf("Game starts in 2 seconds");
        delay(2);
    
        for(int i = 0; i < 30; i++)
        {
            gotoxy(i, 1);
            printf(" ");
        }

        gameLoop();
    }
    else exit(1);
}

void main()
{
    init();
    gameLoop();
}

