
// Se citesc de la tastatură două numere reale.
// Să se afișeze suma, diferenta și media lor cu precizie de
// 5 zecimale exacte.

#include <stdio.h>

int main(void)
{
	// citesc
	float a, b;

	printf("a:\n");
	scanf("%f", &a);

	printf("b:\n");
	scanf("%f", &b);

	// calculez
	float s = a + b;
	float d = a - b;
	float m = (a + b) / 2;

	// afisez rezultatele
	printf("s = %.5f\n", s);
	printf("d = %.5f\n", d);
	printf("m = %.5f\n", m);

	return 0;
}

// Tema:
// * Realizati aceeasi cerinta pentru a si b 2 numere intregi.

// Rulare:
// $ make
// $ ./04-diff_avg
// a:
// 2
// b:
// 3
// s = 5.00000
// d = -1.00000
// m = 2.50000
