#include<stdio.h>
#include<stdlib.h>

#include"chan_graphics.c"
#include"chan_init.c"
#include"chan_misc.c"

int x,y;
float speed;
float accn;
float road_decn;
float prec;

#include"RaceTrack.c"
#include"GameEngine.c"

void carHit()
{
    if(speed > 0)
    {
        speed = speed - (0.5 * speed);
    }
}

void showSpeed()
{
    gotoxy(3,1);
    printf("Speed: %f",speed);
}

void driveCar()
{
    y = y - speed*prec;
    if(speed < 0.01) speed = 0;
}

void decelerateCar()
{
    if(speed > 0)
    {
        speed = speed + road_decn*prec;
        if(speed < 0) speed = 0;
    }
}

void reverseCar()
{
    y++;
}

void brakeCar()
{
    if(speed > 0)
    {
        speed = speed - 0.25 * speed;
        if(speed < 0.05)
        {
            speed = 0;
        }
        if(speed < 0) speed = 0;
    }
    else reverseCar();
}

void accelerateCar()
{
    speed = speed + accn * prec;
}

void drawCar()
{
    gotoxy(x,y);
    printf("A");
}

void eraseCar()
{
    gotoxy(x,y);
    printf(" ");
}

void init()
{
    y = 38;
    speed = 0;
    prec = 0.1;

    accn = 8;
    road_decn = - 0.2;

    gameLayout();
}

void main()
{
    init();
    gameLoop();
}