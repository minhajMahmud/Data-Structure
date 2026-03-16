#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check whether a binary tree is complete or not
int isComplete(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 1; // An empty tree is considered complete
    }

    // Create a queue for level order traversal
    struct TreeNode **queue = (struct TreeNode **)malloc(100 * sizeof(struct TreeNode *));
    int front = 0, rear = 0;
    int flag = 0; // Flag to indicate if a non-full node is encountered

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear)
    {
        struct TreeNode *current = queue[front++];

        // If a non-full node is encountered after a full node, the tree is not complete
        if (current == NULL)
        {
            flag = 1;
        }
        else
        {
            if (flag)
            {
                free(queue);
                return 0;
            }

            // Enqueue left and right children
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }

    free(queue);

    return 1; // If the loop completes without returning, the tree is complete
}

int main()
{
    // Create a sample binary tree
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    // Check if the binary tree is complete
    if (isComplete(root))
    {
        printf("The binary tree is complete.\n");
    }
    else
    {
        printf("The binary tree is not complete.\n");
    }

    // Free the memory allocated for the tree
    // Note: In a real-world scenario, you would typically use a function to free the entire tree
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
