#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev; // Added previous pointer for a doubly linked list
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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    if (head != NULL)
        head->prev = ptr;

    return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) // check list is empty or not
    {
        ptr->prev = NULL;
        return ptr;
    }

    struct Node *p = head; // traverse full list
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr; // insert at end newnode
    ptr->prev = p;

    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;

    if (p->next != NULL)
        p->next->prev = ptr;

    p->next = ptr;

    return head;
}

int main()
{
    struct Node *head = NULL;

    // Insert at the beginning
    int newDataAtFirst = 7;
    head = insertAtFirst(head, newDataAtFirst);

    // Insert at a specific index (e.g., index 1)
    int newDataAtIndex = 6;
    head = insertAtIndex(head, newDataAtIndex, 1);

    // Insert at the end
    int newDataAtEnd = 9;
    head = insertAtEnd(head, newDataAtEnd);

    printf("After insertion:\n");
    linkedlistTraversal(head);

    return 0;
}
