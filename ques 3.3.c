#include<stdio.h>
int main()
{
	int c[3][3],i,j,k,l,a,value=0;
	printf("Enter the numbers in the matrix 3*3 \n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", &c[i][j]);
		}
	}
	printf("Enter the value to be checked in the matrix:");
	scanf("%d", &a);
	for( k=0; k<3; k++)
	{
		for(l=0; l<3; l++)
		{
			if(c[k][l]==a)
			value=1;
		}	
	}
	if(value==1)
	{
		printf("Yes. It's an element of the matrix");
	}
	else
	{
		printf("No. It's not an element of the matrix");
	}
	return 0;
}
