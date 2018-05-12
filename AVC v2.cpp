#include <stdio.h>
#include <time.h>
#include "E101.h"

int main (){
	
	init();
	
	int quad = 0;
	
	while(1)
	{
	
		if (quad == 0)
		{
				
		/* Take picture, find the maximum and minimum value of white pixels, find the threshold
		 * for determining whether to assign a pixel binary value of 0 - black or 1 - white   */
		
		take_picture();
		display_picture(1,0); // this is just to display picture on screen for testing
				
		 int max = 0;
         int min = 255;
         int scan_row = 120;
   	     for (int i = 0; i <320;i++)
	     {
		   int pix = get_pixel(scan_row,i,3);
           if ( pix > max) 
           {
			  max = pix;
	  	   }
		   if (pix < min)
		   {
			  min = pix;
		   }
        }
       int thr = (max+min)/2;
       printf(" min=%d max=%d threshold=%d\n", min, max,thr);
    
      
      /* Removing noise - assigns binary values to each pixel, 
       * 0 - black, 1 - white */
      
      int whi[320];  // white pixels (array)
      int nwp = 0;
      for (int i = 0; i <320;i++)
	  {
		whi[i]= 0 ;
		int pix = get_pixel(scan_row,i,3);
		if ( pix > thr)
		{
			whi[i] = 1;
			nwp++;
		}
      }
    
	/* Prints binary values of each pixel to screen (just for testing) */
     
     for (int i = 0; i <320;i++)
	 {
 		printf("%d ",whi[i]);
     }
    printf("\n");
    sleep1(1,0);
			
	
	/* Computes the error value */	
		
	int error = 0;
		
	for (int i = 0; i < 320; i++)
	{
	   error = error +(i-160)*whi[i];	
	}
	printf("error=%d\n",error); //prints error for testing/debug
	sleep1(1,0);

	
	/* Motor 1 and 2 - (note: default speeds different as we had found that 
	 * motor 2 was much slower than motor 1) */	
	
	unsigned char vgo_m1 = 20; // motor 1 speed
	unsigned char vgo_m2 = 128; // motor 2 speed
	double kp = 0.005; // proportionality - how much motor reacts to error
	unsigned char dv = error * kp; // proportional signal
	
	set_motor(1, vgo_m1 + (dv/(160*1*kp)) * 255);
	set_motor(2, vgo_m2 - (dv/(160*1*kp)) * 255);
	sleep1(10,0);
	set_motor(1,0);
	set_motor(2,0);

	}
	
  }	

}	
	
	


