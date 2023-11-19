#include<stdio.h>
#define max 5
int back=0,n=0,num,i,j,val=0, front=0, temp;
int stack[5];
int pop();
int pairs();
int display();
int sort();
int push(int);
int main()
{
	char choice;
	int x=1;
	printf("---socks colors with numbers---\n");
	printf("1-black\t\t 2-red\t\t 3-yellow\t\t 4-white\t\t\n");
	printf(" P: push\t\t D: display\t\t C:Pairs of socks\t\t E:exit\n");
	while(x)
	{
	printf("\nEnter your choice:\t");
	scanf("%ch", &choice);
	switch(choice)
	{
		case 'P':
				printf("Enter the number of chances to choose: ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("Enter the color of socks: ");
					scanf("%d",&num);
					push(num);
				}
				sort();	    
				break;
		case 'D':
			display();
			break;
		case 'C':
			pairs();
			break;
		case 'E':
		    x=0;
	}
	}
}
int pairs()
{
	int z=0,k=0,count;
	while(k!=front)
	{
		if(stack[z]==stack[z+1])
		{
			count++;
		}
		z=z+1;
		k++;
	}
printf("No of pairs are: %d",count);
}
int sort()
{
	for(i=0;i<front-1;i++)
	{
		for(j=i+1;j<front;j++)
		{
				if(stack[i] > stack[j])
				{
					temp=stack[i];
					stack[i]=stack[j];
					stack[j]=temp;
				}	
		}
	}
}
int push(var)
{
	if(front<max)
	{
	
		stack[front]=var;
		front++;
		printf("%d is pushed\n",var);
	}
	else
	{
		printf("The stack is full\n");
	}
}
int pop()
{
    if(back<front)
    {
        printf("%d is popped\n", stack[back]);
        back+=1;
    }
    else
    {
        	printf("The stack is empty\n");
    }
}
int display()
{
    if(back<front)
    {
        for(i=back; i<front; i++)
        {
            printf("%d ", stack[i]);
        }
            printf("\n");
    }
    else
    {
        printf("The stack is empty\n");
    }
}
