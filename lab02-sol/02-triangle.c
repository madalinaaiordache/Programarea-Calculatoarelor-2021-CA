
#include <stdio.h>

int main(void)
{
	// a, b, c = laturile unui triunghi
	unsigned int a, b, c;

	// citire
	printf("a = ");
	scanf("%u", &a);

	printf("b = ");
	scanf("%u", &b);

	printf("c = ");
	scanf("%u", &c);

	// verificare
	// 1. a,b,c pozitive (sunt deja)
	// 2. suma a doua laturi sa fie mai mare ca a 3-a latura
	if (a + b > c && a + c > b && b + c > a) {
		printf("DA\n");
	} else {
		printf("NU\n");
	}

	return 0;
}

// Tema:
// * De ce a, b, c sunt de tipul "unsigned int" in loc de "int"?
// * De ce am folosit %u?
// * Rescrieti citirea astfel incat sa folositi un singur apel de scanf.

// Rulare:
// $ make
// $ ./02-triangle
// a = 3
// b = 4
// c = 5
// DA
// $ ./02-triangle
// a = 1
// b = 2
// c = 3
// NU
// $ ./02-triangle
// a = -3
// b = 4
// c = 5
// NU
