#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/

int main()
{
    printf("Welcome to random number guessing game!\n");
    printf("Guess a number between 0-100\n");

    srand(time(NULL));
    int running = 1;
    int guess;
    char again;

    while (running)
    {
        printf("\nGuess a number...\n");
        int randomNumber = rand() % 100;
        int attempts = 0;

        while (1)
        {
            printf("Take a guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess == randomNumber)
            {
                printf("Correct!\n");
                printf("The number was %d!\n", randomNumber);
                printf("It took you %d attempts to find it!\n", attempts);
                break;
            }
            else if (guess < randomNumber)
            {
                printf("Too low!\n");
            }
            else
            {
                printf("Too high!\n");
            }
        }

        printf("\nDo you want to play again(y/n)? ");
        scanf(" %c", &again);
        if (again == 'n' || again == 'N')
        {
            running = 0;
        }
    }


    printf("\nThanks for playing!\n");
    return 0;
}
