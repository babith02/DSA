#include<stdio.h>
int main()
{
	int choice,arr1[5], arr2[5], new[10], duplicate[10],sum=0,avg=0,demo=0, a[10], b[5], c[5],i,j,k=0, var=0,condition=0,count=0, flag=0, ch=0;
	//input the values from the user
	printf("Enter the elements in the first list: \n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr1[i]);
	}
	printf("Enter the elements in the second list: \n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr2[i]);
	}
	//concordinate the two lists
	printf("\nconcordinated list with duplicates: \n");
	for(i=0;i<5;i++)
	{
		new[i]=arr1[i];	
	}
	for(i=0;i<5;i++)
	{
		new[i+5]=arr2[i];
	}
	//displaying the concordinated list
	for(i=0;i<10;i++)
	{
		printf("%d ",new[i]);
	}
	//duplicating the concordinated list
	for(i=0;i<10;i++)
	{
		duplicate[i]=new[i];
	}
	//sorting
	for(i=0; i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(new[i]>new[j])
			{
				ch=new[i];
				new[i]=new[j];
				new[j]=ch;
			}
		}
	}
	printf("\nsorting:");
	for(i=0;i<10;i++)
	{
		printf("%d ",new[i]);
	}
	//removing the duplicates
	printf("\nwithout duplicates: ");
	for(i=0;i<10;i++)
	{
		//var=duplicate[i];
		for(j=0;j<10;j++)
		{
			if(duplicate[i]==duplicate[j])
			{	
				printf("%d", duplicate[i]);
				a[k]=duplicate[j];
				k++;
				count++;
			}
		}
	
	}
	//sum and mean
	for(i=0;i<10;i++)
	{
		sum+=new[i];
		avg=sum/10;	
	}
			printf("\nsum is: %d\n",sum );
		printf("average is: %d", avg);	
	return 0;
}




