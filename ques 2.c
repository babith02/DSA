#include<stdio.h>
struct student{
	int reg;
	char name[25];
	int num;
	float gpa;
}a[2];
int main()
{
	int i, j;
	for(i=0; i<2; i++)
	{
		
		printf(" Enter the details of student %d \n", i+1);
		printf("Enter the reg num:");
		scanf("%d", &a[i].reg);
		printf("Enter the name:");
		scanf("%s", a[i].name);
		printf("Enter the phone num:");
		scanf("%d", &a[i].num);
		printf("Enter the gpa:");
		scanf("%d", &a[i].gpa);		
	}
	for(i=0; i<2; i++)
	{
		printf("\nDETAILS OF THE STUDENT  %d \n", i+1);
		printf("register num is: %d \n", a[i].reg);
		printf("name is: %s \n", a[i].name);
		printf("phone number is:%d \n", a[i].num);
		printf("gpa is:%d \n", a[i].gpa);		
	}
	return 0;
}
