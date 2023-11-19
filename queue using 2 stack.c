#include<stdio.h>
#include<stdlib.h>
/*struct node
{
	int data;
	struct node* next;
}top1=0, top2=0;*/
#define MAX 5
void enqueue(int);
void dequeue();
void display();
int push1(int);
int push2(int);
int pop1();
int pop2();
int stack1[MAX],stack2[MAX],top1=-1, top2=-1,count=0,flag=0, i=0,var=0,rear;
int main()
{
	int choice, num;
	printf("1-enqueue\t\t 2-dequeue\t\t 3-display\t\t \n");
	while(1)
	{
		printf("\nEnter the command: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the num to insert: ");
				scanf("%d",&num);
				enqueue(num);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
		}
		
	}
}
void display()  
{  
	if(top1==-1)
	{
		printf("Stack is empty\n");
	}
	for(i=0;i<=top1;i++)  
	{  
    	printf("%d  ", stack1[i]);  
  	}  
}  
void enqueue(num)
{
	if(top1==MAX-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		push1(num);
		count++;
	}
	display();
}
int push1(num)
{
	top1++;
	stack1[top1]=num;
}
int pop1()
{
	return(stack1[top1--]);
}
int push2(num)
{
	top2++;
	stack2[top2]=num;
}
int pop2()
{
	return(stack2[top2--]);
}

void dequeue()
{
	if(top1==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		for(i = 0;i < count;i++)
		{
			push2(pop1());
		}
		printf(" Deleted element: %d", stack2[top2]);
		pop2();
		count--;
		for (i = 0;i < count;i++)
		{
			push1(pop2());
		}
	}
}




