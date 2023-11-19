#include<stdio.h>
int main(){
	int a[20],b[20],c[40],d[40],i,l1,l2,n,flag,j=0,k=0,m=0,temp;
	printf("Enter no of Elements in List 1: ");
	scanf("%d",&l1);
	for(i=0;i<l1;i++){
		printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);}
	printf("\nEnter no of Elements in List 2: ");
	scanf("%d",&l2);
	for(i=0;i<l2;i++){
		printf("Enter Element %d: ",i+1);
		scanf("%d",&b[i]);}
	//with Duplicates
	for(i=0;i<l1+l2;i++){
		if(i<l1)
			c[j++]=a[k++];
		else 
			c[j++]=b[m++];}
	printf("\nAfter Combining:\n\n");
	printf("\t----->With Duplicates   : ");
	for(i=0;i<j;i++)
		printf("%d ",c[i]);
	printf("\n");
	//without duplicates
	j=0;k=0;m=0;
		for(i=0;i<l1+l2;i++){
			flag=0;
			if(i<l1){
				for(n=0;n<j;n++){
					if(a[k]==c[n]){ flag=1;}}
				if(flag==0) d[j++]=a[k++];
				else k++;}
			else {
				for(n=0;n<j;n++){ if(b[m]==c[n]){flag=1;}}
				if(flag==0)d[j++]=b[m++];
				else   m++;}}
	printf("\n\t----->WithOut Duplicates:");
	printf("\n\n\t\t\t----->Not Sorted: ");
	for(i=0;i<j;i++)
		printf("%d ",d[i]);
	printf("\n");
	//Sorting
	for(i=0;i<j-1;i++){
		for(k=0;k<j-i-1;k++){
			if(d[k]>d[k+1]){
				temp=d[k];d[k]=d[k+1];d[k+1]=temp;}}}
	printf("\n\t\t\t----->Sorted    : ");
	for(i=0;i<j;i++)
		printf("%d ",d[i]);
	printf("\n\n\n");}

