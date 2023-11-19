#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;	
}*top;
void insert(int);
void display();
void del();
void search();
int main()
{
	int num, ch,n ;
	printf("1-insert\t\t 2-delete\t\t 3-search\t\t 4-display\n");
	while(ch!=5)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the number to be inserted: ");
				scanf("%d", &num);
				insert(num);
				display();
				break;
			case 2:
				del();
				break;
			case 3:
				search();
				break;
			case 4:
				display();
				break;
		}
	}
}
void insert( int num)
{
	struct node*Newnode=(struct node*)malloc(sizeof(struct node));
	if(Newnode=='\0')
	{
		printf("unable to push\n");
	}
	else
	{
		if(top=='\0')
		{
			Newnode->data=num;
			Newnode->next='\0';	
			top=Newnode;
			printf("Inserted\n");
		}
		else
		{
			Newnode->data=num;
			Newnode->next=top;	
			top=Newnode;
			printf("Inserted\n");	
		}

	}

}
void display()
{
	struct node* temp;
	temp=top;
	if(top=='\0')
	{
		printf("No elements\n");
	}
	else
	{
		printf("\nThe elements are: ");
		while(temp!='\0')
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void search()
{
	struct node*ptr;
	int item,i=0,flag;
	ptr=top;
	if(ptr==NULL)
	{
		printf("\nstack is empty");
		
	}
	else
	{
		printf("\nEnter the element to search:");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
			if(ptr->data==item)
			{
				printf("\nElement found at %d position",i+1);
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}
			ptr=ptr->next;
			i++;
		}
		if(flag==1)
		{
			printf("\nElement not found");
		}
	}
}
void del()
{
	int f=0;
	struct node* temp;
	if(top=='\0')
	{
		printf("No elements to be deleted\n");
	}
	else
	{
		temp=top;
		top=temp->next;
		free(temp);
		f=1;
	}
	if(f==1)
		printf("Deleted\n");
}
