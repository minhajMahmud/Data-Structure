#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *head;
    int size;
} Stack;

Stack *initializeStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->size == 0;
}

int push(Stack *stack, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    if (isEmpty(stack))
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = stack->head;
    }
    stack->head = new_node;
    stack->size++;
    return 1;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    int popped_data = stack->head->data;
    Node *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    stack->size--;
    return popped_data;
}

int getMiddleElement(Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    Node *fast = stack->head;
    Node *slow = stack->head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

void printStack(Stack *stack)
{
    Node *temp = stack->head;
    printf("[");
    while (temp)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

int main()
{
    Stack *stack = initializeStack();

    int choice, value;

    while (1)
    {
        printf("\t1. Push\t2. Pop\t3. Get Middle Element\t4. Print Stack\t5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            if (push(stack, value))
            {
                printf("%d pushed successfully!\n", value);
            }
            else
            {
                printf("Stack overflow!\n");
            }
            break;
        case 2:
            value = pop(stack);
            if (value != -1)
            {
                printf("Popped %d from the stack.\n", value);
            }
            else
            {
                printf("Stack underflow!\n");
            }
            break;
        case 3:
            value = getMiddleElement(stack);
            if (value != -1)
            {
                printf("Middle element: %d\n", value);
            }
            else
            {
                printf("Stack is empty!\n");
            }
            break;
        case 4:
            if (!isEmpty(stack))
            {
                printStack(stack);
            }
            else
            {
                printf("Stack is empty!\n");
            }
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }

        if (choice == -1)
        {
            break;
        }
    }

    return 0;
}
