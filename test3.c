#include<stdio.h>
#include<stdlib.h>
int num=0,var=0;
int insert(int);
int check(int);
struct node
{
	int data;
	struct node* link;
}*current, *head=NULL, *new;
int insert(int num)
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
int check(int n)
{
	int count=0,i,pairs=0;
	current=head;
	new=head;
	for(i=0;i<n;i++)
	{
		while(current->link!=NULL)
		{
			if(new->data==current->data)
			{
				count++;
			}
			current=current->link;
		}
		new=new->link;
		pairs+=count/2;
	}
	printf("No of pairs are:%d", pairs);
}
int main()
{
	int i, n;
	printf("---socks colors with numbers---\n");
	printf("1-black\t\t 2-red\t\t 3-yellow\t\t 4-white\t\t\n");
	printf("Enter the number of chances to choose: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the color of socks: ");
		scanf("%d",&num);
		insert(num);
	}
	check(n);
	return 0;	
}


	
	
