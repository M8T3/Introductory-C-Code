/* 
 * This program sorts an integer array using the insertion sort algorithm 
 */
 
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

/*Constants*/
#define true 1 //to make while() loop easier to read
#define init_arr_size 16 //initial size of dynamically allocated array (could have been smaller)

/*Function that prints user entered array*/
void PrintArray(int n, int *arr)
{
	int i; 
	for(i = 0; i < n; i++)
	{
		if(i == (n - 1))
		{
			printf(" %d\n", arr[i]);;
		}			
		else
		{
				printf(" %d,", arr[i]);
		}	
	}	
}

/*Function that sorts user entered array*/
void InsertionSort(int n, int *arr)
{
	int i;
	int k;
	int elem_to_sort;
	for(i = 1; i < n; i++)
	{
		k = i;
		elem_to_sort = arr[i];
		while(elem_to_sort < arr[k-1])
		{
			arr[k] = arr[k-1];
			k--; 
			if(k == 0) break;
		}
		arr[k] = elem_to_sort;
	}
}

void main()
{
	/*Variables*/
	int *array; //pointer to base address of array that holds the numbers the user enters
	int j = 0; //index variable
	string input; //holds input from user
	array = (int *) malloc(init_arr_size*sizeof(int)); //initial size of array that holds user entered numbers
	
	printf("Enter a list of integers\n");
	while(true)
	{
		printf("> ");
		input = GetLine(); //receives a string that contains the integer the user entered
		if (StringCompare(input, "\0") == 0) break; //if the user enters a blank line (i.e. presses "Enter" without typing anything), stop accepting numbers
		if (j >= init_arr_size) //this determines if more space needs to be allocated in memory for the array
		{
			array = (int *) realloc(array, (j+1)*sizeof(int)); //reassigns pointer to original array to an array with room for one more space
		}
		array[j] = StringToInteger(input); //converts string to integer so we can sort numbers instead of characters
		j++;
	}

	int end_of_list = j; //reassigning index variable j to make it easier to read
	
	printf("The input array is:");
	PrintArray(end_of_list, array); //print unsorted array

	InsertionSort(end_of_list, array);

	printf("The sorted array is:");
	PrintArray(end_of_list, array); //print sorted array
	
	free(array); //free the memory that holds array (so we don't run out of memory!)
} /*End of main()*/
