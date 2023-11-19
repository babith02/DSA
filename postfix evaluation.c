#include<stdio.h>
int stack[100];
int top = -1;

void push(int var)
{
    stack[++top] = var;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *ch;
    int n1,n2,n3,num;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    ch = exp;
    while(*ch != '\0')
    {
        if(isdigit(*ch))
        {
            num = *ch - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*ch)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        ch++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}
