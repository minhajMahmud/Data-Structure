#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

// Function to insert an element at the bottom of the stack
void insertAtBottom(int item)
{
    // Base case: if the stack is empty, push the item
    if (top == -1)
    {
        push(item);
    }
    else
    {
        // Recursive case: pop all items and insert the item at the bottom
        int temp = pop();
        insertAtBottom(item);

        // Push the popped items back onto the stack
        push(temp);
    }
}

// Function to reverse a stack using recursion
void reverseStack()
{
    // Base case: if the stack is not empty, pop an item
    if (top != -1)
    {
        int item = pop();

        // Reverse the remaining stack
        reverseStack();

        // Insert the popped item at the bottom of the stack
        insertAtBottom(item);
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("1. Push\n2. Pop\n3. Reverse Stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            value = pop();
            if (value != -1)
            {
                printf("Popped value: %d\n", value);
            }
            break;

        case 3:
            reverseStack();
            printf("Stack reversed!\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
