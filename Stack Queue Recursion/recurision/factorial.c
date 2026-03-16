#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int n;

    // Input the value of n
    printf("Enter a non-negative integer (n): ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid input. Please enter a non-negative integer.\n");
    }
    else
    {
        // Calculate and display the factorial of n
        printf("%d! = %llu\n", n, factorial(n));
    }

    return 0;
}
