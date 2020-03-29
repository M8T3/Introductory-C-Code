/* 
 * This program prints out the squares of the numbers from 1 to 10
 */

#include <stdio.h>
#include "genlib.h"

void main()
{
    int i, min_num, max_num, limit, num, num_squared;                //Defining constants for the program
    
    min_num = 1;                                              //Defining mininum number to square
    max_num = 10;                                             //Defining maximum number to square
    limit = (max_num - min_num) + 1;                          //Defining the number of interations for the for loop 
    num = min_num;                                            //Start the first number to square as the mininum number for a given set of numbers to square

    for (i = 0; i < limit; i++) 
    {
        num_squared = num*num;
        printf("%d squared is %d\n", num, num_squared);
        num += 1; 
    }
}/*End of main()*/
