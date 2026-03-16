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
    printf("Linked List:\n");
    linkedlistTraversal(head);

    return 0;
}
5