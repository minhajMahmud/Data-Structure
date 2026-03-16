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
// else returns false.
bool detectLoop(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    // **Correction:** Advance fast by two nodes, not one, in each iteration
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // **Correction:** Check for loop detection within the loop
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
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

    if (detectLoop(head))
    {
        printf("Loop Found\n");
    }
    else
    {
        printf("No Loop\n");
    }

    return 0;
}
