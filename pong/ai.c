void calcPredict();

void aputBar()
{
    gotoxy(abar_x - 4, 6);
    printf("<");
    gotoxy(abar_x + 4, 6);
    printf(">");

    for(int i = -3; i <= 3; i++)
    {
        gotoxy(abar_x + i, 6);
        printf("*");
    }
}

void aeraseBar()
{
    for(int i = -4; i <= 4; i++)
    {
        gotoxy(abar_x + i, 6);
        printf(" ");
    }
}

void calcTarget()
{
    float ax, ay, avx, avy;

    ax = x;
    ay = y;
    avx = vx;
    avy = vy;
    for(; ay >= 6 ;)
    {
        ax = ax + avx;
        ay = ay + avy;

        if(ax < 2)
        {
            ax = 2;
            avx = - avx;
        }
        if(ax > 109)
        {
            ax = 109;
            avx = - avx;
        }
    }
    atarget = ax;
    targetCalc = 1;
}

void aiPlay()
{
    if(targetCalc == 0)
    {
        calcTarget();
    }
    else if(atarget < abar_x)
    {
        aeraseBar();
        abar_x--;
        if(abar_x < 5) abar_x++;
        aputBar();
    }
    else if(atarget > abar_x)
    {
        aeraseBar();
        abar_x++;
        if(abar_x > 105) abar_x--;
        aputBar();
    }
}

void predictReturn()
{
    if(predictCalc == 0) calcPredict();
    else if(abar_x > predict)
    {
        aeraseBar();
        abar_x--;
        if(abar_x < 5) abar_x++;
        aputBar();
    }
    else if(abar_x < predict)
    {
        aeraseBar();
        abar_x++;
        if(abar_x > 100) abar_x--;
        aputBar();
    }
}

void calcPredict()
{
    float ax, ay, avx, avy;

    ax = x;
    ay = y;
    avx = vx;
    avy = vy;

    for(; ay >= 6 ;)
    {
        ax = ax + avx;
        ay = ay + avy;

        if(ax < 2)
        {
            ax = 2;
            avx = - avx;
        }
        if(ax > 109)
        {
            ax = 109;
            avx = - avx;
        }
        if(ay == 37)
        {
            ay = 36;
            avy = - avy;
        }
    }
    predictCalc = 1;
    predict = ax;
}

int acheckSpan()
{
    if(abar_x - 4 <= x && x <= abar_x + 4) return 1;
    return 0;
}