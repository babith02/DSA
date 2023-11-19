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
	for( i=0; i<3; i++)
	{
		for( j=0; j<3; j++)
		{
			d[i][j]=c[j][i];
		}
	}
	printf("The transpose matrix\n");
	for( i=0; i<3; i++)
	{
		for( j=0; j<3; j++)
		{
			printf("%d\t", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}
