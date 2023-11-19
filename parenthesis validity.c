#include<stdio.h>
int main()
{
	int var1=0, var2=0,i;
	char exp[20];
	printf("Enter the expression: ");
	scanf("%d", exp);
	for(i=0; i<strlen(exp);i++)
	{
		if(exp[i]=='(')
		{
			var1++;
		}
		else if(exp[i]==')')
		{
			var2++;
		}
	}
	if(var1==var2)
	{
		printf("Valid");
	}
	else
	{
		printf("Invalid");
	}
}







