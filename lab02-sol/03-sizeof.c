
#include <stdio.h>

int main(void)
{
	// printare dimensiune tip T
	// metoda 1: sizeof(T)
	printf("sizeof(int) = %lu\n", sizeof(int));
	// metoda 2: sizeof(t), unde t e o variabila de tip T
	int i;
	printf("sizeof(i) = %lu\n", sizeof(i));

	printf("sizeof(short int) = %lu\n", sizeof(short int));
	short int si;
	printf("sizeof(si) = %lu\n", sizeof(si));

	printf("sizeof(long) = %lu\n", sizeof(long));
	long l;
	printf("sizeof(l) = %lu\n", sizeof(l));

	return 0;
}

// Tema:
// * De ce s-a folosit in acest exemplu %llu in loc de %d?
// * Schimbati in %llu si compilati! Ce observati?

// Rulare:
// $ make
// $ ./03-sizeof
// sizeof(int) = 4
// sizeof(i) = 4
// sizeof(short int) = 2
// sizeof(si) = 2
// sizeof(long) = 8
// sizeof(l) = 8
