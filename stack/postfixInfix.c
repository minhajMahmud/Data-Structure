#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char x) 
{
    stack[++top] = x;
}

char pop() 
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
void postInfix(char exp[])
{
    int l, i, j = 0;
    char temp[20];
    strrev(exp);
    l = strlen(exp);
    
    for (i = 0; i < l; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            push(exp[i]);
        }
        else
        {
            temp[j++] = exp[i];
            temp[j++] = pop();
        }
    }
    temp[j] = exp[top--];
    strrev(temp);
    printf("infinix expression is: %s\n", temp);
}
int main()
{
    char exp[50];
    printf("\n postfix expreession:");
    scanf("%s", exp);
    postInfix(exp);

    return 0;
}
