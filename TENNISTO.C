#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[50][50];
void tennis(int);
int main()
{
int i,n,j,m;

printf("enter no of players");
scanf("%d",&n);
m=n;
tennis(m);
for(i=1;i<=n;i++)
{
for(j=1;j<n;j++)
printf("\t%d",a[i][j]);
printf("\n");
}
getch();
}
void tennis(int n)
{
int p,d;
if(n==2)
{
a[1][1]=2;
a[2][1]=1;
}
else
{
tennis(n/2);
for(p=(n/2)+1;p<=n;p++)
{
for(d=1;d<n/2;d++)
{
a[p][d]=a[p-n/2][d]+n/2;
}
}
for(p=1;p<=n/2;p++)
{
for(d=n/2;d<n;d++)
{
if((p+d)<=n)
{
a[p][d]=p+d;
}
else
{
a[p][d]=(p+d)%n+(n/2);
}
}
}
for(d=n/2;d<n;d++)
{
for(p=(n/2+1);p<=n;p++)
{
if((p-d)>0)
a[p][d]=p-d;
else
a[p][d]=(p-d)+(n/2);
}
}
}
}
