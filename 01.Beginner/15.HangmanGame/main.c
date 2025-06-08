#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ATTEMPTS 6

// Print the word
void printWord(char word[], int guessed[])
{
    size_t wordLen = strlen(word);
    for (int i = 0; i < wordLen; i++)
    {
        if (guessed[i])
            printf("%c ", word[i]);
        else
            printf("_ ");
    }
    putchar('\n');
}

// Check if word was fully found
int isWordFound(int guessed[], size_t wordLen)
{
    for (int i = 0; i < wordLen; i++)
        if (!guessed[i])
            return 0;
    return 1;
}

// Returns Random Word
char *getRandomWord()
{
    // Random Seed
    srand(time(NULL));
    const char *words[] = {
        "Python",
        "Javascript",
        "Java",
        "Google",
        "Microsoft",
        "Godot",
        "Unity",
        "Go",
        "Rust",
        "Dart",
        "Kotlin",
        "Meta",
        "Amazon"};
    size_t len = sizeof(words) / sizeof(words[0]);
    int randomNumber = rand() % len;
    return (char *)words[randomNumber];
}

int main()
{
    printf("====== Welcome to Hangman Game! ======\n");

    char *word = getRandomWord();
    size_t wordLen = strlen(word);
    int guessed[wordLen];
    int wrongGuesses = 0;
    char guess;

    // Initialize guessed array with zeros
    for (int i = 0; i < wordLen; i++)
        guessed[i] = 0;

    // Main Game loop
    while (wrongGuesses < MAX_ATTEMPTS)
    {
        printf("\nWord:\n");
        printWord(word, guessed);

        printf("Take a guess: ");
        scanf(" %c", &guess);

        // Check if guess is in word
        int found = 0;
        for (int i = 0; i < wordLen; i++)
        {
            if (tolower(word[i]) == tolower(guess))
            {
                guessed[i] = 1;
                found = 1;
            }
        }

        if (!found)
        {
            wrongGuesses++;
            printf("Wrong! You have %d attempts remaining..\n", MAX_ATTEMPTS - wrongGuesses);
        }

        if (isWordFound(guessed, wordLen))
        {
            printf("\nCongratulations! You guessed the word: %s\n", word);
            return 0;
        }
    }

    printf("\nGame over! The word was: %s\n", word);
    return 0;
}
