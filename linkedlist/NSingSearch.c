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

    printf("Linked List:\n");
    linkedlistTraversal(head);

    int targetElement;
    printf("Enter the element to search: ");
    scanf("%d", &targetElement);

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
