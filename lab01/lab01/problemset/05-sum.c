
// Să se calculeze (folosind formule matematice;
// nu instrucțiuni repetitive) și să se afișeze sumele
// S1 = 0 + 1 + 2 + ... + n
// S2 = 0 + 1^2 + 2^2 + ... + n^2

#include <stdio.h>

int main(void)
{
	// citesc numarul de la tastatura
	int n;
	printf("n:\n");
	scanf("%d", &n);

	// aplic formulele
	int S1 = n * (n + 1) / 2,
		S2 = n * (2 * n + 1) * (n + 1) / 6;
	// observati cum scriu codul: aerisit (cu taburi, spatii,
	// pe mai multe linii)

	// afisez rezultatele
	printf("S1 = %d\n", S1);
	printf("S2 = %d\n", S2);

	return 0;
}

// Tema:
// * Ce credeti ca se intampla cu programul acesta pentru n = 123456?

// Rulare:
// $ make
// $ ./05-sum
// n:
// 4
// S1 = 10
// S2 = 30
