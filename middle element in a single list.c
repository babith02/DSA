#include<stdio.h>
#include<stdlib.h>
int val=0,k=0, middle, count=1;
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
int reverse();
int mid();
void search(int);
int main()
{
	int num,num2,num3,num4,num5, value, choice,x=1;
	printf("1-insert front\t\t  2-insert back\t\t 3-delete front\t\t 4-delete back\t\t 5-afternum\t\t 6-beforenum\t\t 7-search\t\t 8-display\t\t9-reverse\t\t 10-middle element\t\t 11-exit\n");
	while(x){
	printf("\nEnter your operation:\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			printf("Enter the num to be inserted: \n");
			val++;
			scanf("%d: ", &num2);
			insertf(num2);
			display();
			break;
		case 2:
			printf("Enter the num to be inserted: \n");
			val++;
			scanf("%d: ", &num);
			insertb(num);
			display();
			break;
		case 3:
			deletef();
			val--;
			display();
			break;
		case 4:
			deleteb();
			val--;
			display();
			break;
		case 5:
			printf("Enter the num to be inserted: \n");
			scanf("%d: ", &num3);			
			afternum(num3);
			val++;
			display();
			break;
		case 6:
			printf("Enter the num to be inserted: \n");
			scanf("%d: ", &num4);			
			beforenum(num4);
			val++;
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
			reverse();
			break;
		case 10:
			mid();
			break;
		case 11:
			x=0;	
	}
}
}
int mid()
{
	int val2;
	val2=val/2;
	current=head;
	/*	middle=val/2;
		current=head;
		while(current->next!=NULL)
		{
			if(count==middle)
			{
				printf("Middle element is: %d",current->data);
			}
			count++;
			current=current->next;
		}	*/
	if(val%2==0){
		for(int i=0;i<val2-1;i++)
			current=current->next;
		printf("The mid elements are %d\t%d",current->data,(current->next)->data);
		}
		else{
			for(int i=0;i<val2-1;i++)
			current=current->next;
			printf("The mid element is %d",(current->next)->data);
		}
	}

int reverse()
{
	struct node* pre;
	current=head;
	for(k=0;k<val;k++)
	{
		current=head;
		while(current->next!=NULL)
		{
			pre=current;
			current=current->next;
		}
		printf("%d",current->data);
		pre->next=NULL;
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
