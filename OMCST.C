#include<stdio.h>;
#include<conio.h>
#include<stdlib.h>
void con(void);
void print(int,int);
int p[20],q[20],wt[20][20],c[20][20];
int r[20],n;
void main()
{
int i;
clrscr();
printf("enter number of nodes");
scanf("%d",&n);
printf("enter frequencies of sucessful search");
for(i=1;i<=n;i++)
{
printf("p[%d]=",i);
scanf("%d",&p[i]);
}
printf("enter frequencies of unsucessful search");
for(i=0;i<=n;i++)
{
printf("q[%d]=",i);
scanf("%d",&q[i]);
}
con();
print(0,n);
getch();
}
}
void con(void)
{
int i,j,k,l,min;
for(i=0;i<n;i++)
{
c[i][i]=0;
r[i][i]=0;
wt[i][i]=q[i];
wt[i][i+1]=q[i]+q[i+1]+p[i+1];
c[i][i+1]=q[i]+q[i+1]+p[i+1];
r[i][i+1]=i+1;
}
c[n][n]=0;
r[n][n]=0;
wt[n][n]=q[n];
for(i=2;i<=n;i++)
{
for(j=0;j<=n-i;j++)
{
wt[j][j+i]=p[j+i]+wt[j][j+i-1];
c[j][j+1]=9999;
for(l=j+1;l<=j+i;l++)
{
if(c[j][j+i]>(c[j][l-1]+c[l][j+i]))
{
c[j][j+i]=c[j][l-1]+c[l][j+i];
r[j][j+i]=1;
}
}
printf("wt[0][%d]%d",n,wt[0][n]);
printf("c[0][%d]%d",n,c[0][n]);
printf("r[0][%d]%d",n,r[0][n]);
}
void print(int ll,int rl)
{
if(ll>=rl)
return;
if(r[ll][r[ll][rl]-1]!=0)
printf("left child %d%d\n",r[ll][rl],r[ll][r[ll][rl]-1]);
if(r[r[ll][rl]][rl]!=0);
printf("right child%d%d\n",r[ll][rl],r[r[ll][rl]][rl]);
print(ll,r[ll][rl]-1);
print(r[ll][rl],rl);
return;
}

}