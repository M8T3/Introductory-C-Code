/* 
 * This program creates a pointer to integer array with n elements, with each element equal to its index value
 */
 
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*Variables*/
int num_of_elems; //variable to hold number of elements user enters
int *ip; //pointer to dynamically allocated index array
int i; //index variable

/*Function that takes the input size of n and returns 
an array with n elements with each element equal to its index*/
int *IndexArray(int n)
{
	int *array;
	int k;
	array = (int *) malloc(n*sizeof(int)); //creates pointer to base address of n-sized integer array
	for(k = 0; k < n; k++)
	{
		array[k] = k; //assigns element equal to its index
	}
	return array;
}

void main()
{
	printf("Please enter the size of the array: ");
	num_of_elems = GetReal();
	ip = IndexArray(num_of_elems);	//calls function to create index array (Note: this is a pointer to the base address of the array)
	printf("The resulting array is:\n");
	for(i = 0; i < num_of_elems; i++)
	{
		if(i == (num_of_elems-1))
		{
			printf("%d\n", ip[i]);
		}
		else
		{
			printf("%d, ", ip[i]);
		}
	}
	
	free(ip); //Must make sure to free the memory that the array is stored in (else could run out of memory!)
}/*End of main()*/
