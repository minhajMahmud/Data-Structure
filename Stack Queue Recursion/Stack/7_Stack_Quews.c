#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Queue
{
    int front;
    int rear;
    int items[MAX];
};

struct Stack
{
    int top;
    int items[MAX];
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = 0;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf(" Queue is full!\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf(" Queue is empty!\n");
        return -1;
    }
    return q->items[q->front++];
}

void initStack(struct Stack *s)
{
    s->top = -1;
}

void push(struct Stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf(" Stack overflow!\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

int pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf(" Stack underflow!\n");
        return -1;
    }
    return s->items[s->top--];
}

void printQueue(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf(" Queue is empty!\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = q->front + 1; i <= q->rear; ++i)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

void printStack(struct Stack *s)
{
    if (s->top == -1)
    {
        printf(" Stack is empty!\n");
        return;
    }

    printf("Stack contents: ");
    for (int i = 0; i <= s->top; ++i)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    struct Stack s;
    int choice, value;

    initQueue(&q);
    initStack(&s);

    while (1)
    {
        printf("1. Push\n2. Pop\n3. Print Queue\n4. Print Stack\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;

        case 2:
            while (q.front != q.rear)
            {
                value = dequeue(&q);
                push(&s, value);
            }
            value = pop(&s);
            if (value != -1)
            {
                printf("Popped value: %d\n", value);
            }
            break;

        case 3:
            printQueue(&q);
            break;

        case 4:
            printStack(&s);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
