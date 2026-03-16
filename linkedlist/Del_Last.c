#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to insert a node at the end of the linked list
void insertEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void deleteLastOccurrence(Node **head, int key)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = *head;
    Node *lastOccur = NULL;
    Node *prevLastOccur = NULL;

    // Traverse the list to find the last occurrence and the node before it
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == key)
        {
            prevLastOccur = lastOccur;
            lastOccur = temp;
        }
        temp = temp->next;
    }

    // Check if the last occurrence is found (including the last node)
    if (lastOccur != NULL && lastOccur->data == key)
    {
        // If the last occurrence is the first node, update the head
        if (lastOccur == *head)
        {
            *head = lastOccur->next;
        }
        else
        {
            // Update the next pointer of the node before the last occurrence
            prevLastOccur->next = lastOccur->next;
        }

        free(lastOccur); // Free the memory of the last occurrence
        printf("Last occurrence of %d deleted.\n", key);
    }
    else
    {
        printf("Element not found in the list.\n");
    }
}

// Function to free the memory allocated for the linked list
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;

    // Insert elements into the linked list
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 2);
    insertEnd(&head, 4);
    insertEnd(&head, 2);
    insertEnd(&head, 5);

    printf("Original Linked List: ");
    displayList(head);

    int key;
    printf("Enter the element to delete its last occurrence: ");
    scanf("%d", &key);

    deleteLastOccurrence(&head, key);

    printf("Linked List after deletion: ");
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
