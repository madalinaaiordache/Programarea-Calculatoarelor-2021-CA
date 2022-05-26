
#include <stdio.h>
#include <stdlib.h> // pentru abs

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

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("count_digits(%d) = %d\n", n, count_digits(n));

	return 0;
}

// Tema:
// * In aceasta sursa vi se da un model de a scrie cod. Observati cum:
//      - am ales numele functiilor/variabilelor
//      - am pus comentariile. In acest exemplu sunt in engleza.
// * Am ales cele mai potrivite tipuri pentru toate variabilele din program?

// Rulare:
// $ make
// $ ./02-count_digits
// 123                         (explicatie: se citeste n)
// count_digits(123) = 3
// $ ./02-count_digits
// -123
// count_digits(-123) = 3
// $ ./02-count_digits
// 0
// count_digits(0) = 1
// $ ./02-count_digits
// 111111111
// count_digits(111111111) = 9
