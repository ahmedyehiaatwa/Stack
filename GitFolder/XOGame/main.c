#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char table[10] = {'1','2','3','4','5','6','7','8','9'};

void Flush (void)  // Prevent stream from char input into int
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

int checkwin()  // Check if player won or not.
{
    if (table[0] == table[1] && table[1] == table[2])
        return 1;

    else if (table[3] == table[4] && table[4] == table[5])
        return 1;

    else if (table[6] == table[7] && table[7] == table[8])
        return 1;

    else if (table[0] == table[3] && table[3] == table[6])
        return 1;

    else if (table[1] == table[4] && table[4] == table[7])
        return 1;

    else if (table[2] == table[5] && table[5] == table[8])
        return 1;

    else if (table[0] == table[4] && table[4] == table[8])
        return 1;

    else if (table[2] == table[4] && table[4] == table[6])
        return 1;

    else if (table[0] != '1' && table[1] != '2' && table[2] != '3' &&
        table[3] != '4' && table[4] != '5' && table[5] != '6' && table[6]
        != '7' && table[7] != '8' && table[8] != '9')

        return 0;
    else
        return  - 1;
}

void board ()
{
  int i,j;
  int x=0;


    printf("**********");
    printf("\n");
    for(i=0;i<9;i++)
    {
        for(j=0;j<10;j++)
    {
        if(i==2 | i==5 | i==8)
        {
        printf("**********");
        break;
        }
        if (j==0 | j==3 | j==6 | j==9)
        {
            printf("|");
        }
        else if (j==2 | j== 5 | j== 8 && i== 1 | i==4 | i==7)
        {
            printf("%c",table[x]);
            x++;
        }
        else
        {
           printf(" ");
        }
    }
        printf("\n");
    }
}


int main()
{
        int player = 1;
        int check;
        int choice=20;
        int gamenotover=0;
        char input;
        int test;
        int rt;
        int arr[9];
        int z=0;
        int counter=0;

        board();
        do{
        player = (player % 2) ? 1 : 2;  // Change between player 1 and player 2
        printf("Player %d , enter a number:  \n",player);
        rt = scanf("%d", &choice);  // Enter the position you want to put X or O into

        if(rt==1)   // Checks if integer is entered or not
        for(z=0;z<counter;z++)  // checks if input position in table is taken
        {
            if(arr[z]==choice)
            while(1)
            {
            printf("Please enter valid position from 1-9 not TAKEN\n");
            Flush();
            rt = scanf("%d", &choice);
            if (choice >= 1 && choice <= 9 && choice != arr[z])
            {
            z=0;
            break;
            }
            }
        }
        if(rt==1)  // After new input it given check f it is an integer
        {
        if (choice >= 1 && choice <= 9) // If the integer is within range from 1 to 9
        {
        choice--;
        input = (player == 1) ? 'X' : 'O';  // If player 1 true then X if not O
        table[choice]=input;
        board();
        player++;
        arr[z]=choice+1;
        z++;
        counter++;
        check = checkwin();
        }
        }
        else if (rt==0)   // if the input is not an integer
        {
        printf("WRONG INPUT\n");
        while(1)
        {
        Flush();
        printf("Player %d , enter a number from 1-9 \n",player);
        rt=scanf("%d", &choice);
    //    if (rt==1)  // Check if input is now an integer
        for(z=0;z<counter;z++)
        {
            if(arr[z]==choice)
            while(1)
            {
            printf("Please enter valid value from 1-9 NOT TAKEN\n");  // Check if input is not taken from table before
            Flush();
            rt = scanf("%d", &choice);
            if (choice >= 1 && choice <= 9 && choice != arr[z])
            {
            z=0;
            break;
            }
            }
        }
        if(rt==1)  // Check if input is an integer
        break;

        }
        if (choice >= 1 && choice <= 9)  // Goes and replace value with X or O
        {
        choice--;
        input = (player == 1) ? 'X' : 'O';
        table[choice]=input;
        board();
        player++;
        arr[z]=choice+1;
        z++;
        counter++;
        check = checkwin();
        }
        }
        }while (check== -1);
        if (check == 1)
        printf("CONGRATULATIONS  \aPlayer %d win ", --player);
    else
        printf("Game ended in a\aGame draw");
        board();

    return 0;
}
