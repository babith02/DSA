#include<stdio.h>
int main()
{
	int  c[7][7], sum[6], avg[6];
	for(int i=1; i<6; i++)
	{
		printf("Enter the new register number and mark of student %d \n",i );
	
		for(int j=1; j<7; j++)
		{
			scanf("%d", &c[i][j]);
		}
	}
	printf("\n");
	printf("REG NO\t\t\t MARKS\n");
	for(int k=1; k<6; k++)
	{
		for(int l=1; l<7; l++)
		{
			printf("   %d \t", c[k][l]);
		}
		printf("\n");	
	}

	for(int k=1; k<6; k++)
	{
		sum[k]=0;
		for(int l=2; l<7; l++)
		{
			sum[k]+=c[k][l];
			avg[k]=sum[k]/5;
		}
			printf("%d\n",sum[k]);				
	}
	for(int i=1; i<6;i++)
	printf("The average mark of the student  %d is: %d\n",i,avg[i]);
	return 0;
}
