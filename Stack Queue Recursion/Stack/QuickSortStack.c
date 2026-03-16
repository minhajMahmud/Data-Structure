#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct StackNode
{
    int low;
    int high;
} StackNode;

typedef struct Stack
{
    int top;
    StackNode *arr[MAX];
} Stack;

void push(Stack *stack, int low, int high)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = (StackNode *)malloc(sizeof(StackNode));
    stack->arr[stack->top]->low = low;
    stack->arr[stack->top]->high = high;
}

StackNode *pop(Stack *stack)
{
    if (stack->top == -1)
    {
        return NULL;
    }
    StackNode *node = stack->arr[stack->top--];
    return node;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSortTwoStacks(int arr[], int n)
{
    Stack leftStack, rightStack;
    leftStack.top = -1;
    rightStack.top = -1;

    push(&leftStack, 0, n - 1);

    while (leftStack.top >= 0)
    {
        StackNode *left = pop(&leftStack);
        int low = left->low;
        int high = left->high;
        free(left);

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low)
        {
            push(&leftStack, low, pivotIndex - 1);
        }

        if (pivotIndex + 1 < high)
        {
            push(&rightStack, pivotIndex + 1, high);
        }
    }

    while (rightStack.top >= 0)
    {
        StackNode *right = pop(&rightStack);
        int low = right->low;
        int high = right->high;
        free(right);

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low)
        {
            push(&leftStack, low, pivotIndex - 1);
        }

        if (pivotIndex + 1 < high)
        {
            push(&rightStack, pivotIndex + 1, high);
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Array size exceeds stack capacity!\n");
        return 1;
    }

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    printArray(arr, n);

    quickSortTwoStacks(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
