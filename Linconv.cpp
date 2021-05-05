/*------------- Linear Convolution of two sequences -----------------*/
//
//      This program computes the Linear Convolution of two causal
//     	sequences x(n) and h(n).
//
//                 Inputs :  1. Number of samples in h(n)
//			     2.	Samples of h(n) in the form
//				h[0],h[1],h[2],.....h[n-1]
//		             3. Number of samples in x(n)
//			     4.	Samples of x(n) in the form
//				x[0],x[1],x[2],.....x[n-1]
//
//		  Outputs :     Convolution sequence of x(n)
//				and h(n)
//
//	      Assumptions :     The given sequences are causal.
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
	float h[20],x[20],y[20],sum;
	int N,M,n,k;
	clrscr();
	printf("                    Linear Convolution\n\n");

	printf("Enter the number of samples in h(n) = ");
	scanf("%d",&N);                      // number of samples in h(n)
	printf("Enter the sequence h(n)\n");
	for(n = 0; n < N; n++)
	{
		printf("h[%d] = ",n);        //Entering the sequence h(n)
		scanf("%f",&h[n]);
	}

	printf("Enter the number of samples in x(n) = ");
	scanf("%d",&M);                      // number of samples in x(n)
	printf("Enter the sequence x(n)\n");
	for(n = 0; n < M; n++)
	{
		printf("x[%d] = ",n);         //Entering the sequence x(n)
		scanf("%f",&x[n]);
	}

	printf("\nThe result of convolution is...");
	for(n = 0; n < (N+M-1); n++)   // convolution calculation
	{
		sum = 0.0;
		for(k = 0; k < M; k++)        //   summation loop
		{
			if(n < k || (n-k)>= N) continue;
			sum += x[k] * h[n-k];
		}
		y[n] = sum;
		printf("\ny[%d] = %f",n,y[n]);
	}

}
//----------------------------End of program------------------------------