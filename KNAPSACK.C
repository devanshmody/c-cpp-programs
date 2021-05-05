#include<stdio.h>
#include<conio.h>
void knapsack(int n,float w[],float p[],float m)
{
int i,j;
float x[20],tp,u;
u=m;
for(i=0;i<n;i++)
{
x[i]=0.0;
}
for(i=0;i<n;i++)
{
if(w[i]>u)
{
break;
}
else
{
x[i]=1.0;
tp=tp+p[i];
u=u-w[i];
}
}
if(i<n)
{
x[i]=u/w[i];
tp=tp+(x[i]*p[i]);
}
printf("objet   weight   profiit   share\n");
for(i=0;i<n;i++)
{
printf("%d %f %f %f\n",i+1,w[i],p[i],x[i]);
}
printf("maximum profit=%f\n",tp);
}
void main()
{
float w[20],p[20],r[20],m,t;
int n,i,j;
clrscr();
printf("enter no of objects");
scanf("%d",&n);
printf("enter weight and profit");
for(i=0;i<n;i++)
{
scanf("%f%f",&w[i],&p[i]);
r[i]=p[i]/w[i];
printf("ratio[%d]=%f\n",i,r[i]);
}
printf("enter capacity");
scanf("%f",&m);
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(r[i]<r[j])
{
t=r[i];
r[i]=r[j];
r[j]=t;
t=w[i];
w[i]=w[j];
w[j]=t;
t=p[i];
p[i]=p[j];
p[j]=t;
}
}
}
knapsack(n,w,p,m);
getch();
}