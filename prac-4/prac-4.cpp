#include <stdio.h>

int fibonacci(int n)
{
    if(n == 0 || n == 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i;

    printf("Enter a number n: ");
    scanf("%d", &n);

    printf("Fibonacci series up to %d:\n", n);
    for(i = 0; i <= n; i++)
        printf("%d ", fibonacci(i));

    printf("\nFibonacci of %d is: %d\n", n, fibonacci(n));

    return 0;
}
