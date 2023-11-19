#include<stdio.h>
#define N 5
void push();
void pop();
void display();
void send();
void receive();
void search();

int s1[N],s2[N],top1=-1,top2=-1,rear1=-1,rear2=-1;

int main(){
	int ch;
	printf("1 - Push\t\t 2 - Pop\t\t 3 - Display\t\t 4 - Search\n");
	while(4){
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			search();
			break;
		default:
			printf("Invalid Choice \n");
		}
	}
}

void push(){
	if(rear1==N-1)
		printf("Stack is full  \n");
	else{
		int data;
		printf("Enter the data: ");
		scanf("%d",&data);
		if(top1==-1){
			s1[++top1]=data;
			rear1++;
		}
		else{
			send();
			s1[++top1]=data;
			rear1++;
			receive();
		}
        display();
	}
}

void send(){
	while(top1<=rear1){
		if(top2==-1){
			s2[++top2]=s1[top1++];
			rear2++;
		}
		else{
			s2[++rear2]=s1[top1++];
		}
	}
	top1=-1;rear1=-1;
}

void receive(){
	while(top2<=rear2){
		s1[++rear1]=s2[top2++];
	}
	top2=-1;
	rear2=-1;
}

void pop(){
	if(top1==-1)
		printf("Stack is Empty \n");
	else if(top1==rear1){
		printf("%d is removed from the Stack \n",s1[top1]);
		top1=-1;rear1=-1;
		display();
		}
	else{
	printf("%d is removed from the Stack \n",s1[top1]);
	int i;
	for(i=0;i<N;i++)
		s1[i]=s1[i+1];
	rear1--;
	display();
	}
}

void display(){
	if(top1==-1)
		printf("Stack is Empty \n");
	else{
		int i;
		for(i=0;i<=rear1;i++)
			printf("%d  ",s1[i]);
		printf("\n");
	}
}

void search(){
	if(top1==-1)
		printf("Stack is Empty \n");
	else{
		int i,flag=0,data;
		printf("Enter the Value: ");
		scanf("%d",&data);
		for(i=0;i<=rear1;i++){
			if(data==s1[i]){
			flag=1;
			break;}
		}
		if(flag==1)
			printf("Element Found \n");
		else
			printf("Element not Found \n");
	}
}
