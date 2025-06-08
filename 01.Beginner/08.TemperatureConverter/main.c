#include <stdio.h>

void getInput(char *target, float *temp)
{
    printf("Enter temperature in %s: ", target);
    scanf("%f", temp);
}

int main()
{
    printf("====== Temperature Converter ======\n\n");

    int option;
    char again;
    float temp, result;

    while (1)
    {
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("Select an option: ");
        scanf("%d", &option);

        if (option == 1)
        {
            getInput("Celsius", &temp);
            result = temp * 9 / 5 + 32;
            printf("%.1f C = %.1f F\n", temp, result);
        }
        else if (option == 2)
        {
            getInput("Fahrenheit", &temp);
            result = (temp - 32) * 5 / 9;
            printf("%.1f F = %.1f C\n", temp, result);
        }
        else
        {
            printf("Invalid option!\n");
        }

        printf("\nQuit(y/n)? ");
        scanf(" %c", &again);
        if (again == 'y' || again == 'Y')
            goto end;
    }

end:
    printf("Thanks for convertions!\n");
    return 0;
}
