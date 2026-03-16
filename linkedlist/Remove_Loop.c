#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = (Node *)malloc(sizeof(Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list to the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// Returns true if there is a loop in linked list
// and removes the loop, else returns false.
bool detectAndRemoveLoop(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *prev = NULL; // To keep track of the previous node for removing the loop

    // Move slow and fast pointers to find the meeting point
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Loop detected, remove the loop
            removeLoop(head, slow, prev);
            return true;
        }
    }

    return false;
}

// Function to remove the loop in the linked list
void removeLoop(struct Node *head, struct Node *loopNode, struct Node *prev)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = loopNode;

    // Move one pointer to the head of the list
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        prev = ptr2;
        ptr2 = ptr2->next;
    }

    // Move the other pointer to the last node of the loop
    while (ptr2->next != loopNode)
    {
        ptr2 = ptr2->next;
    }

    // Break the loop
    ptr2->next = NULL;
}

int main()
{
    /* Start with the empty list */
    struct Node *head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    if (detectAndRemoveLoop(head))
    {
        printf("Loop Removed\n");
    }
    else
    {
        printf("No Loop\n");
    }

    return 0;
}
