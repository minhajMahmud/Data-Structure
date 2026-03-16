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
        printf("Element: %d ", ptr->data);
        ptr = ptr->next;
    }
}

void removeDuplicates(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            struct Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *last = NULL;
    int n, data;

    printf("Enter the data for nodes (enter -1 to stop):\n");

    while (1)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        if (data == -1)
        {
            break;
        }

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

    printf("Linked List before removing duplicates:\n");
    linkedlistTraversal(head);

    removeDuplicates(head);

    printf("Linked List after removing duplicates:\n");
    linkedlistTraversal(head);

    return 0;
}
