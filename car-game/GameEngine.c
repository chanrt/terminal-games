#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ARROWKEYS 0xE0

#include<stdio.h>
#include<time.h>

void drawCar();
void accelerateCar();
void brakeCar();
void decelerateCar();
void driveCar();
int checkCar();
void showSpeed();
void eraseCar();
void carHit();
void createTrack();
void eraseTrack();
void generateTrack();


void gameLayout()
{
    drawBorder();
    createTrack();
    x = (track[1] + track[1] + 12) / 2;
    drawCar();
    drawTrack();
}

void gameLoop()
{
    int key, value;
    float delay_time;
    int hit_track;

    do
    {
        eraseTrack();

        gotoxy(x,y);
        printf(" ");

        if(y < 15 || speed > 20)
        {
            generateTrack();
        }
        else
        {
            y = y - speed*prec;
            if(speed < 0.01) speed = 0;
        }
        
        gotoxy(3,1);
        printf("Speed: %f",speed);

        drawTrack();

        if(checkCar())
        {
            if(speed > 0)
            {
                speed = speed - (0.5 * speed);
            }
        }
        else
        {
            if(speed > 0)
            {
                speed = speed - 0.1 * speed * prec;
                if(speed < 0) speed = 0;
            }
        }

        gotoxy(x,y);
        printf("A");

        if(speed == 0) delay(0.4);
        else if(speed <= 0.5) delay(0.25);
        else if(speed < 10) delay(0.1 / speed);
        else if(speed < 20) delay(0.05 / speed);
        else if(speed < 30) delay(0.01 / speed);
        else if(speed < 40) delay(0.005 / speed);
        else if(speed < 50) delay(0.001 / speed);
        else
        {

        }
    } while (!kbhit());

    key = getch();
    if(key == ARROWKEYS)
    {
        value = getch();
        if(value == LEFT)
        {
            eraseCar();
            x--;
            drawCar();
        }
        else if(value == RIGHT)
        {
            eraseCar();
            x++;
            drawCar();
        }
        else if(value == UP)
        {
            eraseCar();
            accelerateCar();
            drawCar();
        }
        else if(value == DOWN)
        {
            eraseCar();
            brakeCar();
            drawCar();
        }
    }
    
    gameLoop();
}