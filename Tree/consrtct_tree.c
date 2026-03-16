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

// Function to find the index of a value in an array
int findIndex(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1; // Value not found
}

// Function to construct a binary tree from in-order and pre-order traversals
struct Node *constructTree(int inOrder[], int preOrder[], int inStart, int inEnd, int *preIndex)
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    // Create a node with the current pre-order element
    struct Node *root = createNode(preOrder[*preIndex]);

    // Find the index of the current pre-order element in in-order traversal
    int inIndex = findIndex(inOrder, inStart, inEnd, preOrder[*preIndex]);

    // Increment the pre-order index
    (*preIndex)++;

    // Construct the left and right subtrees recursively
    root->left = constructTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
    root->right = constructTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);

    return root;
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
    int inOrder[] = {4, 2, 5, 1, 3};
    int preOrder[] = {1, 2, 4, 5, 3};

    int inOrderSize = sizeof(inOrder) / sizeof(inOrder[0]);
    int preOrderSize = sizeof(preOrder) / sizeof(preOrder[0]);

    int preIndex = 0;

    struct Node *root = constructTree(inOrder, preOrder, 0, inOrderSize - 1, &preIndex);

    printf("In-Order Traversal of the Constructed Tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
