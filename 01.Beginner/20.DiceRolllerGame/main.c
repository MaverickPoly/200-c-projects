#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    int roll;
    char again;

    // Random seed
    srand(time(NULL));

    do
    {
        printf("\nPress enter to roll a dice...\n");
        getchar();

        roll = (rand() % 6) + 1; // 1-6

        printf("You rolled %d sided dice!\n", roll);

        printf("Do you want to play again? ");
        scanf(" %c", &again);
        getchar();

    } while (tolower(again) == 'y');

    printf("Thanks for playing...\n");
    return 0;
}