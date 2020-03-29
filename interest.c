/* 
 * This program reads in the starting balance of a bank account and the annual interest
 * rate and outputs the balance after a year with interest
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void main()
{
    double balance, interest_rate;
    
    printf("Interest calculation program.\n");
    printf("Starting balance? ");
    balance = GetReal();                                    //Wait for user to input an integer for the starting balance and press enter
    printf("Annual interest rate percentage? ");
    interest_rate = GetReal();                              //Wait for user to input an integer for the interest rate and press enter
    balance = balance * (1 + (interest_rate/100));
    printf("Balance after one year: %g\n", balance);

}/*End of main()*/
