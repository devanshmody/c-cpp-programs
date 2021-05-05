//file name : magphe.cpp
/*-- Magnitude and phase transfer function plots of a difference equation --*/
//
//      This program accepts the coefficients of the difference
//      equation and generates the magnitude and phase transfer
//      function plots.
//
//      The format of the difference equation is,
//      y(n) = -[a1*y(n-1)+a2*y(n-2)+a3*y(n-3)+........]
//                +b0*x(n)+b1*x(n-1)+b2*x(n-2)+.......
//
//                 Inputs :  1. Number of coefficients of x(n) i.e. M.
//			     2.	Values of coefficients of x(n),
//                                               i.e. b0,b1,b2,....etc.
//                           3. Number of coefficients of y(n) i.e. N.
//			     4. Values of coefficients of y(n),
//                                               i.e. a1,a2,a3,....etc.
//
//		  Outputs :     Magnitude and phase transfer function
//                              plot H(e^jw) for w = 0 to pi.
//
//	      Assumptions :     This program is written for up to ten
//                              coefficients.
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
     float RealNum,ImagNum,RealDen,ImagDen;
     float mag[640],phase[640],pi,w,wStep;
     float static a[10],b[10],yMag,yPhase;
     int M,N,i,k,gd,gm;

     clrscr();
     printf("   \nThis program displays the magnitude and phase"
	    " transfer function plots\nfrom given coefficients of"
	    " difference equation \n\n");
     printf("\nenter the number of coefficients of x(n), M = ");
     scanf("%d",&M);
     for(i = 0; i < M; i++)
     {                         // coefficients of x(n)
	printf("b%d = ",i);
	scanf("%f",&b[i]);     // b0,b1,b2,....
     }
     printf("\nenter the number of coefficients of y(n), N = ");
     scanf("%d",&N);
     a[0] = 1.0;
     for(i = 1; i <= N; i++)
     {                         // coefficients of y(n)
	printf("a%d = ",i);
	scanf("%f",&a[i]);     // a1,a2,a3,.....
     }
     pi = 22.0/7.0;            // value of pi
     wStep = pi/640.0; // range of w = 0 to pi divided into small
//                           steps of pi/640 for displaying on screen.
     for(k = 0; k < 640; k++)
     {   // this loop computes magnitude and phase at 640 points
//                                        in the range of w = 0 to pi.
	w = w + wStep;         // steps by which w is increased.
	RealNum = b[0];        // real part of numerator
	ImagNum = 0;           // imaginary part of numerator
	for(i = 1; i < M; i++) // this  loop computes total real &
	{ //               imaginary parts of numerator seperately.
	  RealNum = RealNum + b[i]*cos(i*w);  //total real part.
	  ImagNum = ImagNum + b[i]*sin(i*w);  //total imaginary part.
	}
	ImagNum = ImagNum * (-1.0);  // change sign of imaginary part.
	RealDen = a[0];        // real part of denominator
	ImagDen = 0;           // imaginary part of denominator
	for(i = 1; i <= N; i++)// this loop computes total real &
	{ //                imaginary parts of denominator seperately.
	  RealDen = RealDen + a[i]*cos(i*w);  // total real part
	  ImagDen = ImagDen + a[i]*sin(i*w);  // total imaginary part
	}
	ImagDen = ImagDen * (-1.0);  // change sign of imaginary part
	mag[k] = sqrt(RealNum*RealNum + ImagNum*ImagNum)/
			      sqrt(RealDen*RealDen + ImagDen*ImagDen);
		      //calculation of magnitude of transfer function
	phase[k] = atan2(ImagNum,RealNum) - atan2(ImagDen,RealDen);
     }                //calculation of phase of transfer function

// Next part of program displays the magnitude & phase on the screen
//           which is calculated at 640 points by previous 'for' loop

     detectgraph(&gd,&gm);  // detect graphics mode & graphics driver
     initgraph(&gd,&gm,""); // initialize screen in graphics mode
     setlinestyle(DOTTED_LINE,1,1);  // dotted line style for x-axis
     line(0,250,640,250);   // x-axis line for magnitude
     line(0,350,640,350);   // x-axis line for phase
     for(k = 0; k < 640; k++) // this loop puts 640 pixels of
     {//                            magnitude and phase on the screen
	yMag = 250 - mag[k]*25; // magnitude scaled for proper display
	putpixel(k,yMag,WHITE); // put pixel of magnitude on the screen
	yPhase = 350 - phase[k]*50; // scaling of phase
	putpixel(k,yPhase,WHITE);   // put pixel of phase
     }
     outtextxy(500,200,"Magnitude plot"); // label of magnitude
     outtextxy(500,450,"Phase plot");     // label of phase
     getch();                             // wait for observation
     closegraph();                        // close graphics mode
}
//---------------------------End of program---------------------------------

