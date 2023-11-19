#include<stdio.h>
#include<stdlib.h>
int num=0,var=0;
int insert(int);
int display(int);
struct node
{
	int data;
	struct node* link;
}*current, *head=NULL;
int insert(num)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->link=NULL;
	if(head==NULL)
	{
		head=newnode;	
	}
	else
	{
		current=head;
		while(current->link!=NULL)
		{
			current=current->link;	
		}
		current->link=newnode;	
	}	
}
int display(num)
{
	int cal=1;
	current=head;
	while(cal!=num)
	{
		current=current->link;
		cal++;
	}
	printf("The middle element is: %d",current->data);
}
int main()
{
	int n,i,count=0,rem;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
	for(i=0; i<n;i++)
	{
		scanf("%d", &num);
		insert(num);
		count++;
	}
	rem=count/2;
	if(rem!=0)
	{
		display(rem+1);
	}
	else
	{
		display(rem);
	}
}


	
	
