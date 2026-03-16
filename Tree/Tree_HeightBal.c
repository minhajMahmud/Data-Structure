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
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to insert a value into a binary tree
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

// Function to calculate the height of a binary tree
int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight > rightHeight){
            return leftHeight + 1;
        }
        else{
            return rightHeight + 1;
        }
        //return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Function to check if a binary tree is height-balanced
int isHeightBalanced(struct Node *root)
{
    if (root == NULL)
    {
        return 1; // An empty tree is height-balanced
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Check if the left and right subtrees are height-balanced
    if (abs(leftHeight - rightHeight) <= 1 && isHeightBalanced(root->left) && isHeightBalanced(root->right))
    {
        return 1; // The tree is height-balanced
    }

    return 0; // The tree is not height-balanced
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

    // Check if the binary tree is height-balanced
    if (isHeightBalanced(root))
    {
        printf("The binary tree is height-balanced.\n");
    }
    else
    {
        printf("The binary tree is not height-balanced.\n");
    }

    return 0;
}
