#include<stdio.h>
int max(int a, int b) {
   if(a>b){
      return a;
   } else {
      return b;
   }
}
int knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   int knap[n+1][W+1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i==0 || w==0)
            knap[i][w] = 0;
         else if (wt[i-1] <= w)
            knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
         else
            knap[i][w] = knap[i-1][w];
      }
   }
   return knap[n][W];
}
int main() {
    printf("0/1 KNAPSACK PROBLEM BRANCH AND BOUND METHOD\n");
   int profit[100],weight[100],cap,n,i;
   printf("\nEnter the Number of items:");
   scanf("%d",&n);
   printf("\nEnter the profit and weight ");
   for(i=0;i<n;i++)
   {
       scanf("%d%d",&profit[i],&weight[i]);
   }
   printf("\nEnter the capacity of the sack:\n");
   scanf("%d",&cap);
   printf("The solution is : %d", knapsack(cap, weight, profit, n));
   return 0;
}

