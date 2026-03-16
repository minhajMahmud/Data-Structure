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

struct Node *moveLastToFront(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        // If the list is empty or has only one element, nothing to move.
        return head;
    }

    struct Node *secondLast = NULL;
    struct Node *p = head;

    // Traverse the list to find the last and second last nodes.
    while (p->next != NULL)
    {
        secondLast = p;
        p = p->next;
    }

    // Move the last node to the front.
    secondLast->next = NULL;
    p->next = head;
    head = p;

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

    printf("Linked List before moving last element to front:\n");
    linkedlistTraversal(head);

    // Move the last element to the front.
    head = moveLastToFront(head);

    printf("Linked List after moving last element to front:\n");
    linkedlistTraversal(head);

    return 0;
}
