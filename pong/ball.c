int checkSpan(float x);
int acheckSpan();
void displayScores();
void putBall();

void makeBall()
{
    int dir;
    srand(time(NULL));
    again1:
    x = (rand() % 90) + 20;
    y = 20;
    dir = (rand() % 3) + 0;
    if(dir == 0)
    {
        ai_play = 1;
        vy = -0.5;
        targetCalc = 0;
        predictCalc = 1;
    }
    else
    {
        ai_play = 0;
        targetCalc = 0;
        predictCalc = 0;
        vy = 0.5;
    }


    if(x > 90 || x < 20) goto again1;

    if(x > 40 && x < 70)
    {
        vx = (rand() % 2) + 1;
        if(vx == 2) vx = -0.5;
        else vx = 0.5;
    }
    else if(x < 40) vx = 0.5;
    else vx = -0.5;

    gotoxy(x, y);
    printf("o");

    if(vx > 0)
    {
        gotoxy(x + 2, y);
        printf("-->");
    }
    else 
    {
        gotoxy(x - 4, y);
        printf("<--");
    }
    delay(2);

    for(int i = -4; i <= 4; i++)
    {
        gotoxy(x + i,y);
        printf(" ");
    }
}

void putBall()
{
    gotoxy(x, y);
    printf("o");
}

void eraseBall()
{
    gotoxy(x, y);
    printf(" ");
}

void moveBall()
{
    int reflect;

    x = x + vx;
    y = y + vy;

    if(x < 2)
    {
        x = 2;
        vx = - vx;
    }
    if(x > 109)
    {
        x = 109;
        vx = - vx;
    }
    if(y == 37)
    {
        reflect = checkSpan(x);

        if(reflect)
        {
            ai_play = 1;
            predictCalc = 0;
            beep();
        }

        if(reflect == 0) paralysed = 1;
        else if(reflect == 2) 
        {
            vy = - vy;
        }
        else if(reflect == 1)
        {
            vy = - vy;
            vx = vx - 0.25;
            beep();
        }
        else
        {
            vy = - vy;
            vx = vx + 0.25;
            beep();
        }
    }
    if(y == 7)
    {
        reflect = acheckSpan();
        ai_play = 0;
        targetCalc = 0;

        if(reflect) vy = - vy;
    }

    if(y == 4)
    {
        p_score++;
        displayScores();
        makeBall();
    }
    if(y == 39)
    {
        a_score++;
        displayScores();
        makeBall();
    }

    putBall();
}