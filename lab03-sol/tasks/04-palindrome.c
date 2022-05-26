
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

// count_digits: compute the number of digits for an integer
// n        - input number
// @return  - the number of digits
int count_digits(int n)
{
	// if negative, apply absolute value
	if (n < 0) {
		return count_digits(abs(n));
	}

	// base case: 1 digit
	if (n < 10) {
		return 1;
	}

	return 1 + count_digits(n / 10);
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

	return (n % 10) * power(10, count_digits(n) - 1) + reverse_number(n / 10);
}

// is_palindrome: check if a number is a palindrome
// n        - input number
// @return  - 1 if n is a palindrome
//            0 otherwise
int is_palindrome(int n)
{
	return n == reverse_number(n);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("is_palindrome(%d) = %d\n", n, is_palindrome(n));

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
// $ ./04-palindrome
// 123                         (explicatie se citeste n)
// is_palindrome(123) = 0
// $ ./04-palindrome
// 101010
// is_palindrome(101010) = 0
// $ ./04-palindrome
// 101
// is_palindrome(101) = 1
// $ ./04-palindrome
// 1239321
// is_palindrome(1239321) = 1
// $ ./04-palindrome
// -121
// is_palindrome(-121) = 1
