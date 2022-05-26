
#include <stdio.h>

int main(void)
{
	// numarul de numere prime intalnite
	int count_primes = 0;

	// n este primul numar citit
	int n;
	printf("n = ");
	scanf("%d", &n);

	while (n >= 0) {
		int is_prime = 1;

		for (int i = 2; i <= n / 2; ++i) {
			// verific daca i este divizor nebanal al lui n
			if (n % i == 0) {
				// i este divizor, deci n nu e prim
				is_prime = 0;

				printf("%d ", i);
			}
		}

		if (is_prime) {
			// afisez concluzia ca e prim
			printf("PRIM\n");
			++count_primes;
		} else {
			// termin linia pe care am printat sirul de divizori
			printf("\n");
		}

		// n devine urmatorul numar citit
		printf("n = ");
		scanf("%d", &n);
	}

	printf("count_primes = %d\n", count_primes);

	return 0;
}

// Tema:
// * Rescrieti programul dat folosind do ... while. Comparati.
// * Considerand ca nu doriti sa afisati divizorii ci doar daca numarul
// este prim sau nu (PRIM / COMPUS), modificati programul. Ce optimizare
// puteti face astfel incat sa execute cat mai putini pasi? (hint: break)

// Rulare:
// $ make
// $ ./05-divisors
// n = 35
// 5 7
// n = 36
// 2 3 4 6 9 12 18
// n = 17
// PRIM
// n = 2
// PRIM
// n = 12
// 2 3 4 6
// n = 25
// 5
// n = 53
// PRIM
// n = -4
// count_primes = 3
