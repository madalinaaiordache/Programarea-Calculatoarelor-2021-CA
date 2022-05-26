
#include <stdio.h>
#include <stdlib.h> // memory functions

int main(void)
{
	// un vector de intregi cu n elemente
	int n;
	scanf("%d", &n);

	// alocare
	int *v = (int *)malloc(n * sizeof(int));
	if (!v) {
		fprintf(stderr, "malloc() failed");
		return -1;
	}

	// citire
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}

	// printare
	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");

	// love your ponies
	free(v);

	return 0;
}

// Rulare:
// $ valgrind ./01-basic_vector_example
// ==25942== Memcheck, a memory error detector
// ==25942== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==25942== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==25942== Command: ./01-basic_vector_example
// ==25942==
// 3
// 10 20 30
// 10 20 30
// ==25942==
// ==25942== HEAP SUMMARY:
// ==25942==     in use at exit: 0 bytes in 0 blocks
// ==25942==   total heap usage: 3 allocs, 3 frees, 2,060 bytes allocated
// ==25942==
// ==25942== All heap blocks were freed -- no leaks are possible
// ==25942==
// ==25942== For lists of detected and suppressed errors, rerun with: -s
// ==25942== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
