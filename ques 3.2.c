#include<stdio.h>
int main()
{
	int c[3][3],i,j,k,l;
	printf("Enter the numbers in the matrix 3*3 \n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", &c[i][j]);
		}
	}
	for( k=0; k<3; k++)
	{
		for(l=k; l<3; l++)
		{	
				c[k][l]=c[k][l+1];	
		}	
	}
	for(k=0; k<3; k++)
	{
		for(l=0; l<2; l++)
		{
			printf("%d \t", c[k][l]);
		}
			printf("\n");		
	}
	return 0;
}
