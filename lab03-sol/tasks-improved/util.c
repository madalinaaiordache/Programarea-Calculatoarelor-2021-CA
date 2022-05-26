
#include "util.h"

// power: compute n raise to k
// n       - the base
// k       - the exponente
// @return - n raise to k
int power(int n, int k)
{
	// base case: n raise to 0 is 1
	if (!k) {
		return 1;
	}

	int temp = 1;
	while (k != 1) {
		if (k % 2 == 0) {
			n = n * n;
			k /= 2;
		} else {
			temp *= n;
			k--;
		}
	}

	return n * temp;
}

// power_brute: compute n raise to k
// n       - the base
// k       - the exponente
// @return - n raise to k
int power_brute(int n, int k)
{
	int result = 1;

	for (int i = 1; i <= k; ++i) {
		result *= n;
	}

	return result;
}

// power_recursive: compute n raise to k
// n       - the base
// k       - the exponente
// @return - n raise to k
int power_recursive(int n, int k)
{
	// base case: n raise to 0 is 1
	if (!k) {
		return 1;
	}

	// apply recursion
	if (k % 2 == 0) {
		return power_recursive(n * n, k / 2);
	} else {
		return n * power_recursive(n, k - 1);
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

// count_digits_iterative: compute the number of digits for an integer
// n        - input number
// @return  - the number of digits
int count_digits_iterative(int n)
{
	// if negative, apply absolute value
	if (n < 0) {
		return count_digits_iterative(abs(n));
	}

	// base case: 1 digit
	if (n < 10) {
		return 1;
	}

	int digits = 0;
	while (n) {
		++digits;
		n /= 10;
	}

	return digits;
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

// next_palindrome: find the smallest palindrome number greater than n
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

// closest_palindrome: find the closest palindrome number from n
// n        - input number
// @return  - the target number
int closest_palindrome(int n)
{
	int lower = n - 1; // used to search to left
	int upper = n + 1; // used to search to right

	while (1) {
		if (lower >= 0 && is_palindrome(lower)) {
			return lower;
		}

		if (is_palindrome(upper)) {
			return upper;
		}

		// get to next iteration
		--lower;
		++upper;
	}

	// return a dummy value to avoid the warning
	return -1;
}

// is_prime: check if a number is a prime number
// n        - input number
// @return  - 1 if n is prie
//            0 otherwise
int is_prime(int n)
{
	if (n < 2) {
		return 0;
	}

	if (n == 2) {
		return 1;
	}

	if (n % 2 == 0) {
		return 0;
	}

	for (int i = 3; 1LL * i * i <= n; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

// closest_palindrome: find the closest prime number from n
// n        - input number
// @return  - the target number
int closest_prime(int n)
{
	// check if n is a solution
	if (is_prime(n)) {
		return n;
	}

	int lower = n - 1; // used to search to left
	int upper = n + 1; // used to search to right

	while (1) {
		if (lower >= 0 && is_prime(lower)) {
			return lower;
		}

		if (is_prime(upper)) {
			return upper;
		}

		// get to next iteration
		--lower;
		++upper;
	}

	// return a dummy value to avoid the warning
	return -1;
}

// closest_func: find the closest number from n which has f(n) == 1
// n        - input number
// f        - the function used to check something about n
//            (f is a pointer to a function which receives an int and returns
//             an int)
// @return  - the target number
int closest_func(int n, func_t f)
{
	// check if n is a solution
	if (f(n)) {
		return n;
	}

	int lower = n - 1; // used to search to left
	int upper = n + 1; // used to search to right

	while (1) {
		if (lower >= 0 && f(lower)) {
			return lower;
		}

		if (f(upper)) {
			return upper;
		}

		// get to next iteration
		--lower;
		++upper;
	}

	return -1;
}
