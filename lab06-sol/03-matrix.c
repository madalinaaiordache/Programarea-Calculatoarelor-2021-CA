
#include <stdio.h>
#include <stdlib.h> // memory functions

// funcția primește ca parametri dimensiunile unei matrice
// aloca tabloul și returnează pointerul
int **alloc_matrix(int n, int m)
{
	// alocam vectorul de linii (de pointeri)
	int **a = (int **)malloc(n * sizeof(int *));
	if (!a) {
		fprintf(stderr, "malloc() failed\n");
		return NULL;
	}

	// alocare propriu-zisa a liniilor
	for (int i = 0; i < n; ++i) {
		a[i] = (int *)malloc(m * sizeof(int));
		if (!a[i]) {
			fprintf(stderr, "malloc() failed\n");

			// elibereaza memoria alocata pentru liniile anterioare
			while (--i >= 0) {
				free(a[i]);
			}
			free(a);

			return NULL;
		}
	}

	return a;
}

// funcția primește dimensiunile unei matrice și matricea alocată
// va citi elementele și le va salva în matrice
void read_matrix(int n, int m, int **a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
}

// funcția va afișa elementele matricei
void print_matrix(int n, int m, int **a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// funcție care primește toate datele necesare pentru
// eliberarea unei matrice alocată cu alloc_matrix
void free_matrix(int n, int m, int **a)
{
	for (int i = 0; i < n; ++i) {
		free(a[i]);
	}
	free(a);

	// Tema: este m necesar aici? :D
}

int main(void)
{
	// o matriace de intregi cu n x m elemente
	int n, m;
	scanf("%d%d", &n, &m);
	int **a = alloc_matrix(n, m);
	if (!a) {
		return -1;
	}
	read_matrix(n, m, a);

	print_matrix(n, m, a);

	// love your ponies
	free_matrix(n, m, a);

	return 0;
}

// Rulare:
// $ valgrind ./03-matrix
// ==28177== Memcheck, a memory error detector
// ==28177== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==28177== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==28177== Command: ./03-matrix
// ==28177==
// 2 3
// 10 20 30
// 40 50 60
// 10 20 30
// 40 50 60
// ==28177==
// ==28177== HEAP SUMMARY:
// ==28177==     in use at exit: 0 bytes in 0 blocks
// ==28177==   total heap usage: 5 allocs, 5 frees, 2,088 bytes allocated
// ==28177==
// ==28177== All heap blocks were freed -- no leaks are possible
// ==28177==
// ==28177== For lists of detected and suppressed errors, rerun with: -s
// ==28177== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
