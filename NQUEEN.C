#include<stdio.h>
#include<conio.h>
int x[10];
int place(int k,int i);
void nqueen(int k,int n);
 int main()
{
int n;

printf("enter no of queens\n");
scanf("%d",&n);
nqueen(1,n);
getch();
}
void nqueen(int k,int n)
{
int i,j;
for(i=1;i<=n;i++)
	{
	if(place(k,i)==1)
		{
			x[k]=i;
			if(k==n)
			{
				for(j=1;j<=n;j++)
				{
					printf("%d\t",x[j]);
				}
			printf("\n");
			}
			else
			{
			nqueen(k+1,n);
			}
		}
	}
}
int place(int k,int i)
{
int j;
for(j=1;j<=k-1;j++)
	{
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
		{
			return 0;
		}
	}
return 1;
}
