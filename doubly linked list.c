#include <stdio.h>
#include <stdlib.h>
void display();
void insertf(int);
void insertl(int);
void delf();
void dell();
void search(int);
struct node
{
	int data;
	struct node *prev;
	struct node *next;
} *head = '\0', *first = 0, *last = 0, *current;
int main()
{
	int choice, num;
	printf("1-display\t\t 2-insert first\t\t 3-insert last\n 4-del f\t\t 5-del l\t\t 6-search\t\t\n");
	while (1)
	{
		printf("\nEnter the command:  ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			display();
			break;
		case 2:
			printf("Enter the num to insert: ");
			scanf("%d", &num);
			insertf(num);
			break;
		case 3:
			printf("Enter the num to insert: ");
			scanf("%d", &num);
			insertl(num);
			break;
		case 4:
			delf();
			break;
		case 5:
			dell();
			break;
		case 6:
			printf("Enter the num to search: ");
			scanf("%d", &num);
			search(num);
			break;
		}
	}
}
void insertf(num)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = num;
	if (head == '\0')
	{
		newnode->prev = '\0';
		newnode->next = '\0';
		head = newnode;
	}
	else
	{
		newnode->next = head;
		newnode->prev = NULL;
	}
	head = newnode;
}
void insertl(num)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = num;
	if (head == '\0')
	{
		newnode->prev = '\0';
		newnode->next = '\0';
		head = newnode;
	}
	else
	{
		current = head;
		while (current->next != '\0')
		{
			current = current->next;
		}
		current->next = newnode;
		newnode->next = '\0';
		newnode->prev = current;
		ṇ
	}
}
void delf()
{
	if (head == '\0')
	{
		printf("No data\n");
		ṇ
	}
	else
	{
		current = head;
		head = current->next;
		head->prev = '\0';
		free(current);
	}
	printf("node deleted\n");
}
void dell()
{
	if (head == '\0')
	{
		printf("No data\n");
	}
	else
	{
		struct node *newnode = (struct node *)malloc(sizeof(struct node));
		current = head;
		while (current->next != '\0')
		{
			current = current->next;
			newnode = current->prev;
		}
		newnode->next = '\0';
		free(current);
	}
	printf("node deleted\n");
}
void search(num)
{
	int flag = 0;
	current = head;
	if (head == '\0')
	{
		printf("No data\n");
	}
	else
	{
		while (current->next != '\0')
		{
			if (current->data == num)
			{
				printf("Element found\n");
				flag = 1;
			}
			current = current->next;
		}
		if (flag == 0)
		{
			printf("Element not found\n");
		}
	}
}
void display()
{
	if (head == '\0')
	{
		printf("NO DATA\n");
	}
	else
	{
		current = head;

		while (current->next != '\0')
		{
			printf("%d ", current->data);
			current = current->next;
		}
		printf("%d", current->data);
	}
}
