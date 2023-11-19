#include<stdio.h>
#define max 5
int back=0,n=0,i,j,val=0, front=0, temp;
int stack[5];
int pop();
int display();
int sort();
int push(int);
int main()
{
	int choice,x=1;
	printf(" 1: push\t\t 2: pop\t\t 3: display\t\t 4-sort \t\t 5:exit\n");
	while(x)
	{

		printf("Enter your choice:\t");
		scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			    printf("Enter the number: ");
			    scanf("%d", &n);
			    //val++;
			    push(n);
			break;
		case 2:
			pop();
			//val--;
			break;
		case 3:
			display();
			break;
		case 4:
			sort();
			break;
		case 5:
		    x=0;
	}
	}
}
int sort()
{
	for(i=0;i<front-1;i++)
	{
		for(j=i+1;j<front;j++)
		{
				if(stack[i] > stack[j])
				{
					temp=stack[i];
					stack[i]=stack[j];
					stack[j]=temp;
				}	
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
