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

int searchElement(struct Node *head, int target)
{
    struct Node *current = head;
    int position = 1;

    while (current != NULL)
    {
        if (current->data == target)
        {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // allocate memory for nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // first node
    head->data = 4;
    head->next = second;

    // second node
    second->data = 3;
    second->next = third;

    // third node
    third->data = 8;
    third->next = fourth;

    // fourth node
    fourth->data = 1;
    fourth->next = NULL;

    linkedlistTraversal(head);

    int targetElement = 3;
    int position = searchElement(head, targetElement);

    if (position != -1)
    {
        printf("Element %d found at position %d\n", targetElement, position);
    }
    else
    {
        printf("Element %d not found in the list\n", targetElement);
    }

    return 0;
}
