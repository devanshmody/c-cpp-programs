#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int j,k,i,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void main()
{
clrscr();
printf("enter number of vertices");
scanf("%d",&n);
printf("\n enter the cost adjcency matrix");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
}
}
printf("the edegs of minimum cost spanning tree are\n\n");
while(ne<n)
{
for(i=1,min=999;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(cost[i][j]<min)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
}
}
u=find(u);
v=find(v);
if(uni(u,v))
{
printf("edge%d--->(%d,%d)====%d\n",ne++,a,b,min);
mincost+=min;
}
cost[a][b]=cost[b][a]=999;
}
printf("\n\tminimum cost=%d\n",mincost);
getch();
}
int find(int i)
{
while(parent[i])
{
i=parent[i];
}
return i;
}
int uni(int i,int j)
{
if(i!=j)
{
parent[j]=i;
return 1;
}
return 0;
}
