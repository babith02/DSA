#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 40
struct node{
	char data;
	struct node* next;
}*top = '\0', *current;
void push(char);
char pop();
int Lowerprecede(char);
int main(){
	int flag =1, dum=0;
	char exp[MAX];
	char *res;
	int i, j;
	printf("Enter Expression in infix: ");
	scanf("%s",exp);
	strrev(exp);
	res = (char *)malloc(strlen(exp)*sizeof(char));
	for(i=0, j=0; exp[i] != '\0'; i++){
		if((exp[i] >= 'A' && exp[i] <= 'Z')||(exp[i] >= 'a' && exp[i] <= 'z')){
			*(res+j) = exp[i];
			j++;
		
			
			
		}
		else if(exp[i] == '+' ||exp[i] == '-' ||exp[i] == '*' ||exp[i] == '/'||exp[i] == '('||exp[i] == ')'){
			if(top == NULL )
				{
				push(exp[i]);
			}
			else{
				if(exp[i] == '('){
					while(top->data != ')'){
						*(res+j) = pop();
						j++;
					}
					pop();
					dum = 1;
				}
				else if(!Lowerprecede(exp[i])){
					while(flag && !Lowerprecede(exp[i])){
						if(top->next == NULL){
							flag = 0;
						}
						*(res+j) = pop();
						j++;	
					}
					flag=1;
				
				}
				push(exp[i]);
				if(dum){
					pop();
					dum=0;
				}
			}
		}
	}	
	while(top!=NULL){
		*(res+j) = pop();
		j++;
	}
	printf("\nPrefix Expression:\n\t");
	strrev(res);
	for(int k=0; k<j+1; k++)
	printf("%c",res[k]);
	return 0;
}

void push(char num){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = top;
	top = newNode;
	//printf("%c\n", top->data);
}

char pop(){
	char dele;
	if(top == '\0'){
		printf("\t**Stack is empty\n");
		dele = 0;	
	}
	else{
		current = top;
		top = top->next;
		dele = current->data;
		free(current);
	}
	return dele;
}

int Lowerprecede(char exp){
	if((top->data =='+' || top->data == '-') && (exp == '*' || exp == '/'))
		return 1;
	else if((top->data =='+' && exp == '-') || (top->data == '-' && exp == '+'))
		return 1;
	else if((top->data =='*' && exp == '/') || (top->data == '/' && exp == '*'))
		return 1;
	else if(top->data =='(' || exp == '(' || top->data == ')' || exp == ')'){
		return 1;
	}
	else return 0;
}
