#include<stdio.h>
#include<conio.h>
int c=0;
int s=0;
int part(int x[],int lb,int ub)
{
int a,temp,up,down;
a=x[lb];
up=ub;
down=lb;
while(down<up)
{
while(x[down]<=a&&down<ub)
{
down++;
c++;
}
while(x[up]>a)
{
up--;
c++;
}
if(down<up)
{
temp=x[down];
x[down]=x[up];
x[up]=temp;
s++;
}
}
x[lb]=x[up];
x[up]=a;
return up;
}
void quick(int x[],int lb,int ub)
{
int j;
if(lb>=ub)
return;
j=part(x,lb,ub);
quick(x,lb,j-1);
quick(x,j+1,ub);
}
void main()
{
int a[50],n,i;
clrscr();
printf("enter no elements");
scanf("%d",&n);
printf("enter elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
quick(a,0,n-1);
printf("sorted");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("comparison=%d and swap=%d",c,s);
getch();
}



