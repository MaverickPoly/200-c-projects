#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int convertToDecimal(const char *binary)
{
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++)
    {
        if (binary[i] == '1')
            decimal += pow(2, length - i - 1);
        else if (binary[i] != '0')
            return -1;
    }
    return decimal;
}

int main()
{
    int running = 1;
    char binary[65];
    char again;

    while (running)
    {
        printf("\nEnter binary number: ");
        scanf("%64s", &binary);

        int decimal = convertToDecimal(binary);

        if (decimal == -1)
            printf("Invalid binary number!\n");
        else
            printf("%s => %d\n", binary, decimal);

        printf("\nAgain(y/n)? ");
        scanf(" %c", &again);

        if (tolower(again) == 'n')
            running = 0;
    }

    printf("Bye bye...\n");
    return 0;
}
