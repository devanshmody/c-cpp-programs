#include<stdio.h>
#include<conio.h>
void main()
{
	int n,m,i,j,k,x[10],h[10],y[10],mul[10][10];
	clrscr();
	printf("Enter value of n: ");
	scanf("%d",&n);
	printf("Enter value of m: ");
	scanf("%d",&m);
	printf("Enter x(n):\n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	printf("Enter h(n):\n");
	for(i=0;i<m;i++)
		scanf("%d",&h[i]);
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			mul[j][i]=x[i]*h[j];
			printf("%d\t",mul[j][i]);
		}
		printf("\n");
	}
	for(i=0;i<10;i++)
		y[i]=0;
	k=0;
	while(k<(n+m))
	{
		for(j=0;j<m;j++)
		{
			for(i=0;i<n;i++)
			{
				if((i+j)==k)
				{
					y[k]=y[k]+mul[j][i];
				}
			}
		}
		k++;
	}
	for(i=0;i<(n+m-1);i++)
		printf("%d ",y[i]);
	getch();
}