
#include <stdio.h>

int main(void)
{
	int n;
	printf("n = ");
	scanf("%d", &n);

	printf("verificare cu %%: ");
	if (n % 2 == 0) {
		printf("numarul %d este PAR\n", n);
	} else {
		printf("numarul %d este IMPAR\n", n);
	}

	printf("verificare cu &: ");
	if ((n & 1) == 0) {
		printf("numarul %d este PAR\n", n);
	} else {
		printf("numarul %d este IMPAR\n", n);
	}

	return 0;
}

// Tema:
// * Scrieti in baza 2 numarul n folosit si intelegeti logica.

// Rulare:
// $ make
// make: Nothing to be done for 'all'.
// $ ./01-parity
// n = 10
// verificare cu %: numarul 10 este PAR
// verificare cu &: numarul 10 este PAR
// $ ./01-parity
// n = 119
// verificare cu %: numarul 119 este IMPAR
// verificare cu &: numarul 119 este IMPAR
