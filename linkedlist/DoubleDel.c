#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;  // Added previous pointer for a doubly linked list
    struct Node* next;
};

void linkedlistTraverse(struct Node* ptr) {
    while (ptr != NULL) {
        printf("element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct Node* newHead = head->next;

    if (newHead != NULL) {
        newHead->prev = NULL;  // Update the prev pointer of the new head to NULL
    }

    free(head);
    return newHead;
}

// Case 2: Deleting at index element
struct Node* deleteAtIndex(struct Node* head, int index) {
    struct Node* p = head;
    struct Node* q = head->next;
    
    for (int i = 0; i < index - 1; i++) {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;

    if (q->next != NULL) {
        q->next->prev = p;  // Update the prev pointer of the next node
    }

    free(q);
    return head;
}

// Case 3: Deleting the last element
struct Node* deleteAtLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct Node* p = head;
    struct Node* q = head->next;

    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;

    free(q);
    return head;
}

int main() {
    // ... (unchanged code for creating the doubly linked list)

    linkedlistTraverse(head);

    printf("Before deletion:\n");
    linkedlistTraverse(head);

    // Uncomment and use the following code to delete the first element
    // head = deleteFirst(head);

    // Uncomment and use the following code to delete at a specific index (e.g., index 2)
    // head = deleteAtIndex(head, 2);

    // Uncomment and use the following code to delete the last element
    // head = deleteAtLast(head);

    printf("After deletion:\n");
    linkedlistTraverse(head);

    // Free allocated memory when done
    free(second);
    free(third);
    free(fourth);

    return 0;
}
