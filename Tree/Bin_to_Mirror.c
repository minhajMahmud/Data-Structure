#include <stdio.h>
#include <stdlib.h>

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
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to convert a binary tree into its mirror tree
void mirrorTree(struct Node *root)
{
    if (root == NULL)
        return;

    // Swap left and right subtrees
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Function to perform in-order traversal of a binary tree
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    // Example usage
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Print the original tree
    printf("Original Tree (In-Order Traversal): ");
    inOrderTraversal(root);
    printf("\n");

    // Convert the tree into its mirror
    mirrorTree(root);

    // Print the mirrored tree
    printf("Mirror Tree (In-Order Traversal): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
