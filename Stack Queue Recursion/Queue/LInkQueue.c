#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Structure to represent a linked list queue
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (queue == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the linked list queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

// Function to enqueue an element into the linked list queue
void enqueue(struct Queue *queue, int item)
{
    struct Node *newNode = createNode(item);

    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enqueued to the queue.\n", item);
}

// Function to dequeue an element from the linked list queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *frontNode = queue->front;
    int item = frontNode->data;

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = NULL;
    }
    else
    {
        queue->front = frontNode->next;
    }

    free(frontNode);
    return item;
}

// Function to display the elements in the linked list queue
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node *current = queue->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list queue
void freeQueue(struct Queue *queue)
{
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}

int main()
{
    // Create a linked list queue
    struct Queue *queue = createQueue();

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
