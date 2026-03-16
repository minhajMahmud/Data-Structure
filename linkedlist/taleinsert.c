#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    int t;
    int count = 0;
    printf("Enter the numbe nodes: ");
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
    temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
        count++;
    }
    printf(" \n count num is %d \n", count);
    return 0;
}
