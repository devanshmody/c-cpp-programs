/*------------- z Transform of the sequence ------------------------------*/
//
//      This program computes the z-transform of the causal input sequence
//      at given value of z.
//
//                 Inputs :  1. Number of samples (n) in the sequence
//			     2.	Causal input sequence in the from
//				x[0],x[1],x[2],.....x[n-1]
//			     3. Real and Imaginary part of z at which
//				z-transform is to be evaluated.
//
//		  Outputs :     Real and Imaginary parts of X(z) at given
//				value of z.
//
//	      Assumptions :     The given sequence is causal.
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
	float x[20],Rz,Iz,zabs,theta,RealXz,ImagXz;
	int n,i,k;
	clrscr();
	printf("                            z Transform\n\n");
	printf("\nEnter the total number of samples(max 20) = ");
	scanf("\%d",&n);
	printf("Enter the samples of the sequence\n");
	for(i = 0; i < n; i++)  //sequence x[n] is entered here
	{
		printf("x[%d] = ",i);
		scanf("%f",&x[i]);
	}
	printf("\nEnter the value of z :\nReal part of z = ");
	scanf("%f",&Rz); // Value of z at which z transform is computed
	printf("Imaginary part of z = ");
	scanf("%f",&Iz);
	zabs = sqrt(Rz*Rz + Iz*Iz); //magnitude of z is computed here
	theta = atan(Iz/Rz);        //phase of z is computed here
	RealXz = ImagXz = 0.0;
	for(i = 0; i < n; i++)/*computation of real
				and imaginary parts of X(z)*/
	{
		RealXz += x[i]*cos(theta*i)*pow(zabs,-i); //real part
		ImagXz += x[i]*sin(theta*i)*pow(zabs,-i); //imaginary part
	}
	ImagXz = -ImagXz;
	printf("\nReal part of X(z) = %f",RealXz);
	printf("\nImag part of X(z) = %f",ImagXz);
}
//---------------------------End of program---------------------------------
