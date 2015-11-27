#include <math.h>
#include <stdio.h>
#include <time.h>

int is_prime(int* primes, int length, int register test) {
    int prime;
    int primality = 1;
    float register square_root = sqrt(test);
    for (int index = 0; index < length; index++) {
        prime = *(primes + index);
        if (prime > square_root) {
            break;
        }
        if (test % prime == 0) {
            primality = 0;
            break;
        }
    }
    return primality;
}

int main() {
    clock_t start = clock();
    int ceiling = 1000000;
    int primes[ceiling];
    primes[0] = 2;
    int test = 3;
    int found = 1;
    while (found <= ceiling) {
        if (is_prime((int*) primes, found, test)) {
            primes[found++] = test;
        }
        test += 2;
    }
    clock_t end = clock();
    printf("%ld\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("%i\n", primes[ceiling]);
}