//2.MULTIPLICATION:
#include <limits.h>
#include <stdio.h>
int block(int arr[],int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min =INT_MAX;
    int number;
    for (k = i; k < j; k++)
    {
        number = (block(arr, i, k)
                + block(arr, k + 1, j)
                + arr[i - 1] * arr[k] * arr[j]);

        if (number < min)
            min = number;
    }
    return min;
}
int main()
{
    int arr[100],n;
printf("Enter the number of elements to be  multiplied: ");
scanf("%d",&n);
printf("Enter an array:  ");
for(int i=0;i<n;i++)
    {
scanf("%d",&arr[i]);

    }
printf("Minimum number of multiplications %d: ",block(arr,1,n-1));
    return 0;
}
