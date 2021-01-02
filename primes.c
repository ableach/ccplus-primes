/*
Author: ableach
Date: 01/01/21
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int primeUpperRange;
    if ( argc == 2 ) {
        primeUpperRange = atoi(argv[1]);
        if (primeUpperRange>100) {
            primeUpperRange = 100;
        }
    } else {
        primeUpperRange = 30;   
    }

    int primes[100] = {0};
    primes[0] = 2;
    int primeElement = 1;
    double test;
    bool isPrime;
    
    for ( int candidate=3; candidate<=primeUpperRange; candidate += 2) { // loop through candidates
        printf("Filling prime array element %i.\n ", primeElement);
        isPrime=true; // asume prime until proved otherwise
        printf("checking %i:\n", candidate);
        for ( int previousPrime=1; isPrime && previousPrime<primeElement; previousPrime++) { // can the candidate be devided evenly by previous prime?
            test = candidate % primes[previousPrime];
            if ( test == 0 ) {
                //printf("%i can be divided by %i so it is not prime.\n", candidate, primes[previousPrime] );
                isPrime=false;
            }
        }
        if ( isPrime ) {
            primes[primeElement++] = candidate;
        }
    }
    
    printf("\n\nResults:\n");
    printf("--------\n");
    for ( int i=0; i<primeUpperRange; i++) {
        if ( primes[i] == 0) 
            break;
        printf("%i = %i\n", i, primes[i]);
    }
    return 0;
}