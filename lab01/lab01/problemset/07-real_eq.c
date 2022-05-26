
// Se citesc de la tastatură două numere reale.
// Să se afișeze EQ dacă cele două numere sunt egale cu precizie
// de 10^-4.
// în caz contrar se va afișa mesajul NOT EQ.

#include <stdio.h>
#include <math.h> // pentru a folosi functia "fabs"

int main(void)
{
	// declar o constanta folosita la comparare (e mai dragut asa)
	const float eps = 0.0001; // definesc o CONSTANTA epsilon egala cu 10^-4
	// x == y cu precizie eps <=> |x - y| < eps
	// citesc
	float a, b;

	printf("a:\n");
	scanf("%f", &a);

	printf("b:\n");
	scanf("%f", &b);

	// calculez
	float difference = fabs(a - b); // diferenta in modul a celor doua numere

	// compar folosind if-urile pe care inca nu le-am invatat :))
	if (difference < eps) {
		printf("EQ\n");
	} else {
		printf("NOT EQ\n");
	}

	return 0;
}

// Rulare:
// $ make
// $ ./06-minmax
// a:
// 2
// b:
// 5
// min = 2.00
// max = 5.00
// $ ./07-real_eq
// a:
// 1
// b:
// 2
// NOT EQ
// $ ./07-real_eq
// a:
// 1
// b:
// 1
// EQ
// $ ./07-real_eq
// a:
// 1.001
// b:
// 1.002
// NOT EQ
// $ ./07-real_eq
// a:
// 1.0001
// b:
// 1.0009
// NOT EQ
// $ ./07-real_eq
// a:
// 1.00001
// b:
// 1.00009
// EQ
