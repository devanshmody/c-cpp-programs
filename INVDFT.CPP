//file name : invdft.cpp
/*------------- Inverse Discrete Fourier Transform(IDFT) ------------*/
//
//	This program computes the Inverse DFT of N point X(k).
//
//	Inputs :  1. Length of the DFT i.e. N
//		  2. Real and Imaginary parts of DFT X(k).
//
//	Outputs :    N point sequence i.e. x(n)
//
//	Assumptions: The sequence x(n) is considered real.
//---------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
   float static x[100],XReal[100],XImag[100],pi;
   float k,n,N;

   clrscr();
   printf("\t\tInverse Discrete Fourier Transform(IDFT)\n");
   printf("\nEnter the length of the DFT  N = ");
   scanf("%f",&N);                                 // length of the DFT
   printf("\nEnter the real amd imaginary parts of X(k) as follows\n"
	  "X(k) = Re{X(k)}  Im{X(k)}\n");
   for(k = 0; k < N; k++)
   {
      printf("X(%1.0f) = ",k);                   // enter values of DFT
      scanf("%f %f",&XReal[k],&XImag[k]);
   }

// next part of the program computes inverse DFT

   pi = 22.0/7.0;                                        // value of pi
   for(n = 0; n < N; n++)
   {
      x[n] = 0;
      for(k = 0; k < N; k++)    // this loop computes one value of x(n)
      {
	 x[n] = x[n] + XReal[k]*cos((2*pi*k*n)/N)
		      - XImag[k]*sin((2*pi*k*n)/N);
      }
      x[n] = x[n]/N;
   }
//   Next part of program displays x(n) on the screen

     printf("\nThe sequence x(n) is as follows...");
     for(n = 0; n < N; n++)            // displaying x(n) on the screen
	printf("\nx(%1.0f) =  %3.6f",n,x[n]);
}
//---------------------------End of program---------------------------------
