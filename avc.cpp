#include <stdio.h>
#include <time.h>
#include "E101.h"

int main (){
	
	init();
	
	/* Take picture, assign each pixel an error value. Looks only at
	 * the horizontal pixels in the center of the picture (row 120)
	 * as in the lectures.   */
	
	int error = 0;
	for (i = 0, i < 320, i++)
	{
		take_picture();
		
		pixel = get_pixel(120, i, 3)
		if (i < 160)
		{
			error = error - pixel;
		}
		else 
		{
			error = error + pixel;
		}
	}
	
}

/* Motor 1 and 2 speeds - different as we had found that motor 2 was
 * much slower than motor 1 */	

unsigned char vgo_m1 = 40; // motor 1 speed
unsigned char vgo_m2; = 255; //motor 2 speed
double kp = 0;
unsigned char dv = error * kp; // difference in speed

/* Test if robot will go forward (since kp = 0) */

set_motor(1, vgo_m1 + dv);
set_motor(2, vgo_m2 - dv);
sleep1(5,0);
set_motor(1, 0);
set_motor(2,0);
sleep1(10,0);

/* Test if robot will follow white line */

double kp = 0.005;
unsigned char dv = error * kp;

set_motor(1, vgo_m1 + dv);
set_motor(2, vgo_m2 - dv);
sleep1(,10,0);
set_motor(1,0);
set_motor(2,0);
set_motor(2, vgo_m2 - dv);
