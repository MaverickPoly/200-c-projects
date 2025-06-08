#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1000

int main()
{
    char text[] = "C is a general-purpose programming language. It was created in the 1970s by Dennis Ritchie and remains very widely used and influential.";
    char input[MAX_LEN];
    int correct = 0;

    printf("==== Mini Typing Test ====\n\n");
    printf("Type the following sentence:\n\n%s\n\n", text);

    printf("Press Enter when you are ready to start...");
    getchar();

    time_t start = time(NULL);
    printf("\nStart typing:\n");
    fgets(input, MAX_LEN, stdin);

    time_t end = time(NULL);

    // Remove the trailing newline char
    size_t len = strlen(input);
    if (input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
        len--;
    }

    // Count correct characters
    for (int i = 0; i < strlen(text) && i < strlen(input); i++)
    {
        if (text[i] == input[i])
            correct++;
    }

    double timeTaken = difftime(end, start); // seconds
    int wordCount = strlen(input) / 5;       // Generally getting the average length of word of 5 chars
    double wpm = (timeTaken > 0) ? (wordCount / (timeTaken / 60)) : 0;
    double accuracy = (correct * 100) / strlen(text);

    printf("\n---- Results ----\n");
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Words per minute: %.2f WPM\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);
}