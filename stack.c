#include<stdio.h>
#define max 5
int top=0,n=0,i;
int stack[5];
int pop();
int display();
int push(int);
int main()
{
	int choice,x=1;

	while(x)
	{
		printf(" 1: push\t\t 2: pop\t\t 3: display\t\t 4: exit\n");
		printf("Enter your choice:\t");
		scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			    printf("Enter the number to be pushed: ");
			    scanf("%d", &n);
			    push(n);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
		    x=0;
	}
	}
}
int push(var)
{
	if(top>=max-1)
	{
		printf("The stack is full\n");
	}
	else
	{
		stack[top]=var;
		top++;
	}
}
int pop()
{
    if(top==0)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The poped element is %d\t:", stack[top]);
        stack[top]='\0';
        top--;
        printf("\n");
    }
}
int display()
{
    if(top==0)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for(i=0; i<top; i++)
        {
            printf("%d ", stack[i]);
        }
            printf("\n");
    }
}
