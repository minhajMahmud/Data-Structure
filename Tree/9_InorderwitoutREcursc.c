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

// Function for in-order tree traversal without recursion and without stack
void morrisInOrderTraversal(struct Node *root)
{
    struct Node *current = root;
    struct Node *predecessor = NULL;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            printf("%d ", current->data);
            current = current->right;
        }
        else
        {
            // Find the in-order predecessor
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL)
            {
                // Make current as the right child of its in-order predecessor
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                // Revert the changes made in the 'if' part to restore the original tree
                predecessor->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
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

    printf("In-Order Traversal: ");
    morrisInOrderTraversal(root);
    printf("\n");

    return 0;
}
