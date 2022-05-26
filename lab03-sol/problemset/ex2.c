
// De la tastatură se introduc mai multe numere întregi si pozitive,
// terminate printr-un număr negativ. După fiecare număr introdus,
// se va afişa lista divizorilor lui nebanali sau textul PRIM.
// La sfârşit se va afişa numărul de numere prime găsite.
// Exemplu
// 35
// OUT: 5 7
// 36
// OUT: 2 3 4 6 9 12 18
// 17
// OUT: PRIM
// 2
// OUT: PRIM
// 12
// OUT: 2 3 4 6
// 25
// OUT: 5
// 53
// OUT: PRIM
// -4
// OUT: S-au găsit 3 numere prime.

#include <stdio.h>

int main(void)
{
	// citesc numere
	int n, prime_count = 0;
	scanf("%d", &n);

	// cat timp nu am intalnit un numar negativ (sau zero)
	while (n > 0) {
		// presupun ca e prim
		int prim = 1;

		// verific daca are un divizor nebanal
		for (int i = 2; i < n; ++i) {
			if (n % i == 0) {       // i de divizor al lui n
				prim = 0;           // deci nu e prim
				printf("%d ", i);  // voi afisa divizori
			}
		}

		if (!prim) {
			printf("\n");
		} else {
			printf("PRIM\n");
			++prime_count;
		}

		printf("n = ");
		scanf("%d", &n);
	}

	printf("S-au găsit %d numere prime.\n", prime_count);

	return 0;
}
