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

// Function to find the maximum depth (height) of a binary tree
int findMaxDepth(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // Recursively calculate the depth of the left and right subtrees
        int leftDepth = findMaxDepth(root->left);
        int rightDepth = findMaxDepth(root->right);

        // Return the maximum depth among the left and right subtrees, plus 1 for the current node
        if(leftDepth > rightDepth){
            return leftDepth + 1;
        }else{
            return rightDepth + 1;
        }
       //return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
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

    // Find and print the maximum depth of the binary tree
    int maxDepth = findMaxDepth(root);
    printf("Maximum Depth of the Binary Tree: %d\n", maxDepth);

    return 0;
}
