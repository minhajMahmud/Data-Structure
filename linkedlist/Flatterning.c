#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node
{
    int data;
    struct Node *next, *bottom;
};

struct Node *head = NULL;

// Utility function to merge two sorted linked lists
struct Node *merge(struct Node *a, struct Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    struct Node *result;

    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL;
    return result;
}

// Utility function to flatten a given linked list
struct Node *flatten(struct Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

// Utility function to insert a node at the beginning of the linked list
struct Node *push(struct Node *head_ref, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->bottom = head_ref;
    head_ref = new_node;
    return head_ref;
}

// Utility function to print the linked list
void printList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->bottom;
    }
    printf("\n");
}

// Driver's code
int main()
{
    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);

    head->next = push(head->next, 20);
    head->next = push(head->next, 10);

    head->next->next = push(head->next->next, 50);
    head->next->next = push(head->next->next, 22);
    head->next->next = push(head->next->next, 19);

    head->next->next->next = push(head->next->next->next, 45);
    head->next->next->next = push(head->next->next->next, 40);
    head->next->next->next = push(head->next->next->next, 35);
    head->next->next->next = push(head->next->next->next, 28);

    head = flatten(head);

    printList();
    return 0;
}
