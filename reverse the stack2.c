#include<stdio.h>
int a[10],b[10],top=0,top2=0,i,j,var1=0, var2=0;
void insert();
void pop();
void pop2();
int main()
{
		int num, choice;
		printf("\n1-insert\t\t 2-reverse\t\t 3-display\t\t\n");
		while(1)
		{
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				pop();
				break;
			case 3:
				pop2();
				break;
		}
		}
}

//inserting
void insert()
{
	int num;
	for(i=1;i<11;i++)
	{
		printf("Enter the element: ");
		scanf("%d",&num);
	if(top==10)
		printf("Stack is full\n");	
	else
	{
		a[++top]=0;
		a[top]=num;
	}
	}
		
}
//revering
void pop()
{
	if( top==0)
		printf("\nThe stack is empty\n");
	else
	{
		printf("\nreverse order: ");
		while(top!=0)
		{
			printf("%d ",a[top]);
			b[top2]=a[top];
			top--;
			top2++;
		}
	}
}
//displaying the reversed stack
void pop2()
{
	if( top2==0)
		printf("\nThe stack is empty\n");
	else
	{
		for(i=top2-1;i>-1;i--)
		{
			printf("%d ",b[i]);
		}
	}
}
