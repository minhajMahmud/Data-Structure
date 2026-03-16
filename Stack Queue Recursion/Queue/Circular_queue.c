#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent a circular queue
struct CircularQueue
{
    int front, rear;
    int capacity;
    int *array;
};

// Function to create a new circular queue
struct CircularQueue *createCircularQueue(int capacity)
{
    struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *queue)
{
    return queue->front == -1;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue *queue, int item)
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
    printf("%d enqueued to the circular queue.\n", item);
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue *queue)
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

// Function to display the elements in the circular queue
void display(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = queue->front;
    do
    {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    } while (i != (queue->rear + 1) % queue->capacity);
    printf("\n");
}

// Function to free the memory allocated for the circular queue
void freeCircularQueue(struct CircularQueue *queue)
{
    free(queue->array);
    free(queue);
}

int main()
{
    // Create a circular queue with a maximum capacity of 5
    struct CircularQueue *queue = createCircularQueue(MAX_SIZE);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    display(queue);

    int dequeued = dequeue(queue);
    if (dequeued != -1)
    {
        printf("%d dequeued from the circular queue.\n", dequeued);
    }

    display(queue);

    freeCircularQueue(queue);

    return 0;
}
