#include <stdio.h>
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortEvenOdd(int arr[], int size)
{
    int evenArr[size], oddArr[size];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenArr[evenCount++] = arr[i];
        }
        else
        {
            oddArr[oddCount++] = arr[i];
        }
    }
    bubbleSort(evenArr, evenCount);
    bubbleSort(oddArr, oddCount);
    int index = 0;
    for (int i = 0; i < evenCount; i++)
    {
        arr[index++] = evenArr[i];
    }
    for (int i = 0; i < oddCount; i++)
    {
        arr[index++] = oddArr[i];
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    sortEvenOdd(arr, size);
    printf("Sorted array with even and odd elements separated: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
