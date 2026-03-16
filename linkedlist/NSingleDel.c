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
struct Node *delatlast(struct Node *head)
{
    struct Node *p = head;       // p head ke point krtcee
    struct Node *q = head->next; // q head ke next ke point krtcee
    while (q->next != NULL)
    {
        p = p->next; // ek ek kore baracce untile the ager index
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
/*
struct Node *deleteAtFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
*/
/*
struct Node *indexdelete(struct Node *head, int index)
{
    struct Node *p = head;       // p head ke point krtcee
   
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next; // ek ek kore baracce untile the ager index
        
    }
    struct Node* deleteNode=p->next;
    p->next = p->next->next;
    free(deleteNode);
    return head;
}
*/
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
    /* delete at first
        printf("Linked List:\n");
        linkedlistTraversal(head);

        head = deleteAtFirst(head);


    printf("New Linked List after deleting first element:\n");
        linkedlistTraversal(head);
        */
    /* delete at index
 int index;
 scanf("%d", &index);
 head = indexdelete(head,index);
 linkedlistTraversal(head);
*/
    head = delatlast(head);
    linkedlistTraversal(head);
    return 0;
}
