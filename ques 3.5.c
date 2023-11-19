#include<stdio.h>
int main()
{
	int c[3][3], d[3][3], res[3][3],i,j,k,l;
	printf("Enter the numbers in the first matrix 3*3 \n");
	for( i=0; i<3; i++)
	{
		for( j=0; j<3; j++)
		{
			scanf("%d", &c[i][j]);
		}
	}
	printf("Enter the numbers in the second matrix 3*3 \n");
	for( i=0; i<3; i++)
	{
		for( j=0; j<3; j++)
		{
			scanf("%d", &d[i][j]);
		}
	}
	for( i=0; i<3; i++)
	{
		for( j=0; j<3; j++)
		{
		res[i][j]=0;
		for(k=0; k<3; k++)
		{
			res[i][j]+=c[i][k] * d[k][j];
		}
		}
	}
	printf("The resultant matrix\n");
	for( i=0; i<3; i++)
	{
		for( j=0; j<3; j++)
		{
			printf("%d\t", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
