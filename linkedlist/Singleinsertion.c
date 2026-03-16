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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
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
    p->next = ptr;
    return head;
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

    printf("Before insertion:\n");
    linkedlistTraversal(head);

    // Uncomment and use the following code to insert a new node at the beginning
    // int newData = 7;
    // head = insertAtFirst(head, newData);

    // Uncomment and use the following code to insert a new node at a specific index (e.g., index 1)
    // int newDataAtIndex = 6;
    // head = insertAtIndex(head, newDataAtIndex, 1);

    // Insert a new node at the end
    int newData = 9;
    head = insertAtEnd(head, newData);

    printf("After insertion at the end:\n");
    linkedlistTraversal(head);

    return 0;
}
