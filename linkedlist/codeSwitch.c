#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define ll long long int

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int searchElement(struct Node *head, int target)
{
    struct Node *current = head;
    int position = 1;

    while (current != NULL)
    {
        if (current->data == target)
        {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}
struct Node *insert(struct Node *head, int data) //
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = ptr;
    }

    return head;
}

struct Node *findMiddleOfTheList(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *reverse(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node *curr = head;
    struct Node *prev = NULL;

    while (curr != NULL)
    {
        struct Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int count_element(struct Node *head)
{
    struct Node *newNode = head;
    int count = 0;
    while (newNode != NULL)
    {
        count++;
        newNode = newNode->next;
    }
    return count;
}

int checkPalindrome(struct Node *head)
{
    struct Node *middle = findMiddleOfTheList(head);
    int size = count_element(head);
    struct Node *reverseList;

    if (size % 2 == 0)
    {
        reverseList = reverse(middle);
    }
    else
    {
        reverseList = reverse(middle->next);
    }

    struct Node *curr = head;

    while (reverseList != NULL)
    {
        if (curr->data != reverseList->data)
        {
            return 0;
        }
        curr = curr->next;
        reverseList = reverseList->next;
    }
    return 1;
}

int isPalindrome(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 1;
    }
    return checkPalindrome(head);
}

struct Node *delete(struct Node *head) // ending
{
    struct Node *ptr = head;
    struct Node *p = head->next;

    while (p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }

    ptr->next = NULL;
    free(p);
    return head;
}

int main()
{
    struct Node *head = NULL;

    while (1)
    {
        printf("[1] Insert Item.\n[2] Display.\n[3] Search An Item.\n[4] Delete.\n[5] Reverse.\n[6] Count Element.\n[7] Palindrome.\n[8] Duplicate Element.\n[9] Exit.\n");
        printf("Enter Choice: ");
        int n;
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter elements for the linked list (enter -1 to stop):\n");
            int data;
            while (1)
            {
                // printf("Enter element: ");
                scanf("%d", &data);

                if (data == -1)
                {
                    break;
                }

                head = insert(head, data);
            }
            break;

        case 2:
            display(head);
            break;
        case 3:
            printf("Enter element to search: ");
            int target, position;
            scanf("%d", &target);
            position = searchElement(head, target);
            if (position != -1)
            {
                printf("Element %d found at position %d\n", target, position);
            }
            else
            {
                printf("Element not found in the list\n");
            }
            break;
        case 4:
            head = delete (head);
            break;
        case 5:
            // struct Node *temp = reverse(head);
            head = reverse(head);
            break;
        case 6:
            printf("Size: %d", count_element(head));
            break;
        case 7:
            if (isPalindrome(head))
            {
                printf("Palindrome\n");
            }
            else
                printf("Not palindromed\n");
            break;

        case 9:
            return 0;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }
}