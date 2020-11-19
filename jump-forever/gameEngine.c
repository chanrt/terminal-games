void gameLayout()
{
    drawBorder();
    textMiddle("Jump Forever",2);
    drawHorizontalLine(3);
    drawStart();
}

void gameLoop()
{
    int key, value;
    do
    {
        eraseScreen();
        erasePlayer();
        moveScreen();
        movePlayer();
        drawScreen();
        drawPlayer();

        delay(0.05);
    } while (!kbhit());

    key = getch();
    if(key == 0xE0)
    {
        value = getch();
        if(value == JUMP && (y+1) == b[4])
        {
            fall = 3;
        }
    }

    gameLoop();
}