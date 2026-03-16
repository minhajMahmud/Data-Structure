#include <stdio.h>
void left_rotate_array(int arr[], int size, int rotations)
{
  int temp_arr[size];
  for (int i = 0; i < size; ++i)
  {
    temp_arr[(i + rotations) % size] = arr[i];
  }
  for (int i = 0; i < size; ++i)
  {
    arr[i] = temp_arr[i];
  }
}
int main()
{
  int size, rotations;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter elements of the array: ");
  for (int i = 0; i < size; ++i)
  {
    scanf("%d", &arr[i]);
  }
  printf("Enter the number of rotations: ");
  scanf("%d", &rotations);
  left_rotate_array(arr, size, rotations);
  printf("Rotated array: ");
  for (int i = 0; i < size; ++i)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
