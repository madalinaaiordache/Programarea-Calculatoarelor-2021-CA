
#include <stdio.h>
#include <stdlib.h> // memory functions

// funcția primește ca parametri dimensiunile unei matrice
// aloca tabloul și returnează pointerul
int **alloc_matrix_varlen(int n, int *m)
{
	// alocam vectorul de linii (de pointeri)
	int **a = (int **)malloc(n * sizeof(int *));
	if (!a) {
		fprintf(stderr, "malloc() failed\n");
		return NULL;
	}

	// alocare propriu-zisa a liniilor
	for (int i = 0; i < n; ++i) {
		a[i] = (int *)malloc(m[i] * sizeof(int));
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
void read_matrix_varlen(int n, int *m, int **a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m[i]; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
}

// funcția va afișa elementele matricei
void print_matrix_varlen(int n, int *m, int **a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m[i]; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// funcție care primește toate datele necesare pentru
// eliberarea unei matrice alocată cu alloc_matrix
void free_matrix_varlen(int n, int *m, int **a)
{
	for (int i = 0; i < n; ++i) {
		free(a[i]);
	}
	free(a);

	// Tema: este m necesar aici? :D
}

int main(void)
{
	// o matriace de intregi cu n linii
	// linia i are m[i] elemente
	int n;
	scanf("%d", &n);
	int *m = (int *)malloc(n * sizeof(int));
	if (!m) {
		fprintf(stderr, "malloc() failed");
		return -1;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m[i]);
	}

	int **a = alloc_matrix_varlen(n, m);
	if (!a) {
		free(m);
		return -1;
	}

	read_matrix_varlen(n, m, a);
	print_matrix_varlen(n, m, a);

	// love your ponies
	free_matrix_varlen(n, m, a);
	free(m);

	return 0;
}

// Rulare:
// $ valgrind ./04-matrix_varlen
// ==29328== Memcheck, a memory error detector
// ==29328== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==29328== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==29328== Command: ./04-matrix_varlen
// ==29328==
// 5
// 1 2 4 5 3
// 10
// 2 22
// 3 3 33 333
// 5 5 5 5 5
// -1 0 -1
// 10
// 2 22
// 3 3 33 333
// 5 5 5 5 5
// -1 0 -1
// ==29328==
// ==29328== HEAP SUMMARY:
// ==29328==     in use at exit: 0 bytes in 0 blocks
// ==29328==   total heap usage: 9 allocs, 9 frees, 2,168 bytes allocated
// ==29328==
// ==29328== All heap blocks were freed -- no leaks are possible
// ==29328==
// ==29328== For lists of detected and suppressed errors, rerun with: -s
// ==29328== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
