//file name : pzplot.cpp
/*----------------------- pole zero plot  ---------------------------*/
//
//      This program accepts poles and zeros and plots them
//      on the graphics screen.
//      The format of the poles and zeros is,
//      pole : pReal, pImag
//      zero : zReal, zImag
//
//   	Inputs :  Real and Imaginary parts of poles and zeros.
//
//	Outputs : Pole zero plot on screen

//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()

{
     float realZero[20],imagZero[20],realPole[20],imagPole[20];
     int M,N,i,gd,gm;

     clrscr();
     printf("   \nThis program generates pole-zero plot\n\n");
     printf("Enter the number of zeros  M = ");
     scanf("%d",&M);                   // number of zeros of the system
     printf("\nEnter the value of zero as =  real part imaginary part\n");
     for(i = 0; i < M;i++)
     {
       printf("re%d,  im%d = ",i+1,i+1
       );   // enter values of zeros
       scanf("%f%f",&realZero[i],&imagZero[i]);
     }
     printf("\nEnter the number of poles  N = ");
     scanf("%d",&N);                   // number of poles of the system
     printf("\nEnter the value of pole as =  real part imaginary part\n");
     for(i = 0; i < N;i++)
     {
       printf("re%d,  im%d = ",i+1,i+1);   // enter values of poles
       scanf("%f%f",&realPole[i],&imagPole[i]);
     }
//--------- Next part displays pole zero plot -------------------------

     detectgraph(&gd,&gm);  // detect graphics mode & graphics driver
     initgraph(&gd,&gm,""); // initialize screen in graphics mode
     setlinestyle(SOLID_LINE,1,1);  // solid line style for axis
     line(0,250,640,250);    // x-axis line for magnitude
     line(320,30,320,480);   // y-axis line for phase
     circle(320,250,200);
     for(i = 0; i < M; i++)  // This loop displays zeros
     {
	outtextxy(320+realZero[i]*200,250-imagZero[i]*200,"o");
     }
     // zeros and poles are scaled appropriately for display

     for(i = 0; i < N; i++)  // This loop displays poles
     {
	outtextxy(320+realPole[i]*200,250-imagPole[i]*200,"x");
     }
     outtextxy(250,10,"Pole zero plot");  // label of plot
     getch();                             // wait for observation
     closegraph();                        // close graphics mode
}
//---------------------------End of program---------------------------------
