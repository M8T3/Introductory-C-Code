/* 
 * This program computes and prints out a user specified term
 * of the Fibonacci series.
 */
 
 #include <stdio.h>
 #include "simpio.h"
 
 int Fib(int n)
 {
	if(n == 0) return 0;
	else if (n == 1) return 1;
    else return Fib(n-2) + Fib(n-1);	
 }
 
 void main()
 {
	int num;
	int fib_num;
	printf("This program computes the n-th Fibonacci number\n");
	printf("using the recursive formula.\n");
	printf("Please enter n: ");
	num = GetReal();
	fib_num = Fib(num);
	printf("Fib(%d) = %d\n", num, fib_num);
 }
