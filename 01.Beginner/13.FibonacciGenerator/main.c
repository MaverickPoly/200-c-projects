#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll fibonacciN(int n)
{
    if (n <= 2)
        return 1;
    return fibonacciN(n - 1) + fibonacciN(n - 2);
}

ll *generateFibonacci(int n)
{
    ll *res = (ll *)malloc(n * sizeof(ll));

    for (int i = 0; i < n; i++)
        res[i] = fibonacciN(i + 1);

    return res;
}

int main()
{
    int n;
    printf("How many fibonacci numbers to generate? ");
    scanf("%d", &n);

    ll *result = generateFibonacci(n);

    for (int i = 0; i < n; i++)
        printf("%lld ", result[i]);

    free(result);

    return 0;
}