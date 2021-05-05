#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
float p;
int gd,gm,i,val,r,x,y;
clrscr();
printf("enter the radius of a circle:");
scanf("%d",&r);
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
x=0;
y=r;
p=1.25-r;
	printf("X------Y\n");
do
	{
	putpixel(200+x,200+y,1);
	putpixel(200+y,200+x,2);
	putpixel(200+x,200-y,3);
	putpixel(200+y,200-x,4);
	putpixel(200-x,200+y,5);
	putpixel(200-x,200-y,6);
	putpixel(200-y,200+x,7);
	putpixel(200-y,200-x,8);

	printf("%d------%d\n",x,y);
if(p<0)
	{
	x=x+1;
	p=p+2*x+1;
	}
	else
	{
	x=x+1;
	y=y-1;
	p=p+2*(x-y)+1;
	}
	}
while(x<y);
getch();
closegraph();
}