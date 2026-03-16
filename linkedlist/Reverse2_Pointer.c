#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertNode(int pos, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Insert not possible\n");
        return;
    }

    temp->data = x;

    if (pos == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        int i = 1;
        struct Node *thptr = head;
        while (i < pos - 1)
        {
            thptr = thptr->next;
            i++;
        }
        temp->next = thptr->next;
        thptr->next = temp;
    }
}

void reverseList()
{
    struct Node *current = head;
    struct Node *next;
    struct Node *prev = NULL;

    while (current != NULL)
    {
        next = current->next; // Line 1
        current->next = prev; // Line 2
        prev = current;       // Line 3
        current = next;       // Line 4
    }

    head = prev;
}

void print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    insertNode(1, 10);
    insertNode(2, 20);
    insertNode(3, 30);
    insertNode(4, 40);
    insertNode(5, 50);

    reverseList();
    print();

    return 0;
}
