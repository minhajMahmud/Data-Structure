#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct
{
    int top;
    int elements[MAX_STACK_SIZE];
} Stack;

void init_stack(Stack *stack)
{
    stack->top = -1;
}

int is_empty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int element)
{
    if (stack->top == MAX_STACK_SIZE - 1)
    {
        printf("Stack overflow.\n");
        exit(1);
    }

    stack->top++;
    stack->elements[stack->top] = element;
}

int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack underflow.\n");
        exit(1);
    }

    int element = stack->elements[stack->top];
    stack->top--;
    return element;
}

int main()
{
    Stack stack;

    init_stack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));

    return 0;
}
