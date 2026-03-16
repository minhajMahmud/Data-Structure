#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in a binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Structure representing a stack node
struct StackNode
{
    struct Node *data;
    struct StackNode *next;
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

// Function to create a new stack node with the given data
struct StackNode *createStackNode(struct Node *data)
{
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to push a node onto the stack
void push(struct StackNode **stack, struct Node *data)
{
    struct StackNode *node = createStackNode(data);
    node->next = *stack;
    *stack = node;
}

// Function to pop a node from the stack
struct Node *pop(struct StackNode **stack)
{
    if (*stack == NULL)
        return NULL;

    struct StackNode *temp = *stack;
    *stack = (*stack)->next;
    struct Node *data = temp->data;
    free(temp);

    return data;
}

// Function to perform iterative post-order traversal using two stacks
void postOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct StackNode *stack1 = NULL;
    struct StackNode *stack2 = NULL;

    // Push the root node onto the first stack
    push(&stack1, root);

    // Process nodes while the first stack is not empty
    while (stack1 != NULL)
    {
        // Pop a node from the first stack
        struct Node *temp = pop(&stack1);

        // Push the popped node onto the second stack
        push(&stack2, temp);

        // Push the left and right children of the popped node onto the first stack
        if (temp->left != NULL)
            push(&stack1, temp->left);
        if (temp->right != NULL)
            push(&stack1, temp->right);
    }

    // Print nodes from the second stack
    while (stack2 != NULL)
    {
        struct Node *temp = pop(&stack2);
        printf("%d ", temp->data);
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
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Iterative Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
