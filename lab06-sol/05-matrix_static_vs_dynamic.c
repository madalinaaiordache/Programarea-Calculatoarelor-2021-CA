
#include <stdio.h>
#include <stdlib.h> // memory functions

#define NMAX 3

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

void print_static_matrix_address(int n, int m, int a[NMAX][NMAX])
{
	printf("static matrix: \n");

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%15p ", &a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

void print_dynamic_matrix_address(int n, int m, int **a)
{
	printf("dynamic matrix: \n");

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%15p ", &a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

int main(void)
{
	// dimensiuni matrice
	int n = 3, m = 3;

	// matrice alocata static
	int s[NMAX][NMAX];
	print_static_matrix_address(n, m, s);

	// matrie alocata dinamic
	int **d = alloc_matrix(n, m);
	if (!d) {
		return -1;
	}
	print_dynamic_matrix_address(n, m, d);
	free_matrix(n, m, d);

	return 0;
}

// Rulare:
// $ valgrind ./05-matrix_static_vs_dynamic
// ==31545== Memcheck, a memory error detector
// ==31545== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==31545== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==31545== Command: ./05-matrix_static_vs_dynamic
// ==31545==
// static matrix:
//    0x1ffefffc80    0x1ffefffc84    0x1ffefffc88
//    0x1ffefffc8c    0x1ffefffc90    0x1ffefffc94
//    0x1ffefffc98    0x1ffefffc9c    0x1ffefffca0
//
// dynamic matrix:
//       0x4a634e0       0x4a634e4       0x4a634e8
//       0x4a63530       0x4a63534       0x4a63538
//       0x4a63580       0x4a63584       0x4a63588
//
// ==31545==
// ==31545== HEAP SUMMARY:
// ==31545==     in use at exit: 0 bytes in 0 blocks
// ==31545==   total heap usage: 5 allocs, 5 frees, 1,084 bytes allocated
// ==31545==
// ==31545== All heap blocks were freed -- no leaks are possible
// ==31545==
// ==31545== For lists of detected and suppressed errors, rerun with: -s
// ==31545== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
