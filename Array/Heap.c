#include <stdio.h>
#include <stdlib.h>

void heap(int arr[], int n, int i)
{
    int larg = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[larg])
    {
        larg = l;
    }

    if (r < n && arr[r] > arr[larg])
    {
        larg = r;
    }

    if (larg != i)
    {
        int temp = arr[i];
        arr[i] = arr[larg];
        arr[larg] = temp;
        heap(arr, n, larg);
    }
}

void buildheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heap(arr, n, i);
    }
}

void printHeap(int arr[], int n)
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
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Heap array: ");
    printHeap(arr, n);

    buildheap(arr, n);

    printf("Sorted array: ");
    printHeap(arr, n);

    return 0;
}
