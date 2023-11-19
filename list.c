#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;  
void firstin ();  
void lastin ();  
void postin();  
void firstdel();  
void lastdel();  
void postdel();  
void display();  
void main ()  
{  
    int ch=0;
	struct node*head;
   head=(struct node*)malloc(sizeof(struct node));
        printf(" 1: firstin\t\t 2: firstdel\n");
		printf(" 3: lastin\t\t 4: lastdel\n");
		printf(" 5: postin\t\t 6: postdel\n");
		printf(" 7: display\t\t 8: exit\n");
    while(ch!= 9)  
    {  
		printf("\n FUNCTION:  ");        
        scanf("\n%d",&ch);  
        switch(ch)  
        {  
            case 1:  
            	firstin();      
            	break;  
            case 2:  
            	firstdel();      
            	break;  
            case 3:  
            	lastin();     
            	break;  
            case 4:
				lastdel();      
            	break;  
            case 5:  
                postin(); 
            	break;  
            case 6:  
            	postdel();          
            	break;    
            case 7:  
            	display();        
            	break;  
            case 8:  
            	exit(0);  
            	break;  
            default:  
            	printf("INVALID..");  
        }  
    }  
}  
void firstin()  
{  
    struct node *ptr;  
    int item;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        printf("\nEnter your element: ");    
        scanf("%d",&item);    
        ptr->data = item;  
        ptr->next = head;  
        head = ptr;  
        printf("Node inserted\n");  
    }  
     
}  
void lastin()  
{  
    struct node *ptr,*temp;  
    int item;    
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");    
    }  
    else  
    {  
        printf("\nEnter your element: \n");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            printf("Node inserted\n");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("Node inserted\n");  
         
        }  
    }  
}  
void postin()  
{  
    int i,loc,item;  
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        printf("\nEnter your element: ");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location to insert: ");  
        scanf("%d\n",&loc);  
        temp=head;  
        for(i=1;i<loc-1;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("can't insert\n");  
                return;  
            }  
         
        }  
        ptr ->next = temp ->next;  
        temp ->next = ptr;  
        printf("Node inserted\n");  
    }  
}  
void firstdel()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("List is empty\n");  
    }  
    else  
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
  
    }  
}  
void lastdel()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("list is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);    
    }  
         
    else  
    {  
        ptr = head;  
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("Deleted Node from the last ...\n");  
    }    
}  
void postdel()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("Enter the location of the node :\n");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;      
        ptr = ptr->next;  
             
        if(ptr == NULL)  
        {  
            printf("Can't delete\n");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("Node deleted\n",loc+1);  
}  
void display()  
{  
    struct node *ptr;  
    ptr = head;  
    if(ptr == NULL)  
    {  
        printf("No element to display\n");  
    }  
    else  
    {  
        printf("Elements: ");  
        while (ptr!=NULL)  
        {  
            printf("%d ",ptr->data);  
            ptr = ptr -> next;  
        } 
		printf("\n"); 
    }  
}   
