/* 
 * This program reads in a length given in feet and inches and converts it
 * to its metric equivalent in centimeters
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void main()
{
    double feet, inches, feet_to_inches, total_inches, cm;                         //Defining constants for the program

    printf("This program converts from feet and inches to centimeters.\n");
    printf("Number of feet? ");
    feet = GetReal();                                                             //Wait for user to input an integer for the number of feet and press enter
    printf("Number of inches? ");
    inches = GetReal();                                                           //Wait for user to input an integer for the number of inches and press enter
    feet_to_inches = feet * 12;
    total_inches = feet_to_inches + inches;
    cm = total_inches * 2.54;
    printf("The corresponding length is %g cm.\n", cm); 
}/*End of main()*/
