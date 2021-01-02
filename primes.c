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
    int primes[100] = {1,2};
    int notPrime;
    double test;
    bool isPrime;

    for ( int primeElement=2; primeElement<primeUpperRange; primeElement++) { // build the array of primes
        printf("Filling prime array element %i.\n ", primeElement);
        // for each slot, start at the last prime found
        for ( int candidate=3; candidate<=primeUpperRange; candidate += 2) { // loop through candidates
            isPrime=true; // asume prime until proved otherwise
            printf("checking %i:\n", candidate);
            for ( int previousPrime=1; previousPrime<primeElement; previousPrime++) { // can the candidate be devided evenly by previous prime?
                test = candidate % primes[previousPrime];
                if ( test == 0 ) {
                    printf("%i can be divided by %i so it is not prime.\n", candidate, primes[previousPrime] );
                    isPrime=false;
                    break; // candidate is not prime
                } else {
                    printf("%i: %i could be prime.\n", previousPrime, candidate);
                }
            }
            if ( isPrime ) {
                primes[primeElement] = candidate;
                break;
            }
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