
#include <stdio.h>

// varianta ineficienta - iterativ
int power_iterative(int n, int k)
{
	int p = 1;

	for (int i = 1; i <= k; ++i) {
		p *= n;
	}

	return p;
}

// varianta ineficienta - recursive
unsigned int power_recursive(unsigned int n, unsigned int k)
{
	if (!k) {
		return 1;
	}

	return n * power_recursive(n, k - 1);
}

// variante eficienta - iterativ
unsigned int power(unsigned int n, unsigned int k)
{
	if (!k) {
		return 1;
	}

	if (k % 2 == 0) {
		return power(n * n, k / 2);
	} else {
		return n * power(n, k - 1);
	}
}

// variante eficienta - recursive
// unsigned int power(unsigned int n, unsigned int k)
// {
//     if (!k) {
//         return 1;
//     }
//
//     unsigned int p = 1;
//     while (k != 1) {
//         if (k % 2 == 0) {
//             n = n * n;
//             k /= 2;
//         } else {
//             p = p * n;
//             --k;
//         }
//     }
//
//     return p * n;
// }

int main(void)
{
	unsigned int n, k;
	scanf("%u%u", &n, &k);

	printf("power_iterative(%u, %u) = %u\n", n, k, power_iterative(n, k));
	printf("power_recursive(%u, %u) = %u\n", n, k, power_recursive(n, k));
	printf("power(%u, %u) = %u\n", n, k, power(n, k));

	return 0;
}

// Tema:
// * Analizati tipul de date pentru n si k (power_iterative vs power_recursive).
// Care este tipul cel mai potrivit considerand ca n si k sunt naturale?
// * Comparati cele 2 implementari eficiente.

// Rulare:
// $ make
// $ ./01-power
// 2 11                                  (explicate: se citesc n k)
// power_iterative(2, 11) = 2048
// power_recursive(2, 11) = 2048
// power(2, 11) = 2048
