void displayScores();
void pause();
void about();

void gameLayout()
{
    drawBorder();
    drawHorizontalLine(3);
    putBar();
    aputBar();
    displayScores();
    makeBall();
}

void gameLoop()
{
    int key, value;
    do
    {
        eraseBall();
        moveBall();

        if(ai_play)
        {
            aiPlay();
        }
        else
        {
            predictReturn();
        }

        delay(0.035);
    } while(!kbhit());

    key = getch();
    if(key = 0xE0)
    {
        value = getch();
        if(value == LEFT)
        {
            eraseBar();
            if(bar_x == 7) bar_x--;
            else if(bar_x > 6) bar_x = bar_x - 2;
            putBar();
        }
        else if(value == RIGHT)
        {
            eraseBar();
            if(bar_x == 104) bar_x++;
            else if(bar_x < 105) bar_x = bar_x + 2;
            putBar();
        }
        else if(value == UP)
        {
            pause();
        }
        else if(value == DOWN)
        {
            about();
        }
    }

    gameLoop();
}

void displayScores()
{
    gotoxy(2,2);
    printf("Your score: %d",p_score);
    gotoxy(55,2);
    printf("Enemy score: %d",a_score);
}