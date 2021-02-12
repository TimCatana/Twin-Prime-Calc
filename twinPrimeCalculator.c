#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

/*
 *   Program name: twinPrimeCalculator.c
 *   Author: Tim Catana
 *   Last Update: November 27, 2019
 *   Function: Calculates the number of twin primes between 1 and range. Prints out # of twin primes, Largest twin prime less than
 *  	       range, and the time the calculation took
 *   Notes: none
 *   Compilation: gcc -ansi -o twinprimes twinPrimeCalculator.c     OR      using the makefile 'make twinprimes'
 *   Execution: ./twinprimes 5928
 */

bool isPrime(int x) {
	int i;

	for(i = 2; i <= x/2; i++) {
		if(x != 5){
			if(x % i == 0) {
				return false;
			}
		}
	}

	/* code below assumes function has not returned anything, thus meaning that the current int is a prime */
	for(i = 2; i <= (x+2)/2; i++) {
		if( (x+2) % i == 0) {
			return false;
		}
	}

	/* return code below assumes x and x+2 are both prime */
	return true;
}


int main(int argc, char *argv[]) {
	bool primeOrNot = false;
	int num = 0;
	int largestTwin = 0, numTwins = 0;
	int range = 0;

	clock_t start, end;
	double timeElapsed = 0;

	if(argc != 2){
		printf(" please only input a single integer after the, you can input a float if you want, that doesn't mean it will work the way you want it :3 \n");
		return( 0 );
	}

	range = atoi(argv[1]);
	start = clock();

	/* 0 is not a prime number, so there is no point is checcking it */
	for(num = 1; num < range; num++){
		primeOrNot = isPrime(num);

		if(primeOrNot == true){
			numTwins += 2;
			
			if(num + 2 > range){
				largestTwin = num;
			} else {
				largestTwin = num += 2;
			}
		}
	}

	end = clock();

	timeElapsed = ((double) end - start) / CLOCKS_PER_SEC;

	system("clear");

	printf("There are %d twin-primes less than %d. \n", numTwins, range );
	printf("The largest twin prime less than %d is: %d\n", range, largestTwin );
	printf("The calculation took around %f seconds\n", timeElapsed);

	return( 0 );
}
