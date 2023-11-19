#include<stdio.h>
#include<ctype.h>
int top=-1;
char stack[100];
void push(char X)
{
	stack[++top]=X;
}
char pop()
{
	if(top==-1)
		return -1;
	else
		return stack[top--];
}
int priority(char x)
{
	if(x=='(')
		return 0;
	if(x=='+' || x=='-')
		return 1;
	if(x=='*' || x=='/')
		return 2;
	return 0;
}
int main()
{
	char value[20];
	char *ch, var;
	printf("Enter the expression: ");
	scanf("%s", value);
	ch=value;
	while(*ch != '\0')
	{
		if(isalnum(*ch))
			printf("%c",*ch);
		else if(*ch=='(')
			push(*ch);
		else if(*ch==')')
		{
			while((var=pop())!='(')
				printf("%c", var);
		}
		else
		{
		while(priority(stack[top]) >= priority(*ch))
			printf("%c",pop());
		push(*ch);
		}
		ch++;
	}
	while(top!=-1)
	{
		printf("%c", pop());	
	}		
return 0;	
}
