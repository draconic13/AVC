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
		
		/* Take picture, assign each pixel an error value. Looks only at
		 * the horizontal pixels in the center of the picture (row 120)
		 * as in the lectures.   */
		take_picture();
		display_picture(1,0);
		
		
		 int max = 0;
         int min =255;
         int scan_row =120;
   	     for (int i = 0; i <320;i++)
	     {
		   int pix = get_pixel(scan_row,i,3);
           if ( pix > max) 
           {
			  max = pix;
	  	   }
		   if (pix < min)
		   {
			  min =pix;
		   }
        }
       int thr = (max+min)/2;
       printf(" min=%d max=%d threshold=%d\n", min, max,thr);
    
      int whi[320];  // white pixels
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
    
     for (int i = 0; i <320;i++)
	 {
 		printf("%d ",whi[i]);
     }
    printf("\n");
    sleep1(1,0);
	
	
		
		
		
		int error = 0;
		
		for (int i = 0; i < 320; i++)
		{
		   error = error +(i-160)*whi[i];	
		}
		printf("error=%d\n",error);
		sleep1(1,0);

	
	/* Motor 1 and 2 speeds - different as we had found that motor 2 was
	 * much slower than motor 1 */	
	
	unsigned char vgo_m1 = 40; // motor 1 speed
	unsigned char vgo_m2 = 255; //motor 2 speed
	double kp = 0.005;
	unsigned char dv = error * kp; // difference in speed
	
	//set_motor(1, vgo_m1 + dv);
	//set_motor(2, vgo_m2 - dv);
	//sleep1(10,0);
	//set_motor(1,0);
	//set_motor(2,0);

	}
	
  }	

}	
	
	


