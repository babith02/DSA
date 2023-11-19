#include<stdio.h>
#include<conio.h>
#include<math.h>
int power(int);
int strassen(int*,int*,int*,int,int);
int main()
{
    int i,j,k,n1,n2,n3,n,m;
    printf("FIRST MATRIX\n");
    printf("Enter no of rows and columns:\n");
    scanf("%d%d",&n1,&n2);
    int A[n1][n2];
    printf("\nEnter the elements:\n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
        	//printf("A[i][j]:",i+1,j+1);
        	scanf("%d",&A[i][j]);
	   }
            
    }
    printf("SECOND MATRIX\n");
    printf("\nEnter the no. of columns:\n");
    scanf("%d",&n3);
    int B[n2][n3];
    printf("\nEnter the elements:\n");
  for(i=0;i<n2;i++)
    {
        for(j=0;j<n3;j++)
        {
        	//printf("B[i][j]",i+1,j+1);
        	scanf("%d",&B[i][j]);
	   }
            
    }
    //creating square matrix of order 2^n for all and initializing all elements to 0 except prefixed

    if(n1>=n2 && n1>=n3)
        n=n1;
    else if(n2>=n1 && n2>=n3)
        n=n2;
    else
        n=n3;
    int o=1;
    while(n>power(o))
        o=o+1;
    m=power(o);
    int a[m][m],b[m][m],c[m][m];
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j]=0;
            b[i][j]=0;
        }
    }
    for(i=0;i<n1;i++)
        for(j=0;j<n2;j++)
        a[i][j]=A[i][j];
    for(i=0;i<n2;i++)
        for(j=0;j<n3;j++)
        b[i][j]=B[i][j];
   for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            c[i][j]=0;

    strassen(a,b,c,m,m);
    /*printf("Elements of the FIRST MATRIX: \n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
        	printf("%d\t",&A[i][j]);
	   }
	   printf("\n");
            
    }
    printf("Elements of the SECOND MATRIX: \n");
	for(i=0;i<n2;i++)
    {
        for(j=0;j<n3;j++)
        {
        	printf("%d\t",&B[i][j]);
	   }
	   printf("\n");
            
    }*/
    printf("Result matrix\n");
    for(i=0;i<n1;i++){
        for(j=0;j<n3;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }

}
int power(int n)
{
    int i,p=1;
    for(i=0;i<n;i++)
        p=2*p;
    return p;
}
int strassen(int* A,int* B,int* C, int m, int n){
        if(m==2)
        {
            int p=(*A+*(A+n+1))*(*B+*(B+n+1));//p=(A[0][0]+A[1][1])*(B[0][0]+B[1][1])
            int q=(*(A+n)+*(A+n+1))*(*B);//q=(A[1][0]+A[1][1])*B[0][0]
            int r=(*A)*(*(B+1)-*(B+n+1)); //r=A[0][0]*(B[0][1]-B[1][1])
            int s=(*(A+n+1))*(*(B+n)-*B);// s=A[1][1]*(B[1][0]-B[0][0])
            int t=(*A+*(A+1))*(*(B+n+1));// t=(A[0][0]+A[0][1])*B[1][1]
            int u=(*(A+n)-*A)*(*B+*(B+1)); //u=(A[1][0]-A[0][0])*(B[0][0]+B[0][1])
            int v=(*(A+1)-*(A+n+1))*(*(B+n)+*(B+n+1)); // v=(A[0][1]-A[1][1])*(B[1][0]+B[1][1])

            *C=*C+p+s-t+v;
            *(C+1)=*(C+1)+r+t;
            *(C+n)=*(C+n)+q+s;
            *(C+n+1)=*(C+n+1)+p+r-q+u;
             }

             else{
                m=m/2;
                strassen(A,B,C,m,n);
                strassen(A,B+m,C+m,m,n);
                strassen(A+m,B+m*n,C,m,n);
                strassen(A+m,B+m*(n+1),C+m,m,n);
                strassen(A+m*n,B,C+m*n,m,n);
                strassen(A+m*n,B+m,C+m*(n+1),m,n);
                strassen(A+m*(n+1),B+m*n,C+m*n,m,n);
                strassen(A+m*(n+1),B+m*(n+1),C+m*(n+1),m,n);

             }
}

