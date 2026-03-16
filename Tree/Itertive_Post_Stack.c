#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in a binary tree
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Structure representing a stack node
struct StackNode
{
    struct TreeNode *node;
    struct StackNode *next;
};

// Function to create a new node for the binary tree
struct TreeNode *createTreeNode(int data)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new node for the stack
struct StackNode *createStackNode(struct TreeNode *node)
{
    struct StackNode *stackNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a node onto the stack
void push(struct StackNode **stack, struct TreeNode *node)
{
    struct StackNode *stackNode = createStackNode(node);
    stackNode->next = *stack;
    *stack = stackNode;
}

// Function to pop a node from the stack
struct TreeNode *pop(struct StackNode **stack)
{
    if (*stack == NULL)
        return NULL;

    struct StackNode *temp = *stack;
    *stack = (*stack)->next;
    struct TreeNode *popped = temp->node;
    free(temp);

    return popped;
}

// Function to perform iterative post-order traversal using one stack
void postOrderIterative(struct TreeNode *root)
{
    if (root == NULL)
        return;

    struct StackNode *stack = NULL;

    do
    {
        while (root)
        {
            if (root->right)
                push(&stack, root->right);

            push(&stack, root);

            root = root->left;
        }

        root = pop(&stack);

        if (root->right && stack && root->right == stack->node)
        {
            pop(&stack);
            push(&stack, root);
            root = root->right;
        }
        else
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (stack != NULL);
}

int main()
{
    // Example usage
    struct TreeNode *root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);

    printf("Iterative Post-Order Traversal: ");
    postOrderIterative(root);
    printf("\n");

    return 0;
}
