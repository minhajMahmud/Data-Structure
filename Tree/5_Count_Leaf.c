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
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to insert a value into a Binary Search Tree (BST)
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
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// Function to count leaf nodes in a binary tree
int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1; // Current node is a leaf
    }
    else
    {
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int val;

    // Input values for the nodes and insert into the binary search tree
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

    // Counting leaf nodes and printing the result
    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}
