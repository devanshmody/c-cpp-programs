#include<stdio.h>
#include<conio.h>
#define size 5
int st[size];
int top=-1;
void push(int data);
void pop();
void peak();
void disp();
int isempty();
int isfull();
void main()
{
	int data,ch;
	clrscr();
	do
	{
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.peak\n");
		printf("4.display\n");
		printf("enter choice (1-4)");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter data");
					scanf("%d",&data);
					push(data);
					break;
			case 2 : pop();
			break;
			case 3: peak();
			break;
			case 4: dipl();
			break;
		}
			
	}while(ch<4);
	getch();
}
int isempty()
{
	if(top==-1);
	return 1;
	else
	return 0;
}
int isfull()
{
	if(top==size-1);
	return 1;
	else
	return 0;
}
void push(int data)
{
	if(isfull()==1)
	printf("overflow");
	else
	top++;
	st[top]=data;
}
void pop()
{
	if(isempty()==1)
		printf("underflow");
		else
			printf("data removed=%d",st[top]);
			top--;
}
void peak()
{
	if(isfull()==1)
		printf("ov");
	else
		printf("data=%d",st[top]);
	if(isempty()==1)
		printf("underflow");
	else
		printf("data=%d",st[top]);
}
void disp()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d\n",st[i]);
	}
}