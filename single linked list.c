#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*current, *head=NULL;
void insertb(int);
void insertf(int);
void deletef();
void deleteb();
void afternum(int);
void beforenum(int);
void display();
void search(int);
int main()
{
	int num,num2,num3,num4,num5, value, choice;
	printf("1-insert front\t\t  2-insert back\t\t 3-delete front\t\t 4-delete back\t\t 5-afternum\t\t 6-beforenum\t\t 7-search\t\t 8-display\n");
	while(choice!=9){
	printf("\nEnter your operation:\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			printf("Enter the num to be inserted: \n");
			scanf("%d: ", &num2);
			insertf(num2);
			display();
			break;
		case 2:
			printf("Enter the num to be inserted: \n");
			scanf("%d: ", &num);
			insertb(num);
			display();
			break;
		case 3:
			deletef();
			display();
			break;
		case 4:
			deleteb();
			display();
			break;
		case 5:
			printf("Enter the num to be inserted: \n");
			scanf("%d: ", &num3);			
			afternum(num3);
			display();
			break;
		case 6:
			printf("Enter the num to be inserted: \n");
			scanf("%d: ", &num4);			
			beforenum(num4);
			display();
			break;
		case 7:
			printf("Enter the num to be searched: \n");
			scanf("%d: ", &num5);			
			search(num5);
			break;		
		case 8:
			display();
			break;
		case 9:
			printf("Exit");		
	}
}
}
void insertb(int num)
{
	struct node* Newnode =(struct node*)malloc(sizeof(struct node));
	Newnode->data = num;
	Newnode->next = '\0';
	if(head =='\0')
	{
		head = Newnode;
	}
	else
	{
		current = head;
		while
		(current->next!='\0')
		{
			current = current->next;
		}
		current->next = Newnode;
	}
}
void insertf( int num2)
{
	struct node* newnode =(struct node*)malloc(sizeof(struct node));
	newnode->data=num2;
	newnode->next=head;
	head=newnode;	
	printf("%d",head->data);
}
void deletef()
{
	if(head=='\0')
	{
		printf("NO ELEMENTS");
	}
	else
	{
		current = head;
		head = head->next;
		free(current);
	}
}
void deleteb()
{
	if(head=='\0')
	{
		printf("NO ELEMENTS");
	}
	else
	{
		struct node* neq;
		current=head;
		while(current->next!='\0')
		{
			neq = current;
			current = current->next;
		
		}
		if(current!=head)
		{
			neq->next = '\0';			
		}
		else
		{
			head='\0';
		}
		free(current);
	}
}
void afternum(int num3)
{
	int value;
	struct node* Newnode1 = (struct node*)malloc(sizeof(struct node));
	printf("Enter the element after which to be inserted: ");
	scanf("%d", &value);
	current=head;
	Newnode1->data = num3;
	while(current->next!='\0')
	{
		if(current->data==value)
		{
			Newnode1->next=current->next;
			current->next=Newnode1;
			break;
		}
		current=current->next;	
	}
		if(current->data!=value)
		{
			printf("no element exist");
		}
}
void beforenum(int num4)
{
	int value;
	struct node* Newnode1 = (struct node*)malloc(sizeof(struct node));
	struct node* pre;
	printf("Enter the element before which to be inserted: ");
	scanf("%d", &value);
	current=head;
	pre='\0';
	Newnode1->data = num4;
	while(current->next!='\0')
	{
		if(current->data==value)
		{
			Newnode1->next=pre->next;
			pre->next=Newnode1;
			break;
		}
		pre=current;
		current=current->next;	
		
	}
		if(current->data!=value)
		{
			printf("no element exist");
		}
}
void search(int num5)
{
	current=head;
	int flag=0;
	while(current->next!='\0')
	{
		if(current->data==num5)
		{
			printf("Element found");
			flag=1;
		}
		current=current->next;
	}
	if(flag==0)
	{
		printf("Element not found");	
	}
}
void display()
{
	printf("The inserted number is: ");
	current = head;
	if(head =='\0')
	{
		printf("NO ELEMENTS");	
	}
	else
	{
		while(current->next !='\0')
		{
			printf("%d, ", current->data);
			current = current->next;
		}
		printf("%d",current->data);
	}
}
