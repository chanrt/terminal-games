void moveScreen()
{
    if(y != b[5])
    {
        for(int i = 0; i < 107; i++)
        {
            old[i] = b[i];
            b[i] = b[i+1];
        }
        old[107] = b[106];

        if(platform == 0)
        {
            srand(time(NULL));
            platform = (rand() % 12) + 7;
            int deviation = (rand() % 10) + 2;
            new_ground = b[106] + deviation - 5;

            if(new_ground > 38)
            {
                new_ground = b[106] - 5;
                platform = 7;
            }
            if(new_ground < 6) new_ground = b[106] + 5;
            b[107] = new_ground;
        }
        else
        {
            b[108] = new_ground;
            platform--;
        }
    }
}

void movePlayer()
{
    if(y < b[4] && b[4] <= (y - fall) || y > b[4] && b[4] >= y - fall)
    {
        y = b[4] - 1;
        fall = 0;
    }
    else
    {
        y = y - fall;
        fall--;
    }
    
    if(y+1 == b[4]) fall = 0;

    if(y > 100) {
        init();
    }
}