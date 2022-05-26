
//     Să se determine minimul și maximul a două numere folosind funcția
// matematiă fabs.
//     Afișați rezultatul cu două zecimale.
//     Atenție! Trebuie să includeți antetul math.h și să compilați
// cu opțiunea -lm

//     (http://www.cplusplus.com/reference/cmath/fabs/?kw=fabs)

//     fabs = float absolute (merge pe float, double, int)

//     exista si abs
//     abs = integer absolute (merge doar pe int)

#include <stdio.h>
#include <math.h> // pentru a folosi functia "fabs"

int main(void)
{
	// citesc
	float a, b;

	printf("a:\n");
	scanf("%f", &a);

	printf("b:\n");
	scanf("%f", &b);

	// calculez
	float min, max;
	min = 0.5 * (a + b - fabs(a - b));
	max = 0.5 * (a + b + fabs(a - b));

	// afisez rezultatele
	printf("min = %.2f\n", min);
	printf("max = %.2f\n", max);

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
