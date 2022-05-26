
#include "tester.h"

void test_power(void)
{
	assert(power(2, 10) == 1024);
	assert(power(3, 2) == 9);
	assert(power(123213213, 0) == 1);

	assert(power_brute(2, 10) == 1024);
	assert(power_brute(3, 2) == 9);
	assert(power_brute(123213213, 0) == 1);

	assert(power_recursive(2, 10) == 1024);
	assert(power_recursive(3, 2) == 9);
	assert(power_recursive(123213213, 0) == 1);

	printf("power is good!\n");
}

void test_count_digits(void)
{
	assert(count_digits(0) == 1);
	assert(count_digits(1) == 1);
	assert(count_digits(-1) == 1);
	assert(count_digits(-123) == 3);
	assert(count_digits(123) == 3);

	assert(count_digits_iterative(0) == 1);
	assert(count_digits_iterative(1) == 1);
	assert(count_digits_iterative(-1) == 1);
	assert(count_digits_iterative(-123) == 3);
	assert(count_digits_iterative(123) == 3);

	printf("count_digits is good!\n");
}

void test_reverse_number(void)
{
	assert(reverse_number(123) == 321);
	assert(reverse_number(-123) == -321);
	assert(reverse_number(9) == 9);
	assert(reverse_number(0) == 0);

	printf("reverse_number is good!\n");
}

void test_is_palindrome(void)
{
	assert(is_palindrome(0));
	assert(is_palindrome(11));
	assert(is_palindrome(-11));
	assert(is_palindrome(121));
	assert(is_palindrome(1221));
	assert(is_palindrome(1257521));
	assert(!is_palindrome(123));
	assert(!is_palindrome(12));
	assert(!is_palindrome(1234));
	assert(!is_palindrome(12578521));

	printf("is_palindrome is good!\n");
}

void test_is_prime(void)
{
	assert(is_prime(0) == 0);
	assert(is_prime(1) == 0);
	assert(is_prime(2) == 1);
	assert(is_prime(3) == 1);
	assert(is_prime(4) == 0);
	assert(is_prime(5) == 1);

	printf("is_prime is good!\n");
}

void test_pointer_to_function(void)
{
	int n = 100;
	printf("closest_palindom(%d) = %d\n", n, closest_func(n, &is_palindrome));
	printf("closest_prime(%d) = %d\n", n, closest_func(n, &is_prime));
}

void test_all(void)
{
	test_power();
	test_count_digits();
	test_reverse_number();
	test_is_palindrome();
	test_is_prime();
	test_pointer_to_function();
}
