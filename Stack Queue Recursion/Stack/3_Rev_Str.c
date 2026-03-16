#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Stack implementation
char stack[MAX];
int top = -1;

void push(char value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack[top--];
}

// Function to reverse a string using a stack
void reverseString(char str[])
{
    // Push each character onto the stack
    for (int i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }

    // Pop each character from the stack to reverse the string
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = pop();
    }
}

int main()
{
    char str[MAX];

    // Input the string
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character

    // Reverse the string using a stack
    reverseString(str);

    // Display the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
