/*------- Generation of samples of some standard signals  -------------*/
//
//      This program generates the samples of cosine, sine, square,
//     	exponential and random noise at specified sampling frequencies.
//
//                 Inputs :  1. Frequencies of cosine, sine and
//				square waves.
//			     2.	Sampling frequency
//		             3. Choice for the signal to be generated.
//
//		  Outputs :  1. The samples of the discrete time
//				signal are stored in the array.
//			     2. The discrete time signal is displayed
//				on the screen in graphics mode.
//
//	      Assumptions :     The number of samples of the signal
//				and their amplitudes are assumed in the
//				program.
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
void main()
{
   float x[700],A,F,Fs,n,Y;
   int i,gd,gm,X,choice,k;
   clrscr();

   printf("         Generation of discrete time signals \n");
   printf("\nEnter the frequency of analog signal F = ");
   scanf("%f",&F);                           //frequency of the signal
   printf("Enter the sampling frequency Fs = ");
   scanf("%f",&Fs);                          //sampling frequency
   printf("\nEnter your choice");
   printf("\ncosine wave (Enter 1)");        //cosine wave
   printf("\nsine wave (Enter 2)");          //sine wave
   printf("\nsquare wave (Enter 3)");        //square wave
   printf("\nexponential signal (Enter 4)"); //exponential signal
   printf("\nRandom noise (Enter 5)\nChioce = ");   //random noise
   scanf("%d",&choice);
   i = 640;            //640 samples of the signal will be generated
   A = 1.0;            //maximum amplitude of the signals is 1
   switch(choice)
   {
     case 1 : for(n = 0; n < i; n++) // cosine wave
	      x[n] = A * cos( 2 * 3.1415927 * F * (n/Fs));
	      break;
     case 2 : for(n = 0; n < i; n++) // sine wave
	      x[n] = A * sin( 2 * 3.1415927 * F * (n/Fs));
	      break;
     case 3 : k = 0;                 // square wave
	      do
	      {
		for( n = (k*Fs)/(2*F); n < ((k+1)*Fs)/(2*F); n++)
		{     // positive half cycle of aquare wave
		   x[n] = A;     if(n>i)break;
		}
		for(n = ((k+1)*Fs)/(2*F); n < ((k+2)*Fs)/(2*F); n++)
		{     // negative half cycle of aquare wave
		   x[n] = -A;    if(n>i) break;
		}
		k = k+2;  // this count is modified for next cycle
	      }  while(n<i);
	      break;
     case 4 : for(n = 0; n < i; n++)     // exponential signal
	      x[n] = A * exp( -(n/Fs));
	      break;
     case 5 : for(n = 0; n < i; n++)     // random noise
	      x[n] = (float)(rand()%1000)/1000.0;
	      break;
   }
//-------- next part of the program displays the generated signal
   Y = X = 0;
   gd = DETECT;
   initgraph(&gd,&gm,"");    // initialize screen in graphics mode
   for(n = 0; n < i; n++)
   {       // this loop displays 640 samples of discrete time signal
	Y = 200 - x[n]*100;  //scaling of x(n) for proper display
	putpixel(X,Y,WHITE); //x(n) is displayed as putting pixels
	X++;
   }
   getch();
   closegraph();
}
//----------------------------End of program------------------------------
