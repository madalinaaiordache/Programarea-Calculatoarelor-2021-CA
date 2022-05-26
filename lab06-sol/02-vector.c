
#include <stdio.h>
#include <stdlib.h> // memory functions

void read_vect(int *n, int **v)
{
	scanf("%d", n);

	// alocare
	int *w = (int *)malloc(*n * sizeof(int));
	if (!w) {
		fprintf(stderr, "malloc() failed");
		return;
	}
	*v = w;

	// citire
	for (int i = 0; i < *n; ++i) {
		scanf("%d", &w[i]);
	}
}

void print_vect(int n, int *v)
{
	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(void)
{
	// un vector de intregi cu n elemente
	int n;
	int *v = NULL;

	read_vect(&n, &v);
	if (!v) {
		return -1;
	}
	print_vect(n, v);

	// love your ponies
	free(v);

	return 0;
}

// Rulare:
// $ valgrind ./02-vector
// ==26719== Memcheck, a memory error detector
// ==26719== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==26719== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==26719== Command: ./02-vector
// ==26719==
// 3
// 10 20 30
// 10 20 30
// ==26719==
// ==26719== HEAP SUMMARY:
// ==26719==     in use at exit: 0 bytes in 0 blocks
// ==26719==   total heap usage: 3 allocs, 3 frees, 2,060 bytes allocated
// ==26719==
// ==26719== All heap blocks were freed -- no leaks are possible
// ==26719==
// ==26719== For lists of detected and suppressed errors, rerun with: -s
// ==26719== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
