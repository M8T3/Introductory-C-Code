/* 
 * This program finds which numbers between 1 and 100 are either 
 * divisble by 6 or 7 and prints them to the monintor
 */
 
#include <stdio.h>
#include "genlib.h"

void main()
{
    int i; //index variable
    /*loop to find numbers between 1 and 100 that are divisble by 6 or 7*/
    for(i = 1; i <= 100; i++) //includes i = 100 iteration
    {
        if((i % 6 == 0) || (i % 7 == 0))
        {
	    printf("%4d\n",i);
	}			
    }
}/*End of main()*/
