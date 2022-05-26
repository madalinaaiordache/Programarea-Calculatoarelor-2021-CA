
// Se citeşte de la tastatură un număr întreg si pozitiv n.
// Să se scrie un program care determină care număr cuprins intre 2 si n are
// suma divizorilor nebanali maximă (adică printre divizori nu sunt
// considerate numerele 1 si n). Dacă există mai multe asemenea numere se va
//  afişa numai primul dintre ele.
// Exemplu
// n=100
// OUT: 96 //are suma divizorilor 155

#include <stdio.h>

int main(void)
{
	// citeste n
	int n;
	scanf("%d", &n);

	int sol = 0, sum_max = 0;
	int i, j;  // contori

	// parcurg numerele de la 2 la n cu i
	for (i = 2; i <= n; ++i) {
		int sum_curent = 0;

		// j este un posibil divizor al lui i
		for (j = 2; j < i; ++j)
			if (i % j == 0) {
				sum_curent += j;
			}

		if (sum_curent > sum_max) {
			sum_max = sum_curent;
			sol = i;
		}
	}

	if (sol != 0) {
		printf("%d\n", sol);
	} else {
		printf("Nu exista un astfel de numar\n");
	}

	return 0;
}
