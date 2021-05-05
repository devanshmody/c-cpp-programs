//file name : notch.cpp
/*-------------- Filter design using pole zero combination ----------*/
//
//      This program accepts the loaction of pole and zero
//      and gives the coefficients of difference equation.
//      It also shows the magnitude and phase plot of the filter.
//
//      The format of the difference equation is,
//      y(n) = -[a1*y(n-1)+a2*y(n-2)] + b0*x(n)+b1*x(n-1)+b2*x(n-2)
//
//      Inputs :     Angular position of pole and zero
//                   as position = r e^j(Theta)
//     Outputs :  1. Values of coefficients,i.e. a1,a2,b0,b1 & b2
//                2. Magnitude and phase transfer function
//                   plot H(e^jw) for w = 0 to pi.
//
// Assumptions :  1. This program is written for second order filter.
//                   It can be used for lowpass, highpass,bandpass,
//                   notch any type of pole zero combination.
//                2. The program accepts location of one pole and one
//                   zero and their conjugates are considered internally
//                   (see explanation for details)
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
     float rZ,ThetaZ,rP,ThetaP;
     float RealZ,ImagZ,RealP,ImagP;
     float RealNum,ImagNum,RealDen,ImagDen;
     float mag[640],phase[640],pi,w,wStep;
     float static a[10],b[10],yMag,yPhase;
     int M,N,i,k,gd,gm;

     clrscr();
     printf("\t\tFilter design using using pole zero combination");

     printf("\n\nEnter the angular position of pole and zero "
	  "\nthe program takes their conjugates internally "
	  "\n\npole or zero = r e^j(Theta)");
     printf("\nlocation of zero,  r  Theta : ");
     scanf("%f %f",&rZ,&ThetaZ);                    // location of zero
     printf("location of pole,  r  Theta : ");
     scanf("%f %f",&rP,&ThetaP);                    // location of pole

//   Next part of the program calculates coefficients of the
//                   difference equation. See program logic for details
     RealZ = rZ*cos(ThetaZ);     //|       these statements convert the
     ImagZ = rZ*sin(ThetaZ);     //|               angular positions to
     RealP = rP*cos(ThetaP);     //|                        rectangular
     ImagP = rP*sin(ThetaP);     //|                          positions
     b[0] = 1;                        //|
     b[1] = -2*RealZ;                 //|      these statements compute
     b[2] = RealZ*RealZ+ImagZ*ImagZ;  //|               coefficients of
     a[0] = 1;                        //|           difference equation
     a[1] = -2*RealP;                 //|                           see
     a[2] = RealP*RealP+ImagP*ImagP;  //|                   explanation

     printf("\nThe coefficients of the filter are as follows...");
     printf("\nb[0] = %f",b[0]);   // this loop prints the coefficients
     for(k = 1; k<=2; k++)         //                     on the screen
       printf("\nb[%d] = %f    a[%d] = %f",k,b[k],k,a[k]);
     printf("\npress any key to see magnitude/phase response");
     getch();

//----------- calculation of magnitude and phase response -------------
//   Next part of the program is taken as it is from "magphe.cpp",which
//                                is discussed and implemented earlier.
     M = 3; N = 2;
     pi = 22.0/7.0;                                      // value of pi
     wStep = pi/640.0; // range of w = 0 to pi divided into small steps
//                                   of pi/640 for displaying on screen
     for(k = 0; k < 640; k++)
     {          // this loop computes magnitude and phase at 640 points
//                                          in the range of w = 0 to pi
	w = w + wStep;                 // steps by which w is increased
	RealNum = b[0];                       // real part of numerator
	ImagNum = 0;                     // imaginary part of numerator
	for(i = 1; i < M; i++)      // this  loop computes total real &
	{ //                    imaginary parts of numerator seperately
	  RealNum = RealNum + b[i]*cos(i*w);          //total real part
	  ImagNum = ImagNum + b[i]*sin(i*w);     //total imaginary part
	}
	ImagNum = ImagNum * (-1.0);    // change sign of imaginary part
	RealDen = a[0];                     // real part of denominator
	ImagDen = 0;                   // imaginary part of denominator
	for(i = 1; i <= N; i++)      // this loop computes total real &
	{ //                  imaginary parts of denominator seperately
	  RealDen = RealDen + a[i]*cos(i*w);         // total real part
	  ImagDen = ImagDen + a[i]*sin(i*w);    // total imaginary part
	}
	ImagDen = ImagDen * (-1.0);    // change sign of imaginary part
	mag[k] = sqrt(RealNum*RealNum + ImagNum*ImagNum)/
			      sqrt(RealDen*RealDen + ImagDen*ImagDen);
			//calculation of magnitude of transfer function
	phase[k] = atan2(ImagNum,RealNum) - atan2(ImagDen,RealDen);
     }                      //calculation of phase of transfer function

//    Next part of program displays the magnitude & phase on the screen
//             which is calculated at 640 points by previous 'for' loop

     detectgraph(&gd,&gm);    // detect graphics mode & graphics driver
     initgraph(&gd,&gm,"");       // initialize screen in graphics mode
     setlinestyle(DOTTED_LINE,1,1);     // dotted line style for x-axis
     line(0,250,640,250);                  // x-axis line for magnitude
     line(0,350,640,350);                      // x-axis line for phase
     for(k = 0; k < 640; k++) // this loop puts 640 pixels of magnitude
     {//                                        and phase on the screen
	yMag = 250 - mag[k]*25;  // magnitude scaled for proper display
	putpixel(k,yMag,YELLOW);// put pixel of magnitude on the screen
	yPhase = 350 - phase[k]*50;                 // scaling of phase
	putpixel(k,yPhase,GREEN);                 // put pixel of phase
     }
     outtextxy(500,200,"Magnitude plot");         // label of magnitude
     outtextxy(500,450,"Phase plot");                 // label of phase
     getch();                                   // wait for observation
     closegraph();                               // close graphics mode
}
//---------------------------End of program---------------------------------

