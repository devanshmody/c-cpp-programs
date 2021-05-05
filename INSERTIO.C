#include<stdio.h>
#include<conio.h>
void insertion(int a[],int n)
{
int temp,i,j,c1,e,c2;
for(i=1;i<n;i++)
{
temp=a[i];
j=i-1;
c1++;
while(temp<a[j]&&j>=0)
{
e++;
a[j+1]=a[j];
j--;
}
a[j+1]=temp;
}
c2=c1+e;
printf("compare=%d\nexchange=%d\ncomplexity=%d\n",c1,e,c2);
}
void main()
{
int i,n,a[20];
clrscr();
printf("enter number of elements\n");
scanf("%d",&n);
printf("enter elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
insertion(a,n);
printf("sorted list");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
getch();
}