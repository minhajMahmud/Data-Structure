#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the end of the linked list
struct Node *insertNode(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

// Function to find the nth node from the end of the linked list
struct Node *nthNodeFromEnd(struct Node *head, int n)
{
    if (head == NULL || n <= 0)
    {
        printf("Invalid input\n");
        return NULL;
    }

    struct Node *first = head;
    struct Node *second = head;

    // Move the first pointer n nodes ahead
    for (int i = 0; i < n; ++i)
    {
        if (first == NULL)
        {
            printf("Invalid value of n\n");
            return NULL;
        }
        first = first->next;
    }

    // Move both pointers until the first pointer reaches the end
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    return second;
}

// Function to display the linked list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int val, n;

    // Input values for the linked list (enter -1 to stop)
    printf("Enter the values for the linked list (enter -1 to stop):\n");
    while (1)
    {
        scanf("%d", &val);
        if (val == -1)
            break;
        head = insertNode(head, val);
    }

    // Display the original linked list
    printf("Original Linked List: ");
    displayList(head);

    // Input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Find the nth node from the end
    struct Node *result = nthNodeFromEnd(head, n);

    if (result != NULL)
        printf("The %dth node from the end is: %d\n", n, result->data);

    return 0;
}
