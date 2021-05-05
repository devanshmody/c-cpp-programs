#include<stdio.h>
#include<conio.h>
void main()
{
float n,f,t,mttr,mtbf,ava;
printf("opertion availibility\n");
scanf("%f",&n);
printf("frequency of failures\n");
scanf("%f",&f);
printf("total down time\n");
scanf("%f",&t);
mtbf=((n-t)/f);
printf("mean time before failure=%f \n",mtbf);
mttr=(t/f);
printf("mean time to repair=%f  \n",mttr);
ava=(mtbf/(mtbf+mttr))*100;
printf("availibility=%f% \n",ava);
getch();
}