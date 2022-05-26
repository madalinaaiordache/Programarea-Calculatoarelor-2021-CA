
#include <stdio.h>

// int x = reverse(n);
// x este oglinditul lui n
// ex. n = 123 =>  x = 321
int reverse(int n)
{
	int r = 0;

	while (n) {
		// extrage ultima cifra
		int c = n % 10;
		n /= 10;

		// adauga la oglindit
		r = r * 10 + c;
	}

	return r;
}

// functia returneaz 1 daca n e palindrom
//                   0 altfel
int is_palindrom(int n)
{
	return n == reverse(n);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	if (is_palindrom(n)) {
		printf("%d este palindrom\n", n);
	} else {
		printf("%d NU este palindrom\n", n);
	}

	return 0;
}
