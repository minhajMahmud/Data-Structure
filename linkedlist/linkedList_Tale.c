#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void reversePrint(struct Node *head)
{
    int top = -1;
    int s[100];

    struct Node *temp = head;
    while (temp != NULL)
    {
        s[++top] = temp->data;
        temp = temp->next;
    }
    printf("Reversed Linked List: ");
    while (top >= 0)
    {
        printf("%d -> ", s[top--]);
    }
    printf("NULL\n");
}

int main()
{
    int t;
    printf("Enter the number of nodes: ");
    scanf("%d", &t);
    struct Node *head = NULL, *newnode, *temp;
    while (t--)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    printf(" Linked List: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    reversePrint(head);

    return 0;
}
