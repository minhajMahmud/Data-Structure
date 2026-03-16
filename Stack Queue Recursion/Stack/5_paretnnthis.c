#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack
{
  char data[MAX_SIZE];
  int top;
} Stack;

Stack bracketStack;

void initStack(Stack *stack)
{
  stack->top = -1;
}

int isEmpty(Stack *stack)
{
  return stack->top == -1;
}

void push(Stack *stack, char c)
{
  if (stack->top == MAX_SIZE - 1)
  {
    printf("Stack overflow!\n");
    return;
  }
  stack->top++;
  stack->data[stack->top] = c;
}

char pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack underflow!\n");
    return 0;
  }
  char c = stack->data[stack->top];
  stack->top--;
  return c;
}

int isMatchingPair(char a, char b)
{
  return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int areBracketsBalanced(char *expr)
{
  initStack(&bracketStack);
  for (int i = 0; i < strlen(expr); i++)
  {
    if (isEmpty(&bracketStack))
    {
      push(&bracketStack, expr[i]);
    }
    else if (isMatchingPair(bracketStack.data[bracketStack.top], expr[i]))
    {
      pop(&bracketStack);
    }
    else
    {
      push(&bracketStack, expr[i]);
    }
  }
  return isEmpty(&bracketStack);
}

int main()
{
  // char expr[] = "{(}[";
  printf("Enter the expression: ");
  char expr[100];
  scanf("%s", expr);

  if (areBracketsBalanced(expr))
  {
    printf("Balanced\n");
  }
  else
  {
    printf("Not Balanced\n");
  }

  return 0;
}
