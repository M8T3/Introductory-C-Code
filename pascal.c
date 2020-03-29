/* 
 * This program computes and prints the first eight rows of Pascal's Triangle
 */
 
#include <stdio.h>
#include "genlib.h"


/*This function computes the factorial of a number m*/
int fact(int m)
{
    int i;
    int num = 1;    
    for(i = m; i > 0; i--)
    {
        num *= i;
    }
    return num;  
}

/*This function computes the binomial coefficients given
 r (total number of items) and k (number of items you want)*/ 
int binomial(int r, int k)
{
    int bin; 
    bin = fact(r)/(fact(k)*fact(r-k));
    return bin;
}
 
void main()
{
    int i, j, k; //index variables
    int n = 8; //number of rows of Pascal's Triangle to compute 
    int pascal; //variable to hold each binomial coefficient
    int p;
    p = n-1; //variable that helps compute the offset for each row of Pascal's Triangle
    for(i = 0; i < n; i++)
    {
        for(k = 0; k < 2*p; k++)
        {
	printf("%c",' '); //prints number of offset spaces for each line of the triangle
        }

	for(j = 0; j < (i+1); j++)
	{
	   pascal = binomial(i,j);
	   printf("%4d", pascal); //prints out each term of a row in the triangle
	}

	printf("\n");
	p -= 1; //decrements the offset for the next row of the triangle
    }
}/*End of main()*/
