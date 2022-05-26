#include <stdio.h>

// is_prime: check if a number is a prime number
// n        - input number
// @return  - 1 if n is prie
//            0 otherwise
int is_prime(int n)
{
	// all numbers less than 2 are non-primes
	if (n < 2) {
		return 0;
	}

	// 2 is prime
	if (n == 2) {
		return 1;
	}

	// any other odd number is non-prime
	if (n % 2 == 0) {
		return 0;
	}

	// n is now even
	// we search for a divisor: 3, 5, 7, ..., sqrt(n)
	for (int i = 3; 1LL * i * i <= n; i += 2) {
		if (n % i == 0) {
			// we found i as a divisor for n
			return 0; // n it's not prime
		}
	}

	// n it's prime
	return 1;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("is_prime(%d) = %d\n", n, is_prime(n));

	return 0;
}

// Tema:
// * In aceasta sursa vi se da un model de a scrie cod. Observati cum:
//      - am ales numele functiilor/variabilelor
//      - am pus comentariile in engleza
//      - am pus comentariile inaintea functiilor pentru a explica ce face
// fiecare, ce semnifica fiecare parametru, ce returneaza functia

// Rulare:
// $ make
// $ ./06-is_prime
// 0                    (explicatie: se citeste n)
// is_prime(0) = 0
// $ ./06-is_prime
// 1
// is_prime(1) = 0
// $ ./06-is_prime
// 2
// is_prime(2) = 1
// $ ./06-is_prime
// 3
// is_prime(3) = 1
// $ ./06-is_prime
// 33
// is_prime(33) = 0
// $ ./06-is_prime
// 19
// is_prime(19) = 1
// $ ./06-is_prime
// 101
// is_prime(101) = 1
// $ ./06-is_prime
// 123
// is_prime(123) = 0
// $ ./06-is_prime
// 123456789
// is_prime(123456789) = 0
