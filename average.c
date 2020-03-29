/*
 * This program averages a list of integers. The end of the input
 * is indicated by entering -1, then outputs the final average value.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void main()
{
    int value, total, num_of_integers;                            //Defining constants for the program
    double average;

    printf("This program averages a list of integers.\n");
    printf("Enter -1 to signal the end of the list.\n");
    total = 0;                                                    //Variable to sum inputs of the list
    num_of_integers = 0;                                          //Variable to keep track of number of inputs
    
    while (1)                                                     //Loop to prompt user to enter a number and exits when user enters -1
    {
        printf(" ? ");
        value = GetInteger();
      
        if (value == -1)                                          //Exit condition to break the while(1) loop 
        {
            if (num_of_integers == 0)
            {
                num_of_integers += 1;
            }   
            break;
        }
        total += value;                                          //total = total + value
        num_of_integers += 1;                                    //num_of_integers = num_of_integers + 1
    }
    
    average = (float) total/num_of_integers;                     //Compute average (most likey a floating point number)
    printf("The average is %g\n", average);
}/*End of main()*/
