#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top1 = -1; // Top of the first stack
int top2 = MAX; // Top of the second stack

void push1(int value) {
    if (top1 + 1 == top2) {
        printf("Stack 1 overflow!\n");
        return;
    }
    stack[++top1] = value;
}

void push2(int value) {
    if (top2 - 1 == top1) {
        printf("Stack 2 overflow!\n");
        return;
    }
    stack[--top2] = value;
}

int pop1() {
    if (top1 == -1) {
        printf("Stack 1 underflow!\n");
        return -1;
    }
    return stack[top1--];
}

int pop2() {
    if (top2 == MAX) {
        printf("Stack 2 underflow!\n");
        return -1;
    }
    return stack[top2++];
}

void printStacks() {
    if (top1 == -1) {
        printf("Stack 1 is empty!\n");
    } else {
        printf("Stack 1 contents: ");
        for (int i = 0; i <= top1; ++i) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    if (top2 == MAX) {
        printf("Stack 2 is empty!\n");
    } else {
        printf("Stack 2 contents: ");
        for (int i = MAX - 1; i >= top2; --i) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Push into Stack 1\n2. Pop from Stack 1\n");
        printf("3. Push into Stack 2\n4. Pop from Stack 2\n5. Print Stacks\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push into Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;

            case 2:
                value = pop1();
                if (value != -1) {
                    printf("Popped value from Stack 1: %d\n", value);
                }
                break;

            case 3:
                printf("Enter value to push into Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;

            case 4:
                value = pop2();
                if (value != -1) {
                    printf("Popped value from Stack 2: %d\n", value);
                }
                break;

            case 5:
                printStacks();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
