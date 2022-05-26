
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 100

char **read_strings(int n)
{
	char **s = (char **)malloc(n * sizeof(char *));
	if (!s) {
		fprintf(stderr, "malloc() failed\n");
		return NULL;
	}

	for (int i = 0; i < n; ++i) {
		char word[NMAX];
		scanf("%s", word);

		s[i] = strdup(word);
		if (!s[i]) {
			fprintf(stderr, "strdup() failed\n");

			while (--i >= 0) {
				free(s[i]);
			}
			free(s);

			return NULL;
		}
	}

	return s;
}

void free_strings(int n, char **s)
{
	for (int i = 0; i < n; ++i) {
		free(s[i]);
	}
	free(s);
}

// swaps 2 strings
void swap_strings(const char **a, const char **b)
{
	const char *tmp = *a;
	*a = *b;
	*b = tmp;
}

// sorts an array of n strings
void sort_strings(int n, const char **s)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			size_t i_size =  strlen(s[i]);
			size_t j_size =  strlen(s[j]);

			if (i_size > j_size) {
				// we need ascening order by size
				swap_strings(&s[i], &s[j]);
			} else if (i_size == j_size && strcmp(s[i], s[j]) < 0) {
				// we have ascening order by size
				// we need lexicographic order
				swap_strings(&s[i], &s[j]);
			}
		}
	}
}

// prints an array of strings
void print_strings(int n, const char **s)
{
	for (int i = 0; i < n; ++i) {
		printf("%s ", s[i]);
	}
	printf("\n");
}

int main(void)
{
	int n;
	scanf("%d", &n);

	char **s = read_strings(n);
	if (!s) {
		return -1;
	}

	sort_strings(n, (const char **)s);
	print_strings(n, (const char **)s);
	free_strings(n, s);

	return 0;
}

// Run:
// $ valgrind ./02-sort_strings
// ==438857== Memcheck, a memory error detector
// ==438857== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==438857== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==438857== Command: ./02-sort_strings
// ==438857==
// 5
// gigel not_gigel gigel_e_pe_val messi gigel_e_la_acs
// gigel_e_la_acs gigel_e_pe_val not_gigel gigel messi
// ==438857==
// ==438857== HEAP SUMMARY:
// ==438857==     in use at exit: 0 bytes in 0 blocks
// ==438857==   total heap usage: 8 allocs, 8 frees, 2,140 bytes allocated
// ==438857==
// ==438857== All heap blocks were freed -- no leaks are possible
// ==438857==
// ==438857== For lists of detected and suppressed errors, rerun with: -s
// ==438857== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
