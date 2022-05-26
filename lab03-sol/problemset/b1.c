
//     De la tastatură se introduc n(fiind dat şi el de la tastatură) numere
// citite pe rând.
//     Găsiţi cel mai mare divizor comun al acestor n numere,
// fără a folosi vectori.

#include <stdio.h>

// toate solutiile de mai jos au complexitate log(max(a, b))

int gcd_modulo_iterative(int a, int b)
{
	while (b) {
		int modulo = a % b;
		a = b;
		b = modulo;
	}

	return a;
}

int gcd_modulo_recursive(int a, int b)
{
	if (!b) {
		return a;
	}

	return gcd_modulo_recursive(b, a % b);
}

int gcd_substraction(int a, int b)
{
	while (a != b) {
		if (a > b) {
			a -= b;
		} else {
			b -= a;
		}
	}

	return a;
}

int main(void)
{
	int n, x, gcd_vector, i;

	printf("Introduceti n:\n");
	scanf("%d", &n);

	printf("Introduceti cele %d numere, unul cate unul\n", n);

	scanf("%d", &x);
	gcd_vector = x;
	for (i = 2; i <= n; ++i) {
		scanf("%d", &x);

		// gcd_vector = gcd_substraction(gcd_vector, x);
		// gcd_vector = gcd_modulo_iterative(gcd_vector, x);
		gcd_vector = gcd_modulo_recursive(gcd_vector, x);
	}

	printf("GCD = %d\n", gcd_vector);

	return 0;
}
