void putBar()
{
    gotoxy(bar_x - 4, 37);
    printf("<");
    gotoxy(bar_x + 4, 37);
    printf(">");

    for(int i = -3; i <= 3; i++)
    {
        gotoxy(bar_x + i, 37);
        printf("*");
    }
}

void eraseBar()
{
    for(int i = -4; i <= 4; i++)
    {
        gotoxy(bar_x + i, 37);
        printf(" ");
    }
}

int checkSpan(float x)
{
    if(bar_x - 4 <= x && x <= bar_x + 4)
    {
        y--;
        if(bar_x - 1 <= x && x <= bar_x + 1) return 2;
        else if(bar_x - 4 <= x && x <= bar_x - 1) return 1; 
        else return 3;
    }
    else return 0;
}