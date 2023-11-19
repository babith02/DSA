#include<stdio.h>
#define max 5
int back=0,n=0,i, front=0;
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
	if(front<max)
	{
	
		stack[front]=var;
		front++;
		printf("%d is pushed\n",var);
	}
	else
	{
		printf("The stack is full\n");
	}
}
int pop()
{
    if(back<front)
    {
        printf("%d is popped\n", stack[back]);
        back+=1;
    }
    else
    {
        	printf("The stack is empty\n");
    }
}
int display()
{
    if(back<front)
    {
        for(i=back; i<front; i++)
        {
            printf("%d ", stack[i]);
        }
            printf("\n");
    }
    else
    {
        printf("The stack is empty\n");
    }
}
