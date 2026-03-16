#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int element;
    struct Node *next;
} Node;

typedef struct
{
    struct Node *head;
} Stack;

void init_stack(Stack *stack)
{
    stack->head = NULL;
}

int is_empty(Stack *stack)
{
    return stack->head == NULL;
}

void push(Stack *stack, int element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->element = element;
    new_node->next = stack->head;
    stack->head = new_node;
}

int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack underflow.\n");
        exit(1);
    }

    Node *head = stack->head;
    int element = head->element;
    stack->head = head->next;
    free(head);
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
