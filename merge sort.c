#include<stdio.h>
int arr[100],i,j,k,l,r,m,n,n1,n2;
int mergesort(int,int);
int merge(int, int, int);
int mergesort(int l,int r)
{
	if(l<r)
	{
		m=(l+r)/2;
		mergesort(l,m);
		mergesort(m+1,r);
		merge(l,m,r);	
	}
}
int merge(int l,int m,int r)
{
	n1=m-l+1;
	n2=r-m;
	k=l;
	int L[n1], R[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=arr[l+i];
	}
	for(j=0;j<n2;j++)
	{
		R[j]=arr[m+1+j];
	}
	i=0;
	j=0;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k++]=L[i++];
		}
		else
		{
			arr[k++]=R[j++];
		}
	}
	while(i<n1)
	{
		arr[k++]=L[i++];
	}
	while(j<n2)
	{
		arr[k++]=R[j++];
	}
}
int main()
{
	printf("MERGE SORT\n");
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	l=0;
	r=n-1;
	mergesort(l,r);
	printf("\nSorted array: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
}

