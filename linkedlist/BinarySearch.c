#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Function to perform binary search in a sorted linked list
struct Node *binarySearch(struct Node *head, int target)
{
    struct Node *low = head;
    struct Node *high = NULL;

    // Find the length of the linked list
    int length = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    high = temp = head;

    // Binary search
    while (low != NULL && high != NULL && low != high->next)
    {
        int midIndex = (length - 1) / 2;
        struct Node *mid = temp;

        // Move mid to the middle of the remaining linked list
        for (int i = 0; i < midIndex; i++)
        {
            mid = mid->next;
        }

        if (mid->data == target)
        {
            return mid; // Target found
        }
        else if (mid->data < target)
        {
            low = mid->next; // Adjust the low pointer
        }
        else
        {
            high = mid; // Adjust the high pointer
        }
    }

    return NULL; // Target not found
}

// Function to print the linked list
void printLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int data;

    // Take user input for creating a sorted linked list
    printf("Enter elements for the sorted linked list (enter -1 to stop):\n");
    while (1)
    {
        printf("Enter element: ");
        scanf("%d", &data);

        if (data == -1)
        {
            break; // Stop taking input if -1 is entered
        }

        head = insertAtEnd(head, data);
    }

    printf("Linked List: ");
    printLinkedList(head);

    // Perform binary search
    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    struct Node *result = binarySearch(head, target);

    if (result != NULL)
    {
        printf("Element %d found in the linked list.\n", target);
    }
    else
    {
        printf("Element %d not found in the linked list.\n", target);
    }

    return 0;
}
