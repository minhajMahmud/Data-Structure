#include <stdio.h>

// Recursive function to generate the nth Fibonacci number
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;

    // Input the number of terms in the Fibonacci sequence
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid input. Please enter a non-negative integer.\n");
    }
    else
    {
        // Display the Fibonacci sequence
        printf("Fibonacci Sequence up to %d terms: ", n);
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}
