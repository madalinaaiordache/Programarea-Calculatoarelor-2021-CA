
#include <stdio.h>

int main(void)
{
	int n;
	printf("n = ");
	scanf("%d", &n);

	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

// Tema:
// * Modificati programul dat astfel incat sa se afiseze scara cu treptele
// inverse.  Exemplu: n = 5
//               *
//               **
//               ***
//               ****
//               *****
// * Modificati programul dat astfel incat sa se afiseze scara cu treptele
// aliniate la stranga sau la dreapta alternativ.
//  n = 6
// *
//      **
// ***
//    ****
// ******
// *******

// Rulare:
// $ make
// $ ./04-stairs
// n = 5
// *****
// ****
// ***
// **
// *
