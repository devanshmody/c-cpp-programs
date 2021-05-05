#include<stdio.h>
#include<conio.h>
void selection(int a[],int n)
{
int i,j,temp,min,loc,c=0;
for(i=0;i<n-1;i++)
{
min=a[i];
loc=i;
for(j=i+1;j<n;j++)
{
c++;
if(min>a[j])
{
min=a[j];
loc=j;
}
temp=a[i];
a[i]=a[loc];
a[loc]=temp;
}
}
printf("the count is%d\n",c);
}
void main()
{
int i,n,a[20];
clrscr();
printf("enter no elements");
scanf("%d",&n);
printf("enter elemenets");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
selection(a,n);
printf("sorted");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
getch();
}

