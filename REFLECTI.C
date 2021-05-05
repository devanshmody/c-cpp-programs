#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
float a[3][3],b[3][3],c[3][3],i,j,k,x1,y1,x2,y2,x3,y3,x,y;
int gd,gm;
clrscr();
printf("enter input matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%f",&a[i][j]);
}
}
printf("input matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",a[i][j]);
}
printf("\n");
}
printf("enter reflection matrix");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%f",&b[i][j]);
}
}
printf("reflection matrix");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",b[i][j]);
}
printf("\n");
}
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
	c[i][j]=0;
	for(k=0;k<3;k++)
	{
	c[i][j]+=(a[i][k]*b[k][j]);
	}
	}
	}
printf("output matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",c[i][j]);
}
printf("\n");
}
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
x=getmaxx()/2;
y=getmaxy()/2;
line(0,y,getmaxx(),y);
line(x,0,x,getmaxy());
line(a[0][0]+x,a[0][1]+y,a[1][0]+x,a[1][1]+y);
line(a[1][0]+x,a[1][1]+y,a[2][0]+x,a[2][1]+y);
line(a[2][0]+x,a[2][1]+y,a[0][0]+x,a[0][1]+y);
line(c[0][0]+x,c[0][1]+y,c[1][0]+x,c[1][1]+y);
line(c[1][0]+x,c[1][1]+y,c[2][0]+x,c[2][1]+y);
line(c[2][0]+x,c[2][1]+y,c[0][0]+x,c[0][1]+y);
getch();
closegraph();
}