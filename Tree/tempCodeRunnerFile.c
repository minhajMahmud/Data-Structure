#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure representing a node in a binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with the given data
struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to insert a value into a binary tree based on comparison
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to perform in-order traversal of a binary tree
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);       // Recursively traverse the left subtree
        printf("%d ", root->data); // Print the data of the current node
        inOrder(root->right);      // Recursively traverse the right subtree
    }
}

// Function to find the node with the minimum value in a BST
struct Node *findMinValueNode(struct Node *root)
{
    struct Node *current = root;

    // Keep traversing left until you reach the leftmost leaf node
    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// Function to check if a binary tree is a Binary Search Tree (BST)
int isBST(struct Node *root, int min, int max)
{
    if (root == NULL)
    {
        return 1; // An empty tree is a BST
    }

    if (root->data < min || root->data > max)
    {
        return 0; // The current node's value is out of bounds
    }

    // Check the left subtree with updated max value
    // Check the right subtree with updated min value
    return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}

int main()
{
    struct Node *root = NULL;
    int val;

    // Input values for the nodes and insert into the binary tree
    printf("Enter the values for the nodes (enter -1 to stop):\n");
    while (1)
    {
        scanf("%d", &val);
        if (val == -1)
            break;
        root = insertNode(root, val);
    }

    printf("In-Order Traversal: ");
    inOrder(root);
    printf("\n");

    // Check if the binary tree is a BST
    if (isBST(root, INT_MIN, INT_MAX))
    {
        printf("The binary tree is a Binary Search Tree (BST).\n");

        // Find and print the node with the minimum value
        struct Node *minNode = findMinValueNode(root);
        if (minNode != NULL)
        {
            printf("Node with minimum value: %d\n", minNode->data);
        }
        else
        {
            printf("The tree is empty.\n");
        }
    }
    else
    {
        printf("The binary tree is not a Binary Search Tree (BST).\n");
    }

    return 0;
}
