//file name : plz2cff.cpp
/*------- pole and zeros to coefficients of difference equation ----------*/
//
//      This program computes the coefficients of a difference equation
//      from given poles and zeros.
//      The format of the difference equation is,
//      y(n) = -[a1*y(n-1)+a2*y(n-2)+a3*y(n-3)+........]
//                +b0*x(n)+b1*x(n-1)+b2*x(n-2)+.......
//
//                 Inputs :  1. Number of zeros of the system.
//			     2.	Real and imaginary parts of the zeros.
//                           3. Number of poles of the system.
//			     4. Real and Imaginary parts of the poles.				z-transform is to be evaluated.
//
//		  Outputs :     Coefficients b0,b1,b3,...etc and
//                              a1,a2,a3,...etc are displayed separately
//
//	      Assumptions :     This program is written for maximum four
//                              complex valued poles and zeros.
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()

{
     float static realZero[5],imagZero[5],magZero[5],angZero[5];
     float static realPole[5],imagPole[5],magPole[5],angPole[5];
     float static a[5],b[5];
     int M,N,i;

     void coeff(float x[],float y[],float q[]);

     clrscr();
     printf("   \nThis program computes the coefficients of a difference"
	   " equation\n     from given poles and zeros\n\n");
     printf("Enter the number of zeros (max 4), M = ");
     scanf("%d",&M);                   // number of zeros of the system
     printf("\nEnter the value of zero as =  real part imaginary part\n");
     for(i = 1; i <= M;i++)
     {
       printf("re%d,  im%d = ",i,i);   // enter values of zeros
       scanf("%f%f",&realZero[i],&imagZero[i]);
       magZero[i] = sqrt(realZero[i]*realZero[i]
		       + imagZero[i]*imagZero[i]);
		 // convert value of zero to polar form - magnitude
       angZero[i] = atan2(imagZero[i],realZero[i]);
     }           // convert value of zero to polar form - phase
     printf("\nEnter the number of poles (max 4, N = ");
     scanf("%d",&N);                   // number of poles of the system
     printf("\nEnter the value of pole as =  real part imaginary part\n");
     for(i = 1; i <= N;i++)
     {
       printf("re%d,  im%d = ",i,i);   // enter values of poles
       scanf("%f%f",&realPole[i],&imagPole[i]);
       magPole[i] = sqrt(realPole[i]*realPole[i]
		       + imagPole[i]*imagPole[i]);
		 // convert value of pole to polar form - magnitude
       angPole[i] = atan2(imagPole[i],realPole[i]);
     }           // convert value of pole to polar form - phase
     coeff(magZero,angZero,b);         // calculate b0,b1,b2,...
     coeff(magPole,angPole,a);         // calculate a1,a2,a3,...

     printf("\nThe coefficients b0,b1,b2,.. are as follows..\n");
     for(i = 0; i <= M; i++)  // print coefficients b0,b1,b2,...
		 printf("\nb%d = %f",i,b[i]);
     printf("\n\nThe coefficients a1,a2,a3,... are as follows..\n");
     for(i = 1; i <= N; i++)  // print coefficients a1,a2,a3,...
		 printf("\na%d = %f",i,a[i]);
}

void coeff(float x[],float y[],float q[])
{ // this function calculates coefficients of the equation and returns
  // array q[]. It accepts magnitude and phase i.e. polar form of the
  // pole or zero. This function works up to four complex valued poles
  // or zeros, however this logic can be generalized for higher number
  // of poles and zeros. See explanation for details.

  q[0] = 1;
  q[1] = -(  x[1]*cos(y[1]) + x[2]*cos(y[2])
	   + x[3]*cos(y[3]) + x[4]*cos(y[4]));

  q[2] =  x[1]*x[2]*cos(y[1]+y[2]) + x[1]*x[3]*cos(y[1]+y[3])
	+ x[1]*x[4]*cos(y[1]+y[4]) + x[2]*x[3]*cos(y[2]+y[3])
	+ x[2]*x[4]*cos(y[2]+y[4]) + x[3]*x[4]*cos(y[3]+y[4]);

  q[3] = -(  x[1]*x[2]*x[3]*cos(y[1]+y[2]+y[3])
	   + x[1]*x[3]*x[4]*cos(y[1]+y[3]+y[4])
	   + x[2]*x[3]*x[4]*cos(y[2]+y[3]+y[4])
	   + x[2]*x[4]*x[1]*cos(y[2]+y[4]+y[1]));

  q[4] = x[1]*x[2]*x[3]*x[4]*cos(y[1]+y[2]+y[3]+y[4]);
  return; // here sin terms are not considered since they
}         //                                cancel each other
//---------------------------End of program---------------------------------

