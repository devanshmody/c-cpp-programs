#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
char a[10][10];
int w[10][10],c[10][10],r[10][10],p[10],q[10];
int temp=0,root,min,min1,n,left,right21,right22;
int i,j,k,b;
clrscr();
printf("enter elements");
scanf("%d",&n);
printf("\n");
for(i=1;i<=n;i++)
{
	printf("enter elements",i);
	scanf("%d",&p[i]);
}
printf("\n");
for(i=0;i<=n;i++)
{
	printf("enter probablity");
	scanf("%d",&q[i]);
}
printf("w\t\tc\t\tr\n");
for(i=0;i<=n;i++)
{
	for(j=0;j<=n;j++)
	{
		if(i==j)
	{
	w[i][j]=q[i];
	c[i][j]=0;
	r[i][j]=0;
	printf("w[%d][%d]: %d\tc[%d][%d]: %d\tr[%d][%d]: %d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]);
	}
	}
}
printf("\n");
for(b=0;b<n;b++)
{
	for(i=0,j=b+1;j<n+1&&i<n+1;j++,i++)
	{
		if(i!=j&&i<j)
		{
			w[i][j]=p[j]+q[j]+w[i][j-1];
			min=1000;
			for(k=i+1;k<=j;k++)
			{
				min1=c[i][k-1]+c[k][j]+w[i][j];
				if(min>min1)
				{
					min=min1;
					temp=k;
				}
			}
			c[i][j]=min;
			r[i][j]=temp;
		}
		printf("w[%d][%d]: %d\tc[%d][%d]: %d\tr[%d][%d]: %d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]);
}
printf("\n");
}
printf("minimum cost=%d\n",c[0][n]);
root=r[0][n];
left=r[0][1];
right21=r[2][3];
right22=r[2][4];
printf("root=%d\tleft=%d\tright1=%d\tright2=%d\n",root,left,right21,right22);
getch();
}