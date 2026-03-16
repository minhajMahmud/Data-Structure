#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedlistTraverse(struct Node* ptr) {
    while (ptr != NULL) {
        printf("element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// // Case 1: Deleting the first element
// struct Node* deleteFirst(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty. Cannot delete.\n");
//         return NULL;
//     }

//     struct Node* head = head->next;
//     free(head);
//     return head;
// }
// Case 2: Deleting At index element
// struct Node* deleteAtIndex(struct Node* head,int index) {
//     struct Node *p=head;
//     struct Node*q=head->next;
//     for(int i=0;i<index-1;i++){
//         p=p->next;
//         q=q->next;
//     }
//     p->next=q->next;
//     free(q);
//     return head;
// }
// Case 3: Deleting last  element
struct Node* deleteAtLast(struct Node* head) {
    struct Node *p=head;
    struct Node*q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // allocate memory for nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

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

    linkedlistTraverse(head);

    printf("Before deletion:\n");
    linkedlistTraverse(head);

    //head = deleteFirst(head);//delete st first element
   // head=deleteAtIndex(head,2);
   head=deleteAtLast(head);
    printf("After deletion:\n");
    linkedlistTraverse(head);

    // Free allocated memory when done
    free(second);
    free(third);
    free(fourth);

    return 0;
}
