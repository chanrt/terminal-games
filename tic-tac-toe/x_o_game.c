#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/*#define t1 grid[0][0]
#define t2 grid[1][0]
#define t3 grid[2][0]
#define m1 grid[0][1]
#define m2 grid[1][1]
#define m3 grid[2][1]
#define d1 grid[0][2]
#define d2 grid[1][2]
#define d3 grid[2][2]*/

int fs;
int xspr;
int ospr;
int xofc;
int oofc;
int xdef;
int odef;
int xcon;
int ocon;
int xneut;
int oneut;

int playerwins=0;
int computerwins=0;
int draws=0;
int over=0;

int compdefs=0;
int compofcs=0;
int compneut=0;

int grid[2][2];
int t1,t2,t3,d1,d2,d3,m1,m2,m3;

int symboldecider;
int firststartdecider;
int symbol=0;
int firststarter=0;
int turn=0;

char playerxname[15];
char playeroname[15];
char compname[8]="Computer";
char playerdefname[3]="You";

int playerchoice=1;
int playerx=1;
int playero=0;
int difficulty=0;
int randomize=0;
int defaultnames=0;

void analysis()
{

}

int main()
{
    srand(time(NULL));
    symboldecider=(rand() % 10) + 1;
    firststartdecider=(rand() % 10) + 1;

    if(symboldecider % 2 == 0)
    {
        symbol=1;
    }
    else
    {
        symbol=2;
    }

    if(firststartdecider % 2 == 0)
    {
        firststarter=1;
    }
    else
    {
        firststarter=2;
    }

    mainmenu();
    return 0;
}

void startanalysis()
{
    int c;

    db();
    gotoxy(3,3);
    printf("The X - O Game: Space Edition");
    gotoxy(3,4);
    printf("Advanced Analysis");
    gotoxy(3,6);
    printf("FEATURES:");
    gotoxy(3,7);
    printf("When provided with any stage of a game,");
    gotoxy(3,8);
    printf("The AI extensively analyses the current state");
    gotoxy(3,9);
    printf("And predicts the best moves for X only");
    gotoxy(3,10);
    printf("O is considered to be the opponent playing");
    gotoxy(3,11);
    printf("against X,");
    gotoxy(3,13);
    printf("No analysis is done for O");
    gotoxy(3,14);
    printf("The moves of O need to be entered manually");
    gotoxy(3,16);
    printf("The player may not obey the predicted moves,");
    gotoxy(3,17);
    printf("But the computer will continue to suggest");
    gotoxy(3,18);
    printf("Moves at each step");
    gotoxy(3,20);
    printf("Further, several parameters like: ");
    gotoxy(3,21);
    printf("1: Strategic spread");
    gotoxy(3,22);
    printf("2: Offensive and Defensive index");
    gotoxy(3,23);
    printf("3: Concealability");
    gotoxy(3,24);
    printf("4: And Neutrality");
    gotoxy(3,25);
    printf("Are calculated for both, X and O");
    gotoxy(3,27);
    printf("LIMITATIONS:");
    gotoxy(3,28);
    printf("1: Analysis is done only for X");
    gotoxy(3,29);
    printf("2: The Analysis is poor for initial turns");
    gotoxy(3,30);
    printf("3: The Analysis is not always correct");
    gotoxy(3,32);
    printf("1: Proceed");
    gotoxy(3,33);
    printf("2: Return to Menu");
    gotoxy(3,34);
    printf("Your Choice: ");
    scanf("%d",&c);

    if(c == 1)
    {
        gotoxy(3,36);
        printf("Who gets to start the game first ?");
        gotoxy(3,37);
        printf("1: X starts");
        gotoxy(3,38);
        printf("2: O starts");
        gotoxy(3,39);
        printf("The answer: ");
        scanf("%d",&fs);

        db();
        initgrid();
        playgrid();
        helpgrid();
        if(fs == 1)
        {
            xaturn();
        }
        if(fs == 2)
        {
            oaturn();
        }
    }
    if(c == 2)
    {
        mainmenu();
    }
}

void startaigame()
{
    int ps=0;
    int i;
    int startx=0;
    int starto=0;

    db();
    gotoxy(3,3);
    printf("The X - O Game: Space Edition");
    gotoxy(3,4);
    printf("AI Game:");

    gotoxy(3,6);
    printf("CURRENT CONFIGURATIONS:");
    gotoxy(3,8);
    printf("Player can choose their symbol: %d",playerchoice);
    gotoxy(3,9);
    printf("Player wants X to be their symbol: %d",playerx);
    gotoxy(3,10);
    printf("Player wants O to be their symbol: %d",playero);
    gotoxy(3,11);
    printf("Player wants X and has to start first: %d",difficulty);
    gotoxy(3,12);
    printf("Player has randomized everything: %d",randomize);
    gotoxy(3,13);
    printf("Player wants default names: %d",defaultnames);

    gotoxy(3,15);
    printf("1: Proceed");
    gotoxy(3,16);
    printf("2: Change options");
    gotoxy(3,17);
    printf("3: Return to Menu");
    gotoxy(3,18);
    printf("Your choice: ");
    scanf("%d",&i);

    if(i == 2){options();}
    if(i == 3){mainmenu();}

    if(playerchoice == 1)
    {
        gotoxy(3,20);
        printf("1: X    2: O");
        gotoxy(3,21);
        printf("Please choose your symbol: ");
        scanf("%d",&ps);

        if(ps == 1)
        {
            symbol=1;
        }
        if(ps == 2)
        {
            symbol=2;
        }
    }

    if(symbol == 1)
    {
        gotoxy(3,23);
        printf("Your allotted Symbol is X");
        for(i=0;i<=8;i++)
        {
            playeroname[i]=compname[i];
        }
    }
    if(symbol == 2)
    {
        gotoxy(3,23);
        printf("Your allotted Symbol is O");
        for(i=0;i<=8;i++)
        {
            playerxname[i]=compname[i];
        }
    }

    if(symbol == 1 && defaultnames == 0)
    {
        gotoxy(3,25);
        printf("Enter your name: ");
        scanf("%s",&playerxname);
    }
    if(symbol == 2 && defaultnames == 0)
    {
        gotoxy(3,25);
        printf("Enter your name: ");
        scanf("%s",&playeroname);
    }

    if(symbol == 1 && defaultnames == 1)
    {
        for(i=0;i<=3;i++)
        {
            playerxname[i]=playerdefname[i];
        }
    }
    if(symbol == 2 && defaultnames == 1)
    {
        for(i=0;i<=3;i++)
        {
            playeroname[i]=playerdefname[i];
        }
    }

    gotoxy(3,27);
    printf("X: %s",playerxname);
    gotoxy(3,28);
    printf("O: %s",playeroname);

    if(playerx == 1 || firststarter == 1)
    {
        gotoxy(3,30);
        printf("First Starter: X");
    }
    if(playero == 1 || firststarter == 2)
    {
        gotoxy(3,30);
        printf("First Starter: O");
    }

    gotoxy(3,32);
    printf("1: Go to Game Screen");
    gotoxy(3,33);
    printf("2: Restart from the Start");
    gotoxy(3,34);
    printf("3: Options");
    gotoxy(3,35);
    printf("4: Return to Main Menu");
    gotoxy(3,36);
    printf("Your Choice: ");
    scanf("%d",&i);

    if(i == 2)recaigame();
    if(i == 3)options();
    if(i == 4)mainmenu();

    initgrid();
    db();
    playgrid();
    helpgrid();

    if(i == 1)
    {
        if((symbol == 1 && firststarter == 1) || (symbol == 2 && firststarter == 2))
        {
            playergame();
        }
        if((symbol == 1 && firststarter == 2) || (symbol == 2 && firststarter == 1))
        {
            ai();
        }
    }
    return 0;
}

void playergame()
{
    int input=0;
    int a;

    turn++;
    debug();
    clrent();
    gotoxy(10,3);
    printf("The X - O Game: Space Edition");
    gotoxy(15,5);
    printf("Player X: %s",playerxname);
    gotoxy(15,6);
    printf("Player O: %s",playeroname);

    gotoxy(15,7);
    if(firststarter == 1)
    {
        printf("First starter: X");
    }
    if(firststarter == 2)
    {
        printf("First starter: O");
    }

    gotoxy(15,8);
    printf("Current Chance: Player    ");

    for(a=2;a<=49;a++)
    {
        gotoxy(a,30);
        printf("-");
    }

    gotoxy(3,31);
    printf("Statistics:");
    gotoxy(3,33);
    printf("Number of player wins: %d",playerwins);
    gotoxy(3,34);
    printf("Number of computer wins: %d",computerwins);
    gotoxy(3,35);
    printf("Number of draws: %d",draws);

    gotoxy(3,37);
    printf("Number of computer defenses: %d",compdefs);
    gotoxy(3,38);
    printf("Number of computer offenses: %d",compofcs);
    gotoxy(3,39);
    printf("Number of computer neutral actions: %d",compneut);

    gotoxy(15,9);
    if(symbol == 1)
    {
        printf("Your symbol: X");
    }
    if(symbol == 2)
    {
        printf("Your symbol: O");
    }
    gotoxy(13,12);
    printf("Insert your symbol in: ");
    scanf("%d",&input);

    if(input == 1 && t1 == 0 && symbol == 1)
    {
        t1=1;
        insert();
        ai();
    }
    if(input == 2 && t2 == 0 && symbol == 1)
    {
        t2=1;
        insert();
        ai();
    }
    if(input == 3 && t3 == 0 && symbol == 1)
    {
        t3=1;
        insert();
        ai();
    }
    if(input == 4 && m1 == 0 && symbol == 1)
    {
        m1=1;
        insert();
        ai();
    }
    if(input == 5 && m2 == 0 && symbol == 1)
    {
        m2=1;
        insert();
        ai();
    }
    if(input == 6 && m3 == 0 && symbol == 1)
    {
        m3=1;
        insert();
        ai();
    }
    if(input == 7 && d1 == 0 && symbol == 1)
    {
        d1=1;
        insert();
        ai();
    }
    if(input == 8 && d2 == 0 && symbol == 1)
    {
        d2=1;
        insert();
        ai();
    }
    if(input == 9 && d3 == 0 && symbol == 1)
    {
        d3=1;
        insert();
        ai();
    }

    if(input == 1 && t1 == 0 && symbol == 2)
    {
        t1=2;
        insert();
        ai();
    }
    if(input == 2 && t2 == 0 && symbol == 2)
    {
        t2=2;
        insert();
        ai();
    }
    if(input == 3 && t3 == 0 && symbol == 2)
    {
        t3=2;
        insert();
        ai();
    }
    if(input == 4 && m1 == 0 && symbol == 2)
    {
        m1=2;
        insert();
        ai();
    }
    if(input == 5 && m2 == 0 && symbol == 2)
    {
        m2=2;
        insert();
        ai();
    }
    if(input == 6 && m3 == 0 && symbol == 2)
    {
        m3=2;
        insert();
        ai();
    }
    if(input == 7 && d1 == 0 && symbol == 2)
    {
        d1=2;
        insert();
        ai();
    }
    if(input == 8 && d2 == 0 && symbol == 2)
    {
        d2=2;
        insert();
        ai();
    }
    if(input == 9 && d3 == 0 && symbol == 2)
    {
        d3=2;
        insert();
        ai();
    }
}

void ai()
{
    int a;

    gotoxy(15,8);
    printf("Current Chance: Computer");
    gotoxy(13,13);
    printf("Proceed: ");
    scanf("%d",&a);
    turn++;

    if(symbol == 1)
    {
        // horizontal offence

        if(t1 == 2 && t2 == 2 && t3 ==0)
        {
            t3=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(t1 == 2 && t2 == 0 && t3 == 2)
        {
            t2=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(t1 == 0 && t2 == 2 && t3 ==2)
        {
            t1=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(m1 == 2 && m2 == 2 && m3 ==0)
        {
            m3=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(m1 == 2 && m2 == 0 && m3 == 2)
        {
            m2=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(m1 == 0 && m2 == 2 && m3 ==2)
        {
            m1=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(d1 == 2 && d2 == 2 && d3 ==0)
        {
            d3=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(d1 == 2 && d2 == 0 && d3 == 2)
        {
            d2=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(d1 == 0 && d2 == 2 && d3 ==2)
        {
            d1=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }

        //vertical offence

        if(t1 == 0 && m1 ==2 && d1 == 2)
        {
            t1=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(t1 == 2 && m1 ==0 && d1 == 2)
        {
            m1=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(t1 == 2 && m1 ==2 && d1 == 0)
        {
            d1=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(t2 == 0 && m2 ==2 && d2 == 2)
        {
            t2=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(t2 == 2 && m2 ==0 && d2 == 2)
        {
            m2=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(t2 == 2 && m2 ==2 && d2 == 0)
        {
            d2=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(t3 == 0 && m3 ==2 && d3 == 2)
        {
            t3=2;
            compofcs++;
            insert();
            playergame();
            //compofcs++;
        }
        if(t3 == 2 && m3 ==0 && d3 == 2)
        {
            m3=2;
            compofcs++;
            insert();
            playergame();
        }
        if(t3 == 2 && m3 ==2 && d3 == 0)
        {
            d3=2;
            compofcs++;
            insert();
            playergame();
        }

        //diagonal offence

        if(t1 == 2 && m2 == 2 && d3 == 0)
        {
            d3=2;
            compofcs++;
            insert();
            playergame();
        }
        if(t1 == 2 && m2 == 0 && d3 == 2)
        {
            m2=2;
            compofcs++;
            insert();
            playergame();
        }
        if(t1 == 0 && m2 == 2 && d3 == 2)
        {
            t1=2;
            compofcs++;
            insert();
            playergame();
        }

        if(t3 == 0 && m2 == 2 && d1 == 2)
        {
            t3=2;
            compofcs++;
            insert();
            playergame();
        }
        if(t3 == 2 && m2 == 0 && d1 == 2)
        {
            m2=2;
            compofcs++;
            insert();
            playergame();
        }
        if(t3 == 2 && m2 == 2 && d1 == 0)
        {
            d1=2;
            compofcs++;
            insert();
            playergame();
        }

        // horizontal defense

        if(t1 == 1 && t2 == 1 && t3 ==0)
        {
            t3=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t1 == 1 && t2 == 0 && t3 == 1)
        {
            t2=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t1 == 0 && t2 == 1 && t3 ==1)
        {
            t1=2;
            compdefs++;
            insert();
            playergame();
        }
        if(m1 == 1 && m2 == 1 && m3 ==0)
        {
            m3=2;
            compdefs++;
            insert();
            playergame();
        }
        if(m1 == 1 && m2 == 0 && m3 == 1)
        {
            m2=2;
            compdefs++;
            insert();
            playergame();
        }
        if(m1 == 0 && m2 == 1 && m3 ==1)
        {
            m1=2;
            compdefs++;
            insert();
            playergame();
        }
        if(d1 == 1 && d2 == 1 && d3 ==0)
        {
            d3=2;
            compdefs++;
            insert();
            playergame();
        }
        if(d1 == 1 && d2 == 0 && d3 == 1)
        {
            d2=2;
            compdefs++;
            insert();
            playergame();
        }
        if(d1 == 0 && d2 == 1 && d3 == 1)
        {
            d1=2;
            compdefs++;
            insert();
            playergame();
        }

        //vertical defense

        if(t1 == 0 && m1 == 1 && d1 == 1)
        {
            t1=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t1 == 1 && m1 ==0 && d1 == 1)
        {
            m1=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t1 == 1 && m1 == 1 && d1 == 0)
        {
            d1=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t2 == 0 && m2 == 1 && d2 == 1)
        {
            t2=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t2 == 1 && m2 ==0 && d2 == 1)
        {
            m2=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t2 == 1 && m2 == 1 && d2 == 0)
        {
            d1=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t3 == 0 && m3 == 1 && d3 == 1)
        {
            t3=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t3 == 1 && m3 ==0 && d3 == 1)
        {
            m3=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t3 == 1 && m3 == 1 && d3 == 0)
        {
            d3=2;
            compdefs++;
            insert();
            playergame();
        }

        //diagonal defence

        if(t1 == 1 && m2 == 1 && d3 == 0)
        {
            d3=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t1 == 1 && m2 == 0 && d3 == 1)
        {
            m2=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t1 == 0 && m2 == 1 && d3 == 1)
        {
            t1=2;
            compdefs++;
            insert();
            playergame();
        }

        if(t3 == 0 && m2 == 1 && d1 == 1)
        {
            t3=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t3 == 1 && m2 == 0 && d1 == 1)
        {
            m2=2;
            compdefs++;
            insert();
            playergame();
        }
        if(t3 == 1 && m2 == 1 && d1 == 0)
        {
            d1=2;
            compdefs++;
            insert();
            playergame();
        }

        //middle and corner attacks

        if(m2 == 0)
        {
            m2=2;
            compneut++;
            insert();
            playergame();
        }
        if(t1 == 0)
        {
            t1=2;
            compneut++;
            insert();
            playergame();
        }
        if(t3 == 0)
        {
            t3=2;
            compneut++;
            insert();
            playergame();
        }
        if(d1 == 0)
        {
            d1=2;
            compneut++;
            insert();
            playergame();
        }
        if(d3 == 0)
        {
            d3=2;
            compneut++;
            insert();
            playergame();
        }

        //edge attacks

        if(t2 == 0)
        {
            t2=2;
            compneut++;
            insert();
            playergame();
        }
        if(d2 == 0)
        {
            d2=2;
            compneut++;
            insert();
            playergame();
        }
        if(m1 == 0)
        {
            m1=2;
            compneut++;
            insert();
            playergame();
        }
        if(m3 == 0)
        {
            m3=2;
            compneut++;
            insert();
            playergame();
        }
    }

    if(symbol == 2)
    {
        // horizontal offence

        if(t1 == 1 && t2 == 1 && t3 ==0)
        {
            t3=1;
            insert();
            playergame();
        }
        if(t1 == 1 && t2 == 0 && t3 == 1)
        {
            t2=1;
            insert();
            playergame();
        }
        if(t1 == 0 && t2 == 1 && t3 ==1)
        {
            t1=1;
            insert();
            playergame();
        }
        if(m1 == 1 && m2 == 1 && m3 ==0)
        {
            m3=1;
            insert();
            playergame();
        }
        if(m1 == 1 && m2 == 0 && m3 == 1)
        {
            m2=1;
            insert();
            playergame();
        }
        if(m1 == 0 && m2 == 1 && m3 == 1)
        {
            m1=1;
            insert();
            playergame();
        }
        if(d1 == 1 && d2 == 1 && d3 ==0)
        {
            d3=1;
            insert();
            playergame();
        }
        if(d1 == 1 && d2 == 0 && d3 == 1)
        {
            d2=1;
            insert();
            playergame();
        }
        if(d1 == 0 && d2 == 1 && d3 == 1)
        {
            d1=1;
            insert();
            playergame();
        }

        //vertical offence

        if(t1 == 0 && m1 ==1 && d1 == 1)
        {
            t1=1;
            insert();
            playergame();
        }
        if(t1 == 1 && m1 ==0 && d1 == 1)
        {
            m1=1;
            insert();
            playergame();
        }
        if(t1 == 1 && m1 == 1 && d1 == 0)
        {
            d1=1;
            insert();
            playergame();
        }
        if(t2 == 0 && m2 == 1 && d2 == 1)
        {
            t2=1;
            insert();
            playergame();
        }
        if(t2 == 1 && m2 ==0 && d2 == 1)
        {
            m2=1;
            insert();
            playergame();
        }
        if(t2 == 1 && m2 ==1 && d2 == 0)
        {
            d2=1;
            insert();
            playergame();
        }
        if(t3 == 0 && m3 ==1 && d3 == 1)
        {
            t3=1;
            insert();
            playergame();
        }
        if(t3 == 1 && m3 ==0 && d3 == 1)
        {
            m1=1;
            insert();
            playergame();
        }
        if(t3 == 1 && m3 ==1 && d3 == 0)
        {
            d3=1;
            insert();
            playergame();
        }

        //diagonal offence

        if(t1 == 1 && m2 == 1 && d3 == 0)
        {
            d3=1;
            insert();
            playergame();
        }
        if(t1 == 1 && m2 == 0 && d3 == 1)
        {
            m2=1;
            insert();
            playergame();
        }
        if(t1 == 0 && m2 == 1 && d3 == 1)
        {
            t1=1;
            insert();
            playergame();
        }

        if(t3 == 0 && m2 == 1 && d1 == 1)
        {
            t3=1;
            insert();
            playergame();
        }
        if(t3 == 1 && m2 == 0 && d1 == 1)
        {
            m2=1;
            insert();
            playergame();
        }
        if(t3 == 1 && m2 == 1 && d1 == 0)
        {
            d1=1;
            insert();
            playergame();
        }

        // horizontal defense

        if(t1 == 2 && t2 == 2 && t3 ==0)
        {
            t3=1;
            insert();
            playergame();
        }
        if(t1 == 2 && t2 == 0 && t3 == 2)
        {
            t2=1;
            insert();
            playergame();
        }
        if(t1 == 0 && t2 == 2 && t3 ==2)
        {
            t1=1;
            insert();
            playergame();
        }
        if(m1 == 2 && m2 == 2 && m3 ==0)
        {
            m3=1;
            insert();
            playergame();
        }
        if(m1 == 2 && m2 == 0 && m3 == 2)
        {
            m2=1;
            insert();
            playergame();
        }
        if(m1 == 0 && m2 == 2 && m3 ==2)
        {
            m1=1;
            insert();
            playergame();
        }
        if(d1 == 2 && d2 == 2 && d3 ==0)
        {
            d3=1;
            insert();
            playergame();
        }
        if(d1 == 2 && d2 == 0 && d3 == 2)
        {
            d2=1;
            insert();
            playergame();
        }
        if(d1 == 0 && d2 == 2 && d3 == 2)
        {
            d1=1;
            insert();
            playergame();
        }

        //vertical defense

        if(t1 == 0 && m1 == 2 && d1 == 2)
        {
            t1=1;
            insert();
            playergame();
        }
        if(t1 == 2 && m1 ==0 && d1 == 2)
        {
            m1=1;
            insert();
            playergame();
        }
        if(t1 == 2 && m1 == 2 && d1 == 0)
        {
            d1=1;
            insert();
            playergame();
        }
        if(t2 == 0 && m2 == 2 && d2 == 2)
        {
            t2=1;
            insert();
            playergame();
        }
        if(t2 == 2 && m2 ==0 && d2 == 2)
        {
            m2=1;
            insert();
            playergame();
        }
        if(t2 == 2 && m2 == 2 && d2 == 0)
        {
            d1=1;
            insert();
            playergame();
        }
        if(t3 == 0 && m3 == 2 && d3 == 2)
        {
            t3=1;
            insert();
            playergame();
        }
        if(t3 == 2 && m3 ==0 && d3 == 2)
        {
            m1=1;
            insert();
            playergame();
        }
        if(t3 == 2 && m3 == 2 && d3 == 0)
        {
            d3=1;
            insert();
            playergame();
        }

        //diagonal defence

        if(t1 == 2 && m2 == 2 && d3 == 0)
        {
            d3=1;
            insert();
            playergame();
        }
        if(t1 == 2 && m2 == 0 && d3 == 2)
        {
            m2=1;
            insert();
            playergame();
        }
        if(t1 == 0 && m2 == 2 && d3 == 2)
        {
            t1=1;
            insert();
            playergame();
        }

        if(t3 == 0 && m2 == 2 && d1 == 2)
        {
            t3=1;
            insert();
            playergame();
        }
        if(t3 == 2 && m2 == 0 && d1 == 2)
        {
            m2=1;
            insert();
            playergame();
        }
        if(t3 == 2 && m2 == 2 && d1 == 0)
        {
            d1=1;
            insert();
            playergame();
        }

        //middle and corner attacks

        if(m2 == 0)
        {
            m2=1;
            insert();
            playergame();
        }
        if(t1 == 0)
        {
            t1=1;
            insert();
            playergame();
        }
        if(t3 == 0)
        {
            t3=1;
            insert();
            playergame();
        }
        if(d1 == 0)
        {
            d1=1;
            insert();
            playergame();
        }
        if(d3 == 0)
        {
            d3=1;
            insert();
            playergame();
        }

        //edge attacks

        if(t2 == 0)
        {
            t2=1;
            insert();
            playergame();
        }
        if(d2 == 0)
        {
            d2=1;
            insert();
            playergame();
        }
        if(m1 == 0)
        {
            m1=1;
            insert();
            playergame();
        }
        if(m3 == 0)
        {
            m3=1;
            insert();
            playergame();
        }

    }
}

void xaturn()
{
    int ainput;

    gotoxy(10,3);
    printf("The X - O Game: Space Edition");
    gotoxy(15,4);
    printf("Advanced Analysis");
    gotoxy(15,7);
    if(fs == 1)
    {
        printf("First starter: X");
    }
    if(fs == 2)
    {
        printf("First starter: O");
    }
    analysis();
    gotoxy(15,9);
    printf("Your symbol: X");
    gotoxy(15,10);
    printf("Current turn: X");
    gotoxy(13,12);
    printf("Insert your symbol in: ");
    scanf("%d",&ainput);

    if(ainput == 1 && t1 == 0)
    {
        t1=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
    if(ainput == 2 && t2 == 0)
    {
        t2=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
    if(ainput == 3 && t3 == 0)
    {
        t3=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
    if(ainput == 4 && m1 == 0)
    {
        m1=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
    if(ainput == 5 && m2 == 0)
    {
        m2=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
    if(ainput == 6 && m3 == 0)
    {
        m3=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
    if(ainput == 7 && d1 == 0)
    {
        d1=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
    if(ainput == 8 && d2 == 0)
    {
        d2=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
    if(ainput == 9 && d3 == 0)
    {
        d3=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
}

void oaturn()
{
    int ainput;

    gotoxy(15,10);
    printf("Current turn: O");
    gotoxy(13,12);
    printf("Insert O's symbol in: ");
    scanf("%d",&ainput);

    if(ainput == 1 && t1 == 0)
    {
        t1=2;
        turn++;
        insert();
        ostat();
        xaturn();
    }
    if(ainput == 2 && t2 == 0)
    {
        t2=2;
        turn++;
        insert();
        ostat();
        xaturn();
    }
    if(ainput == 3 && t3 == 0)
    {
        t3=2;
        turn++;
        insert();
        ostat();
        xaturn();
    }
    if(ainput == 4 && m1 == 0)
    {
        m1=2;
        turn++;
        insert();
        ostat();
        xaturn();
    }
    if(ainput == 5 && m2 == 0)
    {
        m2=2;
        turn++;
        insert();
        ostat();
        xoaturn();
    }
    if(ainput == 6 && m3 == 0)
    {
        m3=2;
        turn++;
        insert();
        ostat();
        xaturn();
    }
    if(ainput == 7 && d1 == 0)
    {
        d1=2;
        turn++;
        insert();
        ostat();
        xaturn();
    }
    if(ainput == 8 && d2 == 0)
    {
        d2=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
    if(ainput == 9 && d3 == 0)
    {
        d3=1;
        turn++;
        insert();
        stat();
        oaturn();
    }
}

stat()
{

}

ostat()
{

}

xoaturn()
{

}

void clrent()
{
    gotoxy(36,12);
    printf("  ");
    gotoxy(22,13);
    printf("  ");
}

int mainmenu()
{
    int choice;

    db();
    gotoxy(10,14);
    printf("The X - O Game : Space Edition");
    gotoxy(17,18);
    printf("1: Advanced Analysis");
    gotoxy(17,20);
    printf("2: Play with AI");
    gotoxy(17,22);
    printf("3: 2-Player");
    gotoxy(17,24);
    printf("4: Options");
    gotoxy(17,26);
    printf("5: About");
    gotoxy(17,28);
    printf("6: Exit Game");
    gotoxy(17,32);
    printf("Your choice: ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        startanalysis();
    }
    if(choice == 2)
    {
        startaigame();
    }
    if(choice == 3)
    {
        starttwoplayergame();
    }
    if(choice == 4)
    {
        options();
    }
    if(choice == 5)
    {
        about();
    }
    if(choice == 6)
    {
        return 0;
    }
}

void starttwoplayergame()
{
    db();
}

void insert()
{
    gotoxy(3,37);
    printf("Number of computer defenses: %d",compdefs);
    gotoxy(3,38);
    printf("Number of computer offenses: %d",compofcs);
    gotoxy(3,39);
    printf("Number of computer neutral actions: %d",compneut);
    if(t1 == 1)
    {
        gotoxy(21,15);
        printf("X");
    }
    if(t1 == 2)
    {
        gotoxy(21,15);
        printf("O");
    }
    if(t2 == 1)
    {
        gotoxy(25,15);
        printf("X");
    }
    if(t2 == 2)
    {
        gotoxy(25,15);
        printf("O");
    }
    if(t3 == 1)
    {
        gotoxy(29,15);
        printf("X");
    }
    if(t3 == 2)
    {
        gotoxy(29,15);
        printf("O");
    }
    if(m1== 1)
    {
        gotoxy(21,17);
        printf("X");
    }
    if(m1 == 2)
    {
        gotoxy(21,17);
        printf("O");
    }
    if(m2 == 1)
    {
        gotoxy(25,17);
        printf("X");
    }
    if(m2== 2)
    {
        gotoxy(25,17);
        printf("O");
    }
    if(m3 == 1)
    {
        gotoxy(29,17);
        printf("X");
    }
    if(m3 == 2)
    {
        gotoxy(29,17);
        printf("O");
    }
    if(d1 == 1)
    {
        gotoxy(21,19);
        printf("X");
    }
    if(d1 == 2)
    {
        gotoxy(21,19);
        printf("O");
    }
    if(d2 == 1)
    {
        gotoxy(25,19);
        printf("X");
    }
    if(d2 == 2)
    {
        gotoxy(25,19);
        printf("O");
    }
    if(d3 == 1)
    {
        gotoxy(29,19);
        printf("X");
    }
    if(d3 == 2)
    {
        gotoxy(29,19);
        printf("O");
    }
    if(over == 0)
    {
        checkxwin();
        checkowin();
        checkdraw();
    }
}

void newgameinit()
{
    int ps;
    int i;

    srand(time(NULL));
    symboldecider=(rand() % 10) + 1;
    firststartdecider=(rand() % 10) + 1;

    over=0;
    turn=0;

    if(symboldecider % 2 == 0)
    {
        symbol=1;
    }
    else
    {
        symbol=2;
    }

    if(firststartdecider % 2 == 0)
    {
        firststarter=1;
    }
    else
    {
        firststarter=2;
    }

    if(playerchoice == 1)
    {
        gotoxy(3,20);
        printf("1: X    2: O");
        gotoxy(3,21);
        printf("Please choose your symbol: ");
        scanf("%d",&ps);

        if(ps == 1)
        {
            symbol=1;
        }
        if(ps == 2)
        {
            symbol=2;
        }
    }

    if(symbol == 1)
    {
        gotoxy(3,23);
        printf("Your allotted Symbol is X");
        for(i=0;i<=8;i++)
        {
            playeroname[i]=compname[i];
        }
    }
    if(symbol == 2)
    {
        gotoxy(3,23);
        printf("Your allotted Symbol is O");
        for(i=0;i<=8;i++)
        {
            playerxname[i]=compname[i];
        }
    }

    gotoxy(3,27);
    printf("X: %s",playerxname);
    gotoxy(3,28);
    printf("O: %s",playeroname);

    if(playerx == 1 || firststarter == 1)
    {
        gotoxy(3,30);
        printf("First Starter: X");
    }
    if(playero == 1 || firststarter == 2)
    {
        gotoxy(3,30);
        printf("First Starter: O");
    }


    gotoxy(3,36);
    printf("Proceed: ");
    scanf("%d",&i);

    initgrid();
    db();
    playgrid();
    helpgrid();

    if(i == 1)
    {
        if((symbol == 1 && firststarter == 1) || (symbol == 2 && firststarter == 2))
        {
            playergame();
        }
        if((symbol == 1 && firststarter == 2) || (symbol == 2 && firststarter == 1))
        {
            ai();
        }
    }
}

void checkxwin()
{
    int a;
    if((t1==1 && t2==1 && t3==1) || (m1==1 && m2==1 && m3==1) || (d1==1 && d2==1 && d3==1) || (t1==1 && m1==1 && d1==1) || (t2==1 && m2==1 && d2==1) || (t3==1 && m3==1 && d3==1) || (t1==1 && m2==1 && d3==1) || (t3==1 && m2==1 && d1==1))
    {
        clrscr();
        playgrid();
        over=1;
        insert();

        if(symbol==1)
        {
            playerwins++;
        }
        if(symbol==2)
        {
            computerwins++;
        }
        gotoxy(3,3);
        printf("X has won the game");
        gotoxy(3,5);
        printf("1: New Game (All data will be intact)");
        gotoxy(3,6);
        printf("2: Return to Main Menu (All data will be lost");
        gotoxy(3,7);
        printf("Your Choice: ");
        scanf("%d",&a);

        if(a==1)
        {
            newgameinit();
        }
        else{
            mainmenu();
        }
    }
}

void checkowin()
{
        int a;
    if((t1==2 && t2==2 && t3==2) || (m1==2 && m2==2 && m3==2) || (d1==2 && d2==2 && d3==2) || (t1==2 && m1==2 && d1==2) || (t2==2 && m2==2 && d2==2) || (t3==2 && m3==2 && d3==2) || (t1==2 && m2==2 && d3==2) || (t3==2 && m2==2 && d1==2))
    {
        clrscr();
        playgrid();
        over=1;
        insert();

        if(symbol==1)
        {
            computerwins++;
        }
        if(symbol==2)
        {
            playerwins++;
        }
        gotoxy(3,3);
        printf("O has won the game");
        gotoxy(3,5);
        printf("1: New Game (All data will be intact)");
        gotoxy(3,6);
        printf("2: Return to Main Menu (All data will be lost");
        gotoxy(3,7);
        printf("Your Choice: ");
        scanf("%d",&a);

        if(a==1)
        {
            newgameinit();
        }
        else{
            mainmenu();
        }
    }
}

void checkdraw()
{
    int a;

    if(t1 != 0 && m1 != 0 && d1 != 0 && t2 != 0 && m2 != 0 && d2 != 0 && t3 != 0 && m3 != 0 && d3 != 0)
    {
        clrscr();
        playgrid();
        over=1;
        insert();
        gotoxy(3,3);
        printf("The Game is a Draw!");
        gotoxy(3,5);
        printf("1: New Game (All data will be intact)");
        gotoxy(3,6);
        printf("2: Return to Main Menu (All data will be lost");
        gotoxy(3,7);
        printf("Your Choice: ");
        scanf("%d",&a);

        if(a==1)
        {
            newgameinit();
        }
        else{
            mainmenu();
        }
    }
}

void recaigame()
{
    startaigame();
}

void playgrid()
{
    gotoxy(23,15);
    printf("|   |");
    gotoxy(21,16);
    printf("--+---+--");
    gotoxy(23,17);
    printf("|   |");
    gotoxy(21,18);
    printf("--+---+--");
    gotoxy(23,19);
    printf("|   |");
}

void helpgrid()
{
    gotoxy(23,22);
    printf("|   |");
    gotoxy(21,23);
    printf("--+---+--");
    gotoxy(23,24);
    printf("|   |");
    gotoxy(21,25);
    printf("--+---+--");
    gotoxy(23,26);
    printf("|   |");

    gotoxy(21,22);
    printf("1");
    gotoxy(25,22);
    printf("2");
    gotoxy(29,22);
    printf("3");
    gotoxy(21,24);
    printf("4");
    gotoxy(25,24);
    printf("5");
    gotoxy(29,24);
    printf("6");
    gotoxy(21,26);
    printf("7");
    gotoxy(25,26);
    printf("8");
    gotoxy(29,26);
    printf("9");
}

void options()
{
    int c1;
    int at1=0;
    int at2=0;
    int at3=0;

    db();
    gotoxy(3,3);
    printf("OPTIONS:");
    gotoxy(3,5);
    printf("Legend: ");
    gotoxy(3,6);
    printf("0: OFF    1: ON");
    gotoxy(3,8);
    printf("CURRENT SETTINGS:");
    gotoxy(3,10);
    printf("1: Player can choose symbol: %d",playerchoice);
    gotoxy(3,12);
    printf("2: Player always gets X: %d",playerx);
    gotoxy(3,14);
    printf("3: Player always gets O: %d",playero);
    gotoxy(3,19);
    printf("4: Player gets X and he starts first: %d",difficulty);
    gotoxy(3,21);
    printf("5: Everything random: %d",randomize);
    gotoxy(3,23);
    printf("6: Default names: %d",defaultnames);
    gotoxy(6,24);
    printf("X: Player X;   O: Player O");
    gotoxy(3,28);
    printf("7: Return to Menu");
    gotoxy(3,16);
    printf("NOTE: If both (2) and (3) are set to '1',");
    gotoxy(10,17);
    printf("the player will get an X");
    gotoxy(3,26);
    printf("NOTE: (4),(5) and (6) can't be toggled back");
    gotoxy(3,30);
    printf("Your Choice: ");
    scanf("%d",&c1);
    if(c1 == 5)
    {
        randomize=1;
        playerchoice=0;
        playerx=0;
        playero=0;
        recoptions();
    }
    if(c1 == 6)
    {
        defaultnames=1;
        recoptions();
    }
    if(c1 == 7)
    {
        mainmenu();
    }
    if(c1 == 4)
    {
        difficulty=-1;
        symbol=1;
        firststarter=1;
        recoptions();
    }
    if(c1 == 1)
    {
        if(playerchoice == 0 && at1 == 0)
        {
            playerchoice=1;
            at1=1;
        }
        if(playerchoice == 1 && at1 == 0)
        {
            playerchoice=0;
        }
        recoptions();
    }
    if(c1 == 2)
    {
        if(playerx == 0 && at2 == 0)
        {
            playerx=1;
            at2=1;
        }
        if(playerx == 1 && at2 == 0)
        {
            playerx=0;
        }
        if(playerx == 1 && playero == 1)
        {
            playerx=1;
            playero=0;
        }
        recoptions();
    }
    if(c1 == 3)
    {
        if(playero == 0 && at3 == 0)
        {
            playero=1;
            at3=1;
        }
        if(playero == 1 && at3 == 0)
        {
            playero=0;
        }
        if(playerx == 1 && playero == 1)
        {
            playerx=1;
            playero=0;
        }
        recoptions();
    }
}

void initgrid()
{
    int a,b;

    for(a=0;a<=2;a++)
    {
        for(b=0;b<=2;b++)
        {
            grid[a][b]=0;
        }
    }
    t1=0;
    t2=0;
    t3=0;
    m1=0;
    m2=0;
    m3=0;
    d1=0;
    d2=0;
    d3=0;
}

void recoptions()
{
    options();
}

void about()
{
    int c2;
    db();
    gotoxy(3,3);
    printf("The X - O Game : Space Edition");
    gotoxy(3,4);
    printf("Programmed by ChessWizard4114");
    gotoxy(3,9);
    printf("TWO PLAYER GAME FEATURES:");
    gotoxy(3,11);
    printf("1: Player name(s) can be entered");
    gotoxy(3,12);
    printf("2: Automatic win checker");
    gotoxy(3,13);
    printf("3: Number of wins counter");
    gotoxy(3,14);
    printf("4: Who starts first, can be toggled");
    gotoxy(6,15);
    printf("Or everything can be randomized");
    gotoxy(3,16);
    printf("5: Or default names can be assigned");
    gotoxy(6,17);
    printf("For those guys who're lazy to type names!");
    gotoxy(3,19);
    printf("AI GAME FEATURES:");
    gotoxy(3,21);
    printf("1: Aggressive Artificial Intelligence");
    gotoxy(3,22);
    printf("2: Automatic win checker and win counter");
    gotoxy(3,23);
    printf("3: Player can enter name, or choose default");
    gotoxy(3,24);
    printf("4: Everything can be initialised");
    gotoxy(6,25);
    printf("Player's symbol, first starter");
    gotoxy(3,26);
    printf("5: Or everything can be randomized");
    gotoxy(3,28);
    printf("FEATURES UNDER DEV:");
    gotoxy(3,30);
    printf("1: OpenGL Graphics");
    gotoxy(3,31);
    printf("2: AI Vs AI");
    gotoxy(3,32);
    printf("3: Game Analyser");
    gotoxy(3,34);
    printf("ENJOY THE GAME");
    gotoxy(30,6);
    printf("RETURN TO MENU: ");
    scanf("%d",&c2);
    mainmenu();
}

void db()
{
    int a,b;

    clrscr();
    for(a=1;a<=50;a++)
    {
        gotoxy(a,1);
        printf("-");
        gotoxy(a,50);
        printf("-");
    }
    for(b=1;b<=50;b++)
    {
        gotoxy(1,b);
        printf("|");
        gotoxy(50,b);
        printf("|");
    }
}

void debug()
{
    gotoxy(3,15);
    printf("Box 1: %d",t1);
    gotoxy(3,16);
    printf("Box 2: %d",t2);
    gotoxy(3,17);
    printf("Box 3: %d",t3);
    gotoxy(3,18);
    printf("Box 4: %d",m1);
    gotoxy(3,19);
    printf("Box 5: %d",m2);
    gotoxy(3,20);
    printf("Box 6: %d",m3);
    gotoxy(3,21);
    printf("Box 7: %d",d1);
    gotoxy(3,22);
    printf("Box 8: %d",d2);
    gotoxy(3,23);
    printf("Box 9: %d",d3);
}

void clrscr()
{
    int a;
    int b;

    for(a=50;a>=1;a--)
    {
        for(b=50;b>=1;b--)
        {
            gotoxy(a,b);
            printf(" ");
        }
    }
}

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
