#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
static int flag=0;
int count=0;
struct node *front;
struct node *rear;
void insert();
void del();
void display();
float mean();
void reverse(struct node *);
int main ()
{
    int choice;
    float sum;
    struct node *current;
    while(choice != 4)
    {

        printf("\n1.insert an element\n2.reverse\n3.Exit\n");
        printf("\nEnter your choice :");
        scanf("%d",& choice);
        switch(choice)
        {
            case 1:
            insert();
			display();
            break;
            case 2:
            current=front;
            printf("\nThe reverse is \t");
            reverse(current);

            break;
            case 3:
            exit(0);
            break;
            default:
            printf("\nEnter valid choice:\n");
        }
    }
}

float mean(){
	float sum;
	struct node *ptr;
    ptr = front;
	if(ptr==NULL){
		printf("\nList is empty");
		return '\0';
	}
	else{
	while(ptr != NULL)
        {
            sum+=ptr -> data;
            ptr = ptr -> next;
        }
        sum=sum/count;
        return sum;
	}}

void insert()
{
    struct node *ptr;
    int item;

    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value:\n");
        scanf("%d",&item);
        ptr -> data = item;
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
            front -> next = NULL;
            rear -> next = NULL;
        }
        else
        {
            rear -> next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
    count++;
}
void del()
{
    struct node *ptr;
    if(front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front -> next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {   printf("\nvalues are\t");
        while(ptr != NULL)
        {
            printf("%d\t",ptr -> data);
            ptr = ptr -> next;
        }
    }
    printf("\n");
}
void reverse(struct node *current){

   if(flag==1){
    return ;
   }

    else{
        if(current==NULL){
            flag=1;



        }
        else{


            int x=current->data;
            reverse(current->next);
            printf("%d\t",x);

        }


    }

}
