/* 
 * This program computes and prints a floating point number raised to a exponent
 */
 
#include <stdio.h>
#include "genlib.h"

/*This function computes the result of raising a base to and exponent (i.e. power)*/
double RaiseRealToPower(double x, int r)
{
    int i;
    double num;
    double denominator;
    num = 1;
    denominator = 1;
    if(r < 0)
    {
        r = -r; //gets rid of negative to multiply positive numbers
	for(i = 1; i <= r; i++)
	{
	    denominator = denominator*x; //x is from the argument of the function
	}
	    num = 1/denominator;
    }
    else
    {
        for(i = 1; i <= r; i++)
	{
	    num = num*x;
	}
    }

    return num;
}

void main()
{
    double base = 10; //base that will be raised to a power
    int power = -4; //the first power that the base will raised to
    int end; //variable that will end the loop to print the base raised to a power
    end = -power + 1;
    double num_raised;
    printf("%11c%c\n", ' ','k');
    printf(" %c%7c%d\n", 'k', ' ', (int)base);
    int i;
    for(i = 0; i < 14; i++)
    {
        printf("%c",'-');
    }
    printf("\n");
    while(power < end)
    {
        num_raised = RaiseRealToPower(base, power);
	if(power < 0)
        {
            printf("%2d%6c%.*f\n", power, ' ', -power, num_raised); //printing base raised to power for -4 <= power < 0
	}
	else 
	{
	    printf("%2d  %7.1f\n", power, num_raised); //printing base raised to power for 0 <= power <= 4
	}
	power++;
    }
}/*End of main()*/
