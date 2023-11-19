#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* stack;
int top = -1;
void normal();
void push(char ele)
{
	stack[++top] = ele;
}
char pop()
{
	return stack[top--];
}
int isPalindrome(char str[])
{
	int length = strlen(str);
	stack = (char*)malloc(length * sizeof(char));
	int i, mid = length / 2;
	for (i = 0; i < mid; i++) 
	{
		push(str[i]);
	}

	
	if (length % 2 != 0) {
		i++;
	}

	while (str[i] != '\0') {
		char ele = pop();
		if (ele != str[i])
			return 0;
		i++;
	}

	return 1;
}
int main()
{
	int choice;
	char str[20];
	printf("\t\tPALINDROME\t\t\n");
	printf("1.Using Stack\n2.without stack\n3.exit program\n");
	while(choice!=3)
	{
		printf("Enter a choice:");
        scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter a string:");
            scanf("%s",&str);
		    	if (isPalindrome(str)) {
	    	printf("Yes %s is a palindrome\n",str);
	              }
	         else {
	         	printf("No %s is a palindrome\n",str);
                 	}
	        break;
	    case 2:
	    	normal();
	    	break;
	    case 3:
	    	printf("exiting");
	    	break;
	    default:
	    	printf("not valid operation");
	 	
		}
		
	}

	return 0;
}
void normal()
{
    char string1[20];
    int i, length;
    int flag = 0;
    
    printf("Enter a string:");
    scanf("%s", string1);
    
    length = strlen(string1);
    
    for(i=0;i < length ;i++){
        if(string1[i] != string1[length-i-1]){
            flag = 1;
            break;
           }
        }
    
    if (flag) {
        printf("%s is not a palindrome\n", string1);
    }    
    else {
        printf("%s is a palindrome\n", string1);
    }
}
