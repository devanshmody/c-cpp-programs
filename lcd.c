#include<regx52.h>
#define data P2
sbit rs=P3^0;
sbit en=P3^1;
void delay(int);
void cmd(char a)
{
	rs=0;
	data = a;
	en=0;
	delay(1);
	en=1;
}
void dat(char b)
{
	data=b;
	rs=1;
	en=0;
	delay(1);
	en=1;
}
void lcdstring(char *item)
{
int x;
for(x=0;item[x]!=0;x++)
{
dat(item[x]);
delay(10);
}
}
void delay(int t)
{
int i,j;
for(i=0;i<t;i++)
{
for(j=0;j<1275;j++)
{
}
}
}
void main()
{
while(1)
{
	cmd(0x38);
	delay(200);
	cmd(0x06);
	delay(200);
	cmd(0x0e);
	delay(200);
	cmd(0x81);
	delay(200);
	lcdstring("AADESH");
	cmd(0xc2);
	lcdstring("SHAH");
	delay(300);
	cmd(0x01);
}
}