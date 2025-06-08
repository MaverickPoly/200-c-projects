#include <stdio.h>

#define MESSAGE_SIZE 100

int main()
{
    FILE *file;
    char message[MESSAGE_SIZE];
    char ch;

    // Write data
    file = fopen("text.txt", "w");
    if (file == NULL)
    {
        printf("Unable to open file in writing mode...\n");
        return 1;
    }
    printf("Enter text to write: ");
    fgets(message, sizeof(message), stdin);
    fputs(message, file);
    fclose(file);
    printf("Contents written to file successfully!\n");

    // Read Data
    file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open file in reading mode...\n");
        return 1;
    }
    printf("\nReading from file:\n");
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    fclose(file);

    return 0;
}
