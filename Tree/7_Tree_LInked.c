#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in a linked list
struct ListNode
{
    int data;
    struct ListNode *next;
};

// Structure representing a node in a binary tree
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node for the linked list
struct ListNode *createListNode(int data)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new node for the binary tree
struct TreeNode *createTreeNode(int data)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node at the end of the linked list
struct ListNode *insertListNode(struct ListNode *head, int data)
{
    struct ListNode *newNode = createListNode(data);
    if (head == NULL)
    {
        return newNode;
    }

    struct ListNode *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to print the linked list
void printLinkedList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to convert a linked list to a binary tree
struct TreeNode *listToTree(struct ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct TreeNode *root = createTreeNode(head->data);
    struct ListNode *current = head->next;

    while (current != NULL)
    {
        struct TreeNode *newNode = createTreeNode(current->data);
        newNode->left = root;
        root = newNode;
        current = current->next;
    }

    return root;
}

// Function to perform in-order traversal of a binary tree
void inOrder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct ListNode *head = NULL;
    int val;

    // Input values for the linked list (enter -1 to stop)
    printf("Enter the values for the linked list (enter -1 to stop):\n");
    while (1)
    {
        scanf("%d", &val);
        if (val == -1)
            break;
        head = insertListNode(head, val);
    }

    // Print the linked list
    printf("Linked List: ");
    printLinkedList(head);

    // Convert the linked list to a binary tree
    struct TreeNode *root = listToTree(head);

    // Print the in-order traversal of the binary tree
    printf("In-Order Traversal of the Binary Tree: ");
    inOrder(root);
    printf("\n");

    return 0;
}
