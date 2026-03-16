#include <stdio.h>
#include <stdlib.h>

#define maxNode 4

typedef struct Node {
    int vertexNum;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *adjlist[maxNode] = { 0 };

void addNode(int s, int d) {
    Node *src, *dest, *tmp;

    if (adjlist[s]->head == NULL) {
        src = (Node *)malloc(sizeof(Node));
        src->vertexNum = s;
        src->next = NULL;
        adjlist[s]->head = src;
    }

    dest = (Node *)malloc(sizeof(Node));
    dest->vertexNum = d;
    dest->next = NULL;

    tmp = adjlist[s]->head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = dest;
}

void printList() {
    printf("Adjacency List:\n");

    for (int i = 0; i < maxNode; i++) {
        Node *current = adjlist[i]->head;
        printf("Node %d: ", i);

        while (current != NULL) {
            printf("%d ", current->vertexNum);
            current = current->next;
        }

        printf("\n");
    }
}

int main() {
    int s, d;
    int i;

    for (i = 0; i < maxNode; i++) {
        adjlist[i] = (List *)malloc(sizeof(List));
        adjlist[i]->head = NULL;
    }

    // User input for adding nodes
    printf("Enter source and destination vertices (enter -1 -1 to stop):\n");
    while (1) {
        scanf("%d %d", &s, &d);

        if (s == -1 && d == -1) {
            break;
        }

        addNode(s, d);
    }

    printList();

    return 0;
}
