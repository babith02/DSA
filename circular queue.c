#include<stdio.h>
void enqueue(int);
void dequeue();
void display();
#define MAX 5
int a[MAX],front=-1,rear=-1,flag=0;
int main()
{
	int choice, num;
	printf("1-enqueue\t\t 2-dequeue\t\t 3-display\n");
	while(1)
	{
		printf("\nEnter the command: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the num to insert: ");
				scanf("%d", &num);
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
void enqueue(num)
{
	if(front==(rear+1)%MAX && flag)
	{
		printf("QUEUE FULL\n");
		return;
	}
	else if(front==-1 && rear==-1)
	{
		front++;
		rear=(rear+1)%MAX;
		a[rear]=num;
		flag=1;
	}
	else
	{
		rear=(rear+1)%MAX;
		a[rear]=num;
		flag=1;
	}
	printf("Inserted\n");
}
void dequeue()
{
	if(!flag){
			printf("Empty");
			return;		
	}
	/*else if(front==(rear+1)%MAX && flag)
			flag = 0;*/
	else if(front==rear)
	{
			flag=0;		
			printf("dequeued");
			front=(front+1)%MAX;}
	else
	{
		printf("Dequeued\n");
		front=(front+1)%MAX;
	
	}
}
void display()
{
	if(!flag)
		printf("Queue Empty!");
	else{
	int i;
	for(i=front; i!=rear; i=(i+1)%MAX)
	{
		printf("%d ", a[i]);
	}
	printf("%d ", a[i]);
}
}

