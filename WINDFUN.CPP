//file name : windfun.cpp
/*-- Magnitude and phase plots of the window function --------------*/
//
//      This program generates coefficients of window function
//      and calculates the magnitude and phase plots.
//
//                 Inputs :  1. Length of window function
//			     2.	Type of the window function
//
//		  Outputs :     Magnitude and phase plot
//
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
     float RealNum,ImagNum,M,n,temp;
     float mag[640],phase[640],pi,w,wStep;
     float static h[50],yMag,yPhase;
     int k,i,gd,gm,choice;
     pi = 22.0/7.0;            // value of pi
     clrscr();
     printf("   \nThis program displays the magnitude and phase"
	    " plots\n        of the given window function\n\n");

     printf("\n\nEnter the window you want to use");// choice of window
     printf("\nrectangular window (Enter 1)");            //rectangular
     printf("\ntriangular(bartlett) window (Enter 2)");    //triangular
     printf("\nhamming window (Enter 3)");                    //hamming
     printf("\nhanning window (Enter 4)\nchoice = ");         //hanning
     scanf("%d",&choice);                               // enter choice
     printf("\nEnter the length of the window = ");
     scanf("%f",&M);				     //length of window

//------- Next part calculates coefficients of window -----------------

     switch(choice)
     {
       case 1 : for(n = 0; n <= M-1; n++)                // rectangular
		{
		  h[n] = 1;                 //wn for rectangular window
		} break;
       case 2 : for(n = 0; n <= M-1; n++)                 // triangular
		{
		  h[n] = 1 - (2*abs(n-(M-1)/2)/(M-1)); // calculation of wn
		} break;
       case 3 : for(n = 0; n <= M-1; n++)                    // hamming
		{
		  h[n] = 0.54 - 0.46*cos((2*pi*n)/(M-1));         // wn
		} break;
       case 4 : for(n = 0; n <= M-1; n++)                    // hanning
		{
		  h[n] = (1-cos((2*pi*n)/(M-1)) )/2;// calculation of wn
		} break;
     }
     printf("The coefficients of the window are\n");
     for(i = 0; i < M; i++) printf("\nh[%d] = %1.3f",i,h[i]);
     getch();
//--------- Next part calculates magnitude and phase ------------------

     wStep = pi/640.0; // range of w = 0 to pi divided into small
//                           steps of pi/640 for displaying on screen.
     for(k = 0; k < 640; k++)
     {   // this loop computes magnitude and phase at 640 points
//                                        in the range of w = 0 to pi.
	w = w + wStep;         // steps by which w is increased.
	RealNum = h[0];        // real part of numerator
	ImagNum = 0;           // imaginary part of numerator
	for(i = 1; i < M; i++) // this  loop computes total real &
	{ //               imaginary parts of numerator seperately.
	  RealNum = RealNum + h[i]*cos(i*w);  //total real part.
	  ImagNum = ImagNum + h[i]*sin(i*w);  //total imaginary part.
	}
	ImagNum = ImagNum * (-1.0);  // change sign of imaginary part.

	mag[k] = sqrt(RealNum*RealNum + ImagNum*ImagNum);
		      //calculation of magnitude of transfer function
	phase[k] = atan2(ImagNum,RealNum);
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
	yMag = 250 - mag[k]*50; // magnitude scaled for proper display
	putpixel(k,yMag,WHITE); // put pixel of magnitude on the screen
	yPhase = 350 - phase[k]*10; // scaling of phase
	putpixel(k,yPhase,WHITE);   // put pixel of phase
     }
     outtextxy(500,200,"Magnitude plot"); // label of magnitude
     outtextxy(500,450,"Phase plot");     // label of phase
     getch();                             // wait for observation
     closegraph();                        // close graphics mode
}
//---------------------------End of program---------------------------------
