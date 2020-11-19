#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#include"chan_graphics.c"

int x;
int y;

int bullet_x;
int bullet_y;

int no_missile;
int missile_x;
int missile_y;

int died;
int hp;
int score;

int no_enemies;
int *ai_x;
int *ai_y;
int *ai_speed;
int *ai_live;

void plotPlayer()
{
    if(!died)
    {
        gotoxy(x,y);
        printf("A");
    }
}

void createEnemies()
{
    int populatedIndex = 0;
    int new_x;

    ai_x = mallocIntArray(no_enemies);
    ai_y = mallocIntArray(no_enemies);
    ai_speed = mallocIntArray(no_enemies);
    ai_live = mallocIntArray(no_enemies);

    makeConstant(ai_speed,no_enemies,0);
    makeConstant(ai_x,no_enemies,0);
    makeConstant(ai_y,no_enemies,3);
    makeConstant(ai_live,no_enemies,1);

    srand(time(NULL));
    for(int i = 0; i < no_enemies; i++)
    {
        again:
        new_x = (rand() % 81) + 32;

        for(int i = 0; i < populatedIndex; i++)
        {
            if(ai_x[i] == new_x) goto again;
        }

        if(new_x < 32 || new_x > 81) goto again;
        else
        {
            populatedIndex++;
            ai_x[i] = new_x;
        }
    }
}

void plotEnemy()
{
    for(int i = 0; i < no_enemies; i++)
    {
        if(ai_live[i])
        {
            gotoxy(ai_x[i],ai_y[i]);
            printf("o");
        }
    }
}

void gamelayout()
{
    drawBorder();
    drawHorizontalLineAt(32,81,36);

    gotoxy(32,39);
    printf("Health: %3d",hp);

    plotPlayer();
    plotEnemy();
}

void init()
{
    x = (32 + 82) / 2;
    y = 37;

    no_enemies = 10;
    createEnemies();

    gamelayout();

    //for(int i = 0; i < no_enemies; i++) printf("%d ",ai_x[i]);
}

void contemplateMovement()
{
    int new_speed;
    int toBeMoved;

    srand(time(NULL));
    {
        for(int i = 0; i < no_enemies; i++)
        {
            if(ai_live[i])
            {
                again1:
                new_speed = (rand() % 2) + 0;

                if(new_speed > 2 || new_speed < 0) goto again1;
                else ai_speed[i] = new_speed;
            }
        }
    }
}

void clearEnemy()
{
    for(int i = 0; i < no_enemies; i++)
    {
        gotoxy(ai_x[i],ai_y[i]);
        printf(" ");
    }
}

void moveEnemy()
{
    for(int i = 0; i < no_enemies; i++)
    {
        if(ai_live[i]) ai_y[i] = ai_y[i] + ai_speed[i];
    }
}

void surveyDamage()
{
    for(int i = 0; i < no_enemies; i++)
    {
        if(ai_y[i] >= 36 && ai_speed[i] != -1)
        {
            ai_live[i] = 0;
            ai_x[i] = 0;
            ai_y[i] = 0;
            hp = hp - 10;

            gotoxy(32,39);
            printf("Health: %3d",hp);
        }
    }
}

void erasePlayer()
{
    gotoxy(x,y);
    printf(" ");
}

int checkFutureDamage()
{
    for(int i = 0; i < no_enemies; i++)
    {
        if(ai_x[i] == bullet_x)
        {
            return i;
        }
    }
    return 0;
}

void eraseBullet()
{
    gotoxy(bullet_x,bullet_y);
    printf(" ");
}

void displayBullet()
{
    gotoxy(bullet_x,bullet_y);
    printf("*");
}

void animateBullet(int y)
{
    while(bullet_y >= y)
    {
        eraseBullet();
        bullet_y = bullet_y - 1;
        displayBullet();
        delay(0.03);
    }
    eraseBullet();
}

void fire()
{
    int target = checkFutureDamage();

    if(target == 0)
    {
        animateBullet(3);
    }
    else
    {
        animateBullet(ai_y[target]);
        hp = hp + 10;
        ai_live[target] = 0;
        ai_x[target] = 0;
        ai_y[target] = 0;
    }
}

void checkGame()
{
    int a;
    if(hp == 0)
    {
        textMiddle("Game over!",5);
        textMiddle("1: New Game",8);
        textMiddle("2: Exit",10);
        textMiddle("Your choice: ",13);
        scanf("%d",&a);

        if(a == 1)
        {
            system("cls");
            hp = 100;
            init();
        }
        if(a == 2) exit(1);
    }

    int enemy_num = 0;
    for(int i = 0; i < no_enemies; i++)
    {
        if(ai_live[i]) enemy_num++;
    }

    if(enemy_num == 0)
    {
        textMiddle("Level complete!",5);
        textMiddle("1: Next level",8);
        textMiddle("2: Exit",10);
        textMiddle("Your choice: ",13);
        scanf("%d",&a);

        if(a == 1)
        {
            system("cls");
            init();
        }
        if(a == 2) exit(1);
    }
}

void clearMissile()
{
    gotoxy(missile_x,missile_y);
    printf(" ");
    gotoxy(missile_x,missile_y+1);
    printf(" ");
}

void displayMissile()
{
    if(missile_x != 0)
    {
        gotoxy(missile_x,missile_y);
        printf("^");
        gotoxy(missile_x,missile_y+1);
        printf("|");
    }
}

void clearCloud()
{
    int dist_x;
    int dist_y;
    for(int i = 32; i < 82; i++)
    {
        for(int j = 2; j < 36; j++)
        {
            dist_x = i - missile_x;

            if(dist_x < 0) dist_x = - dist_x;

            dist_y = j - missile_y;

            if(dist_y <  0) dist_y = - dist_y;

            if(dist_x + dist_y < 6)
            {
                gotoxy(i,j);
                printf(" ");
            }
        }
    }
}

void destructMissile()
{
    int dist_x;
    int dist_y;
    for(int i = 32; i < 82; i++)
    {
        for(int j = 2; j < 36; j++)
        {
            dist_x = i - missile_x;

            if(dist_x < 0) dist_x = - dist_x;

            dist_y = j - missile_y;

            if(dist_y <  0) dist_y = - dist_y;

            if(dist_x + dist_y < 6)
            {
                gotoxy(i,j);
                printf("*");

                for(int k = 0; k < no_enemies; k++)
                {
                    if(ai_x[k] == i && ai_y[k] == j) ai_live[k] = 0;
                }
            }
        }
    }

    delay(0.5);
    clearCloud();
}

void checkMissile()
{
    for(int i = 0; i < no_enemies; i++)
    {
        if(missile_x == ai_x[i] && (missile_y == ai_y[i] || missile_y + 1 == ai_y[i]))
        {
            ai_live[i] = 0;
        }
    }
}

void missileLoop()
{
    int key, value;

    do
    {
        clearMissile();
        missile_y--;

        if(missile_y <= 3)
        {
            destructMissile();
            return ;
        }
        checkMissile();
        displayMissile();

        delay(0.05);
    } while(!kbhit());

    key = getch();
    if(key == 0xE0)
    {
        value = getch();
        if(value == LEFT)
        {
            clearMissile();
            missile_x--;
            displayMissile();
        }
        if(value == RIGHT)
        {
            clearMissile();
            missile_x++;
            displayMissile();
        }
        if(value == DOWN)
        {
            destructMissile();
            return ;
        }
    }

    missileLoop();
}

void gameLoop()
{
    int key, value;

    do
    {
        clearEnemy();
        /*gotoxy(1,1);
        int a;
        for(int i = 0; i < no_enemies; i++) printf("%d %d %d %d\n",ai_x[i],ai_y[i],ai_speed[i],ai_live[i]);
        scanf("%d",&a);*/
        contemplateMovement();
        moveEnemy();       
        plotEnemy();
        gotoxy(1,1);
        surveyDamage();
        checkGame();

        delay(0.2);
    } while(!kbhit());

    key = getch();
    if(key == 0xE0)
    {
        value = getch();
        if(value == LEFT) 
        {
            erasePlayer();
            x--;
            if(x == 31) x = 81;
            plotPlayer();
        }
        if(value == RIGHT) 
        {
            erasePlayer();
            x++;
            if(x == 82) x = 32;
            plotPlayer();
        }
        if(value == UP)
        {
            bullet_x = x;
            bullet_y = 35;
            displayBullet();
            fire();
        }
        if(value == DOWN)
        {
            missile_x = x;
            missile_y = 34;
            displayMissile();
            missileLoop();
        }
    }
    gameLoop();
}

void main()
{
    no_missile = 3;
    hp = 100;
    init();
    gameLoop();
}