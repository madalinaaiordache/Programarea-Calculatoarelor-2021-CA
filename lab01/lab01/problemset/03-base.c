
// Se citește de la tastatură un număr natural în baza 10.
// Să se afișeze în bazele 8, 10 și 16.

#include <stdio.h>

int main(void)
{
	int number;

	printf("number(10):\n");
	scanf("%d", &number); // %d citeste in "decimal"

	// afisez in decimal
	printf("%d(10) = %d(10)\n", number, number);

	// afisez in octal
	printf("%d(10) = %o(8)\n", number, number);

	// afisez in octal hexa cu MAJUSCULE
	printf("%d(10) = %X(16)\n", number, number);

	// afisez in octal hexa cu minuscule
	printf("%d(10) = %x(16)\n", number, number);

	return 0;
}

// Rulare:
// $ make
// $ ./03-base
// number(10):
// 12
// 12(10) = 12(10)
// 12(10) = 14(8)
// 12(10) = C(16)
// 12(10) = c(16)
// $ ./03-base
// number(10):
// 15
// 15(10) = 15(10)
// 15(10) = 17(8)
// 15(10) = F(16)
// 15(10) = f(16
