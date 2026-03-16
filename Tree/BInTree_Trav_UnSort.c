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

// Function to perform pre-order traversal of a binary tree
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data); // Print the data of the current node
        preOrder(root->left);      // Recursively traverse the left subtree
        preOrder(root->right);     // Recursively traverse the right subtree
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

// Function to perform post-order traversal of a binary tree
void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);     // Recursively traverse the left subtree
        postOrder(root->right);    // Recursively traverse the right subtree
        printf("%d ", root->data); // Print the data of the current node
    }
}

// Function to free the entire binary tree
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
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

    // Performing pre-order, in-order, and post-order traversals
    printf("Pre-Order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-Order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrder(root);
    printf("\n");

    // Freeing the entire binary tree
    freeTree(root);

    return 0;
}
