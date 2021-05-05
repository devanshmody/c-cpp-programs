#include<stdio.h>
int main()
{
     float analog[7][5] ;
     float sampling[10] ;
     float discrete[10] ;
     float i,j,k;
     printf("enter values for analog signal");
     for(i=0;i<7;i++)
     {
       for(j=0;j<5;j++)
	 {
	    scanf("%f",&analog[i][j]);
	 }
     }
     printf("enter values for sampling signal");
       for(k=0;k<7;k++)
	   scanf("%f",&sampling[k]);
      for(i=0;i<7;i++)
      {
	 for(j=0;j<4;j++)
	 if(i==sampling[i])
	 discrete[i]=analog[j][i];
	 }

	 printf("the discrete signal is");
	 for(i=0;i<10;i++)
       printf("%f\t",discrete[i]);
	return 1;
  }
