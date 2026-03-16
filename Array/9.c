#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define ARRAY_SIZE 8

void print_array(const char names[][MAX_NAME_LENGTH], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%s", names[i]);
    }
    printf("]\n");
}

int find_element_index(const char names[][MAX_NAME_LENGTH], int size,
                       const char *element)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(names[i], element) == 0)
        {
            return i;
        }
    }
    return -1;
}

int insert_element(char names[][MAX_NAME_LENGTH], int size,
                   const char *element, int position)
{
    if (size >= ARRAY_SIZE)
    {
        printf("Error: Array is full.\n");
        return -1;
    }

    if (position < 0 || position > size)
    {
        printf("Error: Invalid position.\n");
        return -1;
    }

    for (int i = size; i > position; i--)
    {
        strcpy(names[i], names[i - 1]);
    }
    strcpy(names[position], element);

    // Move the return statement here
    return 1;
}

int delete_element(char names[][MAX_NAME_LENGTH], int size, const char *element)
{
    int index = find_element_index(names, size, element);
    if (index == -1)
    {
        printf("Error: Element not found.\n");
        return -1;
    }

    for (int i = index; i < size - 1; i++)
    {
        strcpy(names[i], names[i + 1]);
    }

    // Move the return statement here
    return 1;
}

int main()
{
    char names[][MAX_NAME_LENGTH] = {"Adam", "Clark", "Evans", "Gupta", "Jones",
                                     "Lane", "Pace", "Smith"};

    // Find specific elements
    printf("NAME[2]: %s\n", names[2]);
    printf("NAME[4]: %s\n", names[4]);
    printf("NAME[7]: %s\n", names[7]);

    // Insert element "Davis" into the Array
    insert_element(names, ARRAY_SIZE, "Davis", 3);
    printf("Array after inserting Davis:\n");
    print_array(names, ARRAY_SIZE);

    // Delete element "Gupta"
    delete_element(names, ARRAY_SIZE, "Gupta");
    printf("Array after deleting Gupta:\n");
    print_array(names, ARRAY_SIZE);

    return 0;
}
