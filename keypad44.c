#include<regx52.h>
sbit R1=P1^0;
sbit R2=P1^1;
sbit R3=P1^2;
sbit R4=P1^3;
sbit C1=P1^4;
sbit C2=P1^5;
sbit C3=P1^6;
sbit led1=P2^0;
sbit led2=P2^1;
sbit led3=P2^2;
sbit led4=P2^3;
sbit led5=P2^4;
sbit led6=P2^5;
sbit led7=P2^6;
sbit led8=P2^7;
sbit led9=P3^0;
sbit led10=P3^1;
sbit led11=P3^2;
sbit led12=P3^3;
void delay(int t)
{
int i,j;
for(i=0;i<t;i++)
{
for(j=0;j<1275;j++)	 {}
}
}
void main()
{
P2=0x00;
P3=0x00;
C1=1;
C2=1;
C3=1;
R1=0;
R2=1;
R3=1;
R4=1;
if(C1==0)
{
delay(1);
while(C1==0)
led1=1;

}
if(C2==0)
{
delay(1);
while(C2==0)
led2=1;

}
if(C3==0)
{
delay(1);
while(C3==0)
led3=1;
}
R1=1;
R2=0;
R3=1;
R4=1;
if(C1==0)
{
delay(1);
while(C1==0)
led4=1;
}
if(C2==0)
{
delay(1);
while(C2==0)
led5=1;
}
if(C3==0)
{
delay(1);
while(C3==0)
led6=1;
}
R1=1;
R2=1;
R3=0;
R4=1;
if(C1==0)
{
delay(1);
while(C1==0)
led7=1;
}
if(C2==0)
{
delay(1);
while(C2==0)
led8=1;
}
if(C3==0)
{
delay(1);
while(C3==0)
led9=1;
}
R1=1;
R2=1;
R3=1;
R4=0;
if(C1==0)
{
delay(1);
while(C1==0)
led10=1;
}
if(C2==0)
{
delay(1);
while(C2==0)
led11=1;
}
if(C3==0)
{
delay(1);
while(C3==0)
led12=1;
}

}
