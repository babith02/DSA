#include<stdio.h>
int maxi(int a, int b)
{
    return (a > b)? a : b;
}
int knapsack( int max, int profit[], int weight[], int val)
{
	int i, j;
   int K[val+1][max+1];
   for (i = 0; i<= val; i++)
   {
       for (j = 0; j <= max; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (weight[i-1] <= j)
                 K[i][j] = maxi(profit[i-1] + K[i-1][j-weight[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
       }
   }
   return K[val][max];
}
int main()
{
	int val,profit[100], weight[100],max,i;
	printf("KNAPSACK PROBLEM AND SOLUTION\n");
	printf("Enter the number of values: ");
	scanf("%d",&val);
	printf("Enter %d profits and their corresponding weights\n",val);
	for(i=0;i<val;i++)
	{
		scanf("%d%d", &profit[i], &weight[i]);
	}
	printf("Enter the maximum weight of the sack: ");
	scanf("%d", &max);
	printf("The maximum profit obtainable for the given data is: %d",knapsack(max,profit,weight,val));
	return 0;
}