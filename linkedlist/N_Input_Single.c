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
        printf("Element: %d\t", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insert_At_index(int index, struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (index == 0)
    {
        newNode->next = head;
        return newNode;  // Update head for the new first node
    }

    struct Node *temp = head;
    int i = 0;

    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;  // Return the updated head
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

    int index, newData;
    printf("\nEnter index and data for node to insert: ");
    scanf("%d %d", &index, &newData);

    head = insert_At_index(index, head, newData);

    printf("Linked List after insertion at index %d:\n", index);
    linkedlistTraversal(head);

    return 0;
}
