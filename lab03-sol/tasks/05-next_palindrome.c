#include <stdio.h>
#include <stdlib.h>

// power_recursive: compute n raise to k
// n       - the base
// k       - the exponente
// @return - n raise to k
int power(int n, int k)
{
	// base case: n raise to 0 is 1
	if (!k) {
		return 1;
	}

	// apply recursion
	if (k % 2 == 0) {
		return power(n * n, k / 2);
	} else {
		return n * power(n, k - 1);
	}
}

// number_of_digits: compute the number of digits for an integer
// n        - input number
// @return  - the number of digits
int number_of_digits(int n)
{
	// if negative, apply absolute value
	if (n < 0) {
		return number_of_digits(abs(n));
	}

	// base case: 1 digit
	if (n < 10) {
		return 1;
	}

	return 1 + number_of_digits(n / 10);
}

// reverse_number: compute a new number by reversing the digits
// n        - input number
// @return  - the reverse number
int reverse_number(int n)
{
	// if negative, apply absolute value
	if (n < 0) {
		return -reverse_number(-n);
	}

	// base case: 1 digit
	if (n < 10) {
		return n;
	}

	return (n % 10) * power(10, number_of_digits(n) - 1) +
			reverse_number(n / 10);
}

// is_palindrome: check if a number is a palindrome
// n        - input number
// @return  - 1 if n is a palindrome
//            0 otherwise
int is_palindrome(int n)
{
	return n == reverse_number(n);
}

// next_palindrome: find the smallest number palindrome greater than n
// n       - input number
// @return - the target number
int next_palindrome(int n)
{
	while (1) {
		if (is_palindrome(n)) {
			return n;
		}

		n++;
	}

	return -1;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("next_palindrome(%d) = %d\n", n, next_palindrome(n));

	return 0;
}

// Tema:
// * In aceasta sursa vi se da un model de a scrie cod. Observati cum:
//      - am ales numele functiilor/variabilelor
//      - am pus comentariile in engleza
//      - am pus comentariile inaintea functiilor pentru a explica ce face
// fiecare, ce semnifica fiecare parametru, ce returneaza functia
// * Observati ca am copiat functiile de la exercitiile anterioare.
// Pentru a evita acest lucru, vom invata sa folosim fisiere header.

// Rulare:
// $ make
// $ ./05-next_palindrome
// 10                            (explicatie se citeste n)
// next_palindrome(10) = 11
// $ ./05-next_palindrome
// 12
// next_palindrome(12) = 22
// $ ./05-next_palindrome
// 98
// next_palindrome(98) = 99
// $ ./05-next_palindrome
// 589
// next_palindrome(589) = 595
