
#pragma once

#include <stdio.h>
#include <stdlib.h>

// math functions
int power_brute(int n, int k);
int power(int n, int k);
int power_recursive(int n, int k);

// functions that proccess numbers (aka extract digits)
int count_digits(int n);
int count_digits_iterative(int n);
int reverse_number(int n);

// validators
int is_palindrome(int n);
int is_prime(int n);

// searching functions
int next_palindrome(int n);
int closest_palindrom(int n);
int closest_prime(int n);

// "func_t" it's a new type defined by the programmer:
// func_t it's a pointer to a function with a parameter of
// type int and which returns a value of type int
typedef int (*func_t)(int);

int closest_func(int n, func_t f);
