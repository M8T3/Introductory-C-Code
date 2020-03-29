/* 
 * This program computes the approximate value of pi using
 * 10,000 terms of series approximating pi/4
 */
 
#include <stdio.h>
#include "genlib.h"
 
void main()
{
    int i; //index variable
    double pi;
    double qtr_pi = 0; //variable to hold the sum of each term of pi/4 series
    double n = 1.0; //divisor for each term of the pi/4 series
    for(i = 1; i <= 10000; i++)
    {
        /*for the 1st term of the pi/4 series*/
	if(i == 1) 
	{
	    qtr_pi = 1;
	}
	/*for even numbered entries of the series (i.e. 2nd term, etc)*/
	else if(i%2 == 0) 
        {
	    qtr_pi -= 1/n;
        }
	/*for odd numbered entries of the series other than 1st term
	(i.e. 3rd term, etc)*/
	else 
	{
	    qtr_pi += 1/n;
	}
        n += 2.0;
    }
    pi = 4*qtr_pi; //approximate value of(pi/4)*4 = approximately pi 
    printf("The approximated value of pi is %12.10lf\n", pi);
 }/*End of main()*/
