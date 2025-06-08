#include <stdlib.h>
#include <stdio.h>

int isPrime(int i)
{
    if (i < 2)
        return 0;

    if (i <= 3)
        return 1;

    if (i % 2 == 0 || i % 3 == 0)
        return 0;

    int n = 5;
    while (n * n <= i)
    {
        if (i % n == 0 || i % (n + 2) == 0)
            return 0;
        n += 6;
    }
    return 1;
}

long *generatePrimeNumbers(int n)
{
    long *primeNumbers = (long *)malloc(n * sizeof(long));
    int size = 0;
    int i = 2;
    while (size != n)
    {
        if (isPrime(i))
        {
            primeNumbers[size] = i;
            size++;
        }
        i++;
    }
    return primeNumbers;
}

int main()
{
    int n;
    printf("Enter number of prime numbers to generate: ");
    scanf("%d", &n);

    long *primeNumbers = generatePrimeNumbers(n);

    printf("Generated %d prime numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", primeNumbers[i]);
    }

    free(primeNumbers);
    return 0;
}
