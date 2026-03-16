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

// Function to check if two binary trees are identical
int areIdentical(struct Node *root1, struct Node *root2)
{
    // If both trees are empty, they are identical
    if (root1 == NULL && root2 == NULL)
        return 1;

    // If one tree is empty and the other is not, they are not identical
    if (root1 == NULL&& root2 != NULL|| root1 != NULL && root2 == NULL)
        return 0;

    // Check if the current nodes have the same value
    // and recursively check the left and right subtrees
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

int main()
{
    struct Node *root1 = NULL;
    struct Node *root2 = NULL;
    int val;

    // Input values for the nodes and insert into the first binary search tree
    printf("Enter the values for the nodes of the first tree (enter -1 to stop):\n");
    while (1)
    {
        scanf("%d", &val);
        if (val == -1)
            break;
        root1 = insertNode(root1, val);
    }

    // Input values for the nodes and insert into the second binary search tree
    printf("Enter the values for the nodes of the second tree (enter -1 to stop):\n");
    while (1)
    {
        scanf("%d", &val);
        if (val == -1)
            break;
        root2 = insertNode(root2, val);
    }

    // Performing in-order traversal and printing the result for the first tree
    printf("In-Order Traversal of the first tree: ");
    inOrder(root1);
    printf("\n");

    // Performing in-order traversal and printing the result for the second tree
    printf("In-Order Traversal of the second tree: ");
    inOrder(root2);
    printf("\n");

    // Check if the trees are identical
    if (areIdentical(root1, root2))
    {
        printf("The two trees are identical.\n");
    }
    else
    {
        printf("The two trees are not identical.\n");
    }

    return 0;
}
