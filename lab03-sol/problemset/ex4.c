
#include <stdio.h>

// Scrieţi un program care să convertească numere din baza 2 în baza 10 şi
// invers. Numerele se introduc de la tastatură până la intâlnirea unui
// număr negativ. Pentru fiecare număr introdus, se va afişa pe o
// linie rezultatul.

// int x = dec2bin(n);
// x va fi numarul in baza 2 echivalent el lui n
// Ex. n = 3 => x = 11 (3 = 000..0011)
int dec2bin(int n)
{
	int result = 0, power = 1;

	while (n) {
		int modulo = n % 2;
		n /= 2;

		result += modulo * power;
		power *= 10;
	}

	return result;
}

// int x = bin2dec(n);
// n reprezinta un numar in binar, iar x echivalentul in baza 10
// ex. n = 11; => x = 3
int bin2dec(int n)
{
	int result = 0, power = 1;

	while (n) {
		int modulo = n % 10;
		n /= 10;

		result += modulo * power;
		power *= 2;
	}

	return result;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	while (n >= 0) {
		printf("%d (2) = %d (10)\n", n, bin2dec(n));
		printf("%d (10) = %d (2)\n", bin2dec(n), dec2bin(bin2dec(n)));

		// trec la urmatorul numar
		scanf("%d", &n);
	}

	return 0;
}
