
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NMAX 100

// checks if a string is a palindrom - simple char comparison
// return: 1 if s is a palindrome, 0 otherwise
// int is_palindrome_simple(const char *s)
// {
//	if (!s) {
//		return 0;
//	}
//
//	size_t len = strlen(s);
//	for (size_t i = 0; i < len / 2; ++i) {
//		if (s[i] != s[len - 1 - i]) {
//			return 0;
//		}
//	}
//
//	return 1;
// }

// checks if a string is a palindrom - case insensitive char comparison
// return: 1 if s is a palindrome, 0 otherwise
// int is_palindrome_case_insensitive(const char *s)
// {
//	if (!s) {
//		return 0;
//	}
//
//	size_t len = strlen(s);
//	for (size_t i = 0; i < len / 2; ++i) {
//		if (tolower(s[i]) != tolower(s[len - 1 - i])) {
//			return 0;
//		}
//	}
//
//	return 1;
// }

// checks if a string is a palindrom - case insensitive char comparison,
// skip whitespace
//
// return: 1 if s is a palindrome, 0 otherwise
int is_palindrome(const char *s)
{
	if (!s) {
		return 0;
	}

	size_t i = 0;
	size_t j = strlen(s) - 1;
	while (i < j) {
		// if s[i] is whitespace, increment i - find first non-whitespace char
		while (i < j && isblank(s[i])) {
			++i;
		}
		// if s[j] is whitespace, decrement j - find first non-whitespace char
		while (i < j && isblank(s[j])) {
			--j;
		}

		// no more data to be compared
		if (i >= j) {
			break;
		}

		if (tolower(s[i]) != tolower(s[j])) {
			// found a pair which is not a match
			return 0;
		}

		// advance to the next pair
		++i;
		--j;
	}

	// all characters were processed, s is a palindrome
	return 1;
}

int main(void)
{
	char s[NMAX];
	fgets(s, NMAX, stdin);
	s[strlen(s) - 1] = '\0'; // remove trailing '\n'

	if (is_palindrome(s)) {
		printf("PALINDROME\n");
	} else {
		printf("NOT PALINDROME\n");
	}

	return 0;
}

// Run:
//
// 1) is_palindrome_simple()
// $ ./01-palindrome
// gigel#legig
// PALINDROME
// $ ./01-palindrome
// gigel
// NOT PALINDROME
// $ ./01-palindrome
// 121
// PALINDROME
// $ ./01-palindrome
// 122232221
// PALINDROME
//
// 2) is_palindrome_case_insensitive()
// ./01-palindrome
// giGel#LEGIG
// PALINDROME
// ./01-palindrome
// aNA
// PALINDROME
// ./01-palindrome
// 123
// NOT PALINDROME
//
// 3)
// $ ./01-palindrome
// gigel
// NOT PALINDROME
// $ ./01-palindrome
// ele fac cafele
// PALINDROME
// $ ./01-palindrome
// e l e f		a c c		a f e	l	e
// PALINDROME
// $ ./01-palindrome
// gigel e legig
// PALINDROME
