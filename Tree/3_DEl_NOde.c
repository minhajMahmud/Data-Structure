// #include <stdio.h>
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

// Function to find the minimum value node in a binary tree
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    // Find the leftmost leaf node
    while (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// Function to delete a node with the given value from the binary tree
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    // Recursive search for the node to be deleted
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
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
    // Performing in-order traversal and printing the result
    printf("In-Order Traversal: ");
    inOrder(root);
    printf("\n");


    // Deleting a node from the binary tree
    int key;
    printf("Enter the value to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    // Performing in-order traversal after deletion and printing the result
    printf("In-Order Traversal after deletion: ");
    inOrder(root);
    printf("\n");

    return 0;
}
