#include <stdio.h>
#include <math.h> // 'pow' function

void getNumbers(float *num1, float *num2)
{
    printf("Enter number 1: ");
    scanf("%f", num1);

    printf("Enter number 2: ");
    scanf("%f", num2);
}

int main()
{
    printf("====== Welcome to a scientific calculator! ======\n");

    int option;
    float num1, num2, result;

    while (1)
    {
        printf("\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Modulos\n");
        printf("6. Power\n");
        printf("7. Quit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        if (option == 7)
            goto end;

        if (option < 1 || option > 7)
        {
            printf("Invalid option!\n");
            continue;
        }

        getNumbers(&num1, &num2);

        switch (option)
        {
        case 1:
            result = num1 + num2;
            printf("%.1f + %.1f = %.1f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("%.1f - %.1f = %.1f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("%.1f * %.1f = %.1f\n", num1, num2, result);
            break;
        case 4:
            result = num1 / num2;
            printf("%.1f / %.1f = %.1f\n", num1, num2, result);
            break;
        case 5:
            result = (int)num1 % (int)num2;
            printf("%.1f mod %.1f = %.1f\n", num1, num2, result);
            break;
        case 6:
            result = pow(num1, num2);
            printf("%.1f ** %.1f = %.1f\n", num1, num2, result);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    }

end:
    printf("\nThanks for calculation! Take care!\n");
    return 0;
}
