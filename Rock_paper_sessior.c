#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int get_inp();

int generatearandumnumber()
{
    srand(time(NULL));
    return rand() % 3;
}
int main()
{
    int inpofplayer1, i, scofplayer1 = 0, numberofgames, scofplayer2 = 0;
    int option, inpofplayer2;
    char *nameofplayer1, *nameofplayer2;
    nameofplayer1 = (char *)malloc(100 * sizeof(char));
    nameofplayer2 = (char *)malloc(100 * sizeof(char));
    printf("With Whom You Want to Play with: \n");
    printf("1. Computer\n2. Another Player\n");
    printf("Enter Your Choice: ");
    scanf("%d", &option);
    printf("Enter the name of your without any space: \n");
    name:
    printf("Player 1: ");
    scanf("%s", nameofplayer1);
    if (option == 2)
    {
        printf("Player 2: ");
        scanf("%s", nameofplayer2);
        if (strcmp(nameofplayer1, nameofplayer2) == 0)
        {
            printf("Please Enter Different Name so that we can Declare The Winner Properly.\n");
            goto name;
        }
    }
    else if (option == 1)
    {
        nameofplayer2 = "Computer";
    }
number:
    printf("Enter how many times you want to play : ");
    scanf("%d", &numberofgames);
    if (numberofgames % 2 == 0)
    {
        printf("Please Enter odd input then we could decide the winner.\n");
        goto number;
    }
    printf("The name of Player 1 is: %s \n", nameofplayer1);
    printf("The name of Player 2 is: %s \n", nameofplayer2);
    printf("\n");
    printf("The score of %s round is: %d\n", nameofplayer1, scofplayer1);
    printf("The score of %s round is: %d\n", nameofplayer2, scofplayer2);
    for (i = 0; i < numberofgames; i++)
    {
        printf("\nPress \n0.Rock\n1.Paper\n2.Sessiors\n");
        printf("Enter your input: ");
    label:
        inpofplayer1 = get_inp();
        printf("\n");
        if (option == 1)
        {
            printf("The input by the computer is: %d\n", generatearandumnumber());
        }
        else if (option == 2)
        {
            printf("Enter input of player 2: ");
        label1:
            inpofplayer2 = get_inp();
            if (inpofplayer2 > 2 && inpofplayer2 < 0)
            {
                printf("\nWrong input %s\n", nameofplayer2);
                printf("Give correct input: ");
                goto label1;
            }
        }
        switch (inpofplayer1)
        {
        case 0:
            if (inpofplayer2 == 0)
            {
                printf("\nDraw match \n");
                scofplayer1 = scofplayer1 + 0;
                scofplayer2 = scofplayer2 + 0;
            }
            else if (inpofplayer2 == 1)
            {
                printf("%s wins\n", nameofplayer2);
                scofplayer1 = scofplayer1 + 0;
                scofplayer2 = scofplayer2 + 1;
            }
            else
            {
                printf("%s wins\n", nameofplayer1);
                scofplayer1 = scofplayer1 + 1;
                scofplayer2 = scofplayer2 + 0;
            }
            goto score;
        case 1:
            if (inpofplayer2 == 0)
            {
                printf("%s wins\n", nameofplayer1);
                scofplayer1 = scofplayer1 + 1;
                scofplayer2 = scofplayer2 + 0;
            }
            else if (inpofplayer2 == 1)
            {
                printf("\nDraw match \n");
                scofplayer1 = scofplayer1 + 0;
                scofplayer2 = scofplayer2 + 0;
            }
            else
            {
                printf("%s wins\n", nameofplayer2);
                scofplayer1 = scofplayer1 + 0;
                scofplayer2 = scofplayer2 + 1;
            }
            goto score;
        case 2:
            if (inpofplayer2 == 0)
            {
                printf("%s wins\n", nameofplayer2);
                scofplayer1 = scofplayer1 + 0;
                scofplayer2 = scofplayer2 + 1;
            }
            else if (inpofplayer2 == 1)
            {
                printf("%s wins\n", nameofplayer1);
                scofplayer1 = scofplayer1 + 1;
                scofplayer2 = scofplayer2 + 0;
            }
            else
            {
                printf("\nDraw match \n");
                scofplayer1 = scofplayer1 + 0;
                scofplayer2 = scofplayer2 + 0;
            }
            goto score;
        default:
            printf("Wrong input\n");
            printf("Give correct input: ");
            goto label;
        }
    score:
        printf("\n");
        printf("The score of %s after %d round is: %d\n", nameofplayer1, i + 1, scofplayer1);
        printf("The score of %s after %d round is: %d\n", nameofplayer2, i + 1, scofplayer2);
        continue;
        printf("\n");
    }
    printf("The score of %s round is: %d\n", nameofplayer1, scofplayer1);
    printf("The score of %s round is: %d\n", nameofplayer2, scofplayer2);
    printf("\n");
    if (scofplayer1 > scofplayer2)
    {
        printf("\nThe winner is: %s\n", nameofplayer1);
        printf("CONGRATULATIONS ");
    }
    else if (scofplayer1 < scofplayer2)
    {
        printf("\nThe winner is: %s\n", nameofplayer2);
        printf("CONGRATULATIONS ");
    }
    else
        printf("The match is Draw.");
    return 0;
}

int get_inp()
{
    char ch;
    int i = 0;
    char input[2] = {'\0'}; // We only expect one character and null-terminator
    while (1)
    {
        ch = _getch();
        if (ch == 13) // Enter key
        {
            if (i == 1 && (input[0] == '0' || input[0] == '1' || input[0] == '2'))
            {
                printf("\n");
                return input[0] - '0';
            }
            else
            {
                printf("\nInvalid input. Please enter 0, 1, or 2: ");
                i = 0;
                input[0] = '\0';
            }
        }
        else if (ch == 8) // Backspace
        {
            if (i > 0)
            {
                i = 0;
                input[0] = '\0';
                printf("\b \b"); // Erase character on screen
            }
        }
        else if (i == 0 && (ch == '0' || ch == '1' || ch == '2'))
        {
            input[0] = ch;
            i = 1;
            printf("*");
        }
        else
        {
            // Invalid character
            printf("\nOnly enter 0, 1, or 2. Try again: ");
            i = 0;
            input[0] = '\0';
        }
    }
}

