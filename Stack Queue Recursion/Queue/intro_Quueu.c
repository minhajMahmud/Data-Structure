#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a queue
struct Queue
{
    int front, rear;
    int capacity;
    int *array;
};

// Function to create a new queue
struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue %d.\n", item);
        return;
    }

    if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }

    queue->array[queue->rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a special value to indicate an error
    }

    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }

    return item;
}

// Function to display the elements in the queue
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    do
    {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    } while (i != (queue->rear + 1) % queue->capacity);
    printf("\n");
}

// Function to free the memory allocated for the queue
void freeQueue(struct Queue *queue)
{
    free(queue->array);
    free(queue);
}

int main()
{
    // Create a queue with a maximum capacity of 10
    struct Queue *queue = createQueue(MAX_SIZE);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    display(queue);

    int dequeued = dequeue(queue);
    if (dequeued != -1)
    {
        printf("%d dequeued from the queue.\n", dequeued);
    }

    display(queue);

    freeQueue(queue);

    return 0;
}
