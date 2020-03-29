/* 
 * This program computes and prints out the roots of 
 * the quadratic equation ax^2 + bx + c = 0 for 
 * user entered values of a, b, and c
 */
 
#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

void main() 
{
    int a, b, c; //coefficients of the quadratic equation
    double x1, x2;
    printf("Enter coefficients for the quadratic equation:\n");
    printf("a: ");
    a = GetReal();
    printf("b: ");
    b = GetReal();
    printf("c: ");
    c = GetReal();
    //calculates the quantity under the square root sign of quadratic formula
    x1 = (b*b) - (4*a*c); 
    if(x1 < 0) //x1 is imaginary
    {
	printf("The equation has no real solutions.\n");
    }
    else if(x1 == 0) 
    {
        x1 = -b/(2*a);
	printf("The only solution is %g\n", x1);	
    }
    else
    {
	x2 = x1;
	x1 = (-b + sqrt(x1))/(2*a); //first solution of quadratic equation
	x2 = (-b - sqrt(x2))/(2*a); //second solution of quadratic equation
	printf("The first solution is %g\n", x1);
	printf("The second solution is %g\n", x2);	
    }
}/*End of main()*/
