#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *moveFirstToEnd(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        // If the list is empty or has only one element, nothing to move.
        return head;
    }

    struct Node *first = head;
    struct Node *second = head->next;
    struct Node *p = head;

    // Traverse the list to find the last node.
    while (p->next != NULL)
    {
        p = p->next;
    }

    // Move the first node to the end.
    p->next = first;
    head = second;
    first->next = NULL;

    return head;
}

int main()
{
    struct Node *head = NULL;
    struct Node *last = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    printf("Linked List before moving first element to end:\n");
    linkedlistTraversal(head);

    // Move the first element to the end.
    head = moveFirstToEnd(head);

    printf("Linked List after moving first element to end:\n");
    linkedlistTraversal(head);

    return 0;
}
