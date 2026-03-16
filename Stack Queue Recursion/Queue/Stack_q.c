#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// Function to create a new stack
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack overflow. Cannot push %d.\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow. Cannot pop.\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

// Structure to represent a queue using two stacks
struct QueueUsingStacks
{
    struct Stack *stack1; // For enqueue operation
    struct Stack *stack2; // For dequeue operation
};

// Function to create a new queue using two stacks
struct QueueUsingStacks *createQueue()
{
    struct QueueUsingStacks *queue = (struct QueueUsingStacks *)malloc(sizeof(struct QueueUsingStacks));
    queue->stack1 = createStack(100);
    queue->stack2 = createStack(100);
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct QueueUsingStacks *queue, int item)
{
    push(queue->stack1, item);
    printf("%d enqueued to the queue.\n", item);
}

// Function to dequeue an element from the queue
int dequeue(struct QueueUsingStacks *queue)
{
    if (isEmpty(queue->stack2))
    {
        // If stack2 is empty, transfer elements from stack1 to stack2
        while (!isEmpty(queue->stack1))
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    if (isEmpty(queue->stack2))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }

    return pop(queue->stack2);
}

// Function to display the elements in the queue
void display(struct QueueUsingStacks *queue)
{
    printf("Queue elements: ");
    while (!isEmpty(queue->stack2) || !isEmpty(queue->stack1))
    {
        if (!isEmpty(queue->stack2))
        {
            printf("%d ", pop(queue->stack2));
        }
        else
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    printf("\n");
}

// Function to free the memory allocated for the queue
void freeQueue(struct QueueUsingStacks *queue)
{
    free(queue->stack1->array);
    free(queue->stack1);
    free(queue->stack2->array);
    free(queue->stack2);
    free(queue);
}

int main()
{
    // Create a queue using two stacks
    struct QueueUsingStacks *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    display(queue);

    int dequeued = dequeue(queue);
    printf("%d dequeued from the queue.\n", dequeued);

    display(queue);

    freeQueue(queue);

    return 0;
}
