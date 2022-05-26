
// Please read "man realloc"!
//
// Notes:
// 		* "if ptr is NULL, then the call is equivalent to malloc(size),
// for all values of size"
//  	* "if size is equal to zero, and ptr is not NULL, then the call
// is equivalent to free(ptr)."
//

#include <stdio.h>
#include <stdlib.h> // memory functions

#define DEFAULT_CAPACITY 1

int main(void)
{
	int capacity = 0; // cate elemente sunt alocate pentru vector
	int *v = NULL;
	int size = 0; // cate elemente sunt folosite efectiv din vector

	// citesc toate elementele pana la intalnirea unui numar negativ
	int x; // elementul curent citit
	while (scanf("%d", &x) == 1 && x >= 0) {
		// daca vectorul este plin, il extind
		if (size >= capacity) {
			// dublez capacitatea daca este nenula
			capacity = (!capacity ? 1 : 2 * capacity);

			int *tmp = (int *)realloc(v, capacity * sizeof(int));
			if (!tmp) {
				fprintf(stderr, "realloc() failed\n");
				free(v);
				return -1;
			}
			v = tmp;
		}

		// pozitia size (atentie am inceput de la 0)
		// este alocata si poate fi folosita acum
		v[size++] = x;
	}

	// elimin elementele alocate in plus
	if (size < capacity) {
		capacity = size;
		int *tmp = (int *)realloc(v, capacity * sizeof(int));
		if (!tmp) {
			fprintf(stderr, "realloc() failed\n");
			free(v);
			return -1;
		}
		v = tmp;
	}

	// folosire efectiva vector
	printf("size/capacity = %d/%d\n", size, capacity);
	for (int i = 0; i < size; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");

	free(v);

	return 0;
}

// Rulare:
// $ valgrind ./06-resizable_vector
// ==15086== Memcheck, a memory error detector
// ==15086== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==15086== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==15086== Command: ./06-resizable_vector
// ==15086==
// 1 10 100 -1
// size/capacity = 3/3
// 1 10 100
// ==15086==
// ==15086== HEAP SUMMARY:
// ==15086==     in use at exit: 0 bytes in 0 blocks
// ==15086==   total heap usage: 6 allocs, 6 frees, 2,088 bytes allocated
// ==15086==
// ==15086== All heap blocks were freed -- no leaks are possible
// ==15086==
// ==15086== For lists of detected and suppressed errors, rerun with: -s
// ==15086== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

// Tema: Comentati liniile 46-55. Observati relatia intre size si capacity in
// ambele cazuri.
