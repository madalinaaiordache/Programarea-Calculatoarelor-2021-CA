
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 100

int read_students(int *n, char ***firstnames, char ***lastnames, int **ages)
{
	int num_students;
	scanf("%d", &num_students);
	*n = num_students;

	char **fs = (char **)malloc(num_students * sizeof(char *));
	if (!fs) {
		fprintf(stderr, "malloc() failed\n");
		return 0;
	}
	*firstnames = fs;

	char **ls = (char **)malloc(num_students * sizeof(char *));
	if (!lastnames) {
		fprintf(stderr, "malloc() failed\n");
		free(fs);
		return 0;
	}
	*lastnames = ls;

	int *as = (int *)malloc(num_students * sizeof(int));
	if (!as) {
		fprintf(stderr, "malloc() failed\n");
		free(ls);
		free(fs);
		return 0;
	}
	*ages = as;

	for (int i = 0; i < num_students; ++i) {
		char firstname[NMAX];
		char lastname[NMAX];
		int age;
		scanf("%s%s%d", firstname, lastname, &age);

		fs[i] = strdup(firstname);
		ls[i] = strdup(lastname);
		as[i] = age;

		// TODO: homework - what cleanup was forgetten here?
	}

	return 1;
}

void free_students(int n, char **firstnames, char **lastnames, int *ages)
{
	for (int i = 0; i < n; ++i) {
		free(lastnames[i]);
		free(firstnames[i]);
	}
	free(ages);
	free(lastnames);
	free(firstnames);

	// TODO: note that resources are freed in the reverse order
}

// swaps 2 students i and j from the student array
void swap_students(char **firstnames, char **lastnames, int *ages, int i, int j)
{
	// swap firstname
	char *tmp_firstname = firstnames[i];
	firstnames[i] = firstnames[j];
	firstnames[j] = tmp_firstname;

	// swap lastname
	char *tmp_lastname = lastnames[i];
	lastnames[i] = lastnames[j];
	lastnames[j] = tmp_lastname;

	// swap age
	int tmp_age = ages[i];
	ages[i] = ages[j];
	ages[j] = tmp_age;
}

// sorts an array of n students
void sort_students(int n, char **firstnames, char **lastnames, int *ages, int criterion)
{
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			switch (criterion) {
			case 1: {
				if (strcmp(lastnames[i], lastnames[j]) > 0) {
					// positive value means i > j
					// we should have i <= j by lastname
					swap_students(firstnames, lastnames, ages, i, j);
				}

				break;
			}

			case 2: {
				if (strcmp(firstnames[i], firstnames[j]) < 0) {
					// positive value means i < j
					// we should have i >= j by firstname
					swap_students(firstnames, lastnames, ages, i, j);
				}

				break;
			}

			case 3: {
				if (ages[i] < ages[j]) {
					// need to change because ages are not in the right order
					swap_students(firstnames, lastnames, ages, i, j);
				} else if (ages[i] == ages[j] && strcmp(lastnames[i], lastnames[j]) > 0) {
					// ages are ordered
					// need to change because lastnames are not in the right order
					swap_students(firstnames, lastnames, ages, i, j);
				} else if (ages[i] == ages[j] && strcmp(lastnames[i], lastnames[j]) == 0 && strcmp(firstnames[i], firstnames[j]) < 0) {
					// ages are ordered
					// lastnames are ordered
					// need to change because firstnames are not in the right order
					swap_students(firstnames, lastnames, ages, i, j);
				}

				break;
			}

			default:
				break;
			}
		}
	}
}

// prints an array of students
void print_students(int n, char **firstnames, char **lastnames, int *ages)
{
	for (int i = 0; i < n; ++i) {
		printf("(%15s, %15s, %5d)\n", firstnames[i], lastnames[i], ages[i]);
	}
	printf("\n");
}

int main(void)
{
	// a student -> (firstnames[i], lastnames[i], ages[i])
	int n;
	char **firstnames;
	char **lastnames;
	int *ages;
	if (!read_students(&n, &lastnames, &firstnames, &ages)) {
		return -1;
	}

	printf("legend:\n");
	printf("\t 1 = asc by lastname\n");
	printf("\t 2 = desc by firstname\n");
	printf("\t 3 = desc by age, lexicographic by lastname, non-lexicographic by firstname\n");
	printf("criterion = ?\n");

	int criterion;
	scanf("%d", &criterion);
	if (criterion < 0 || criterion > 3) {
		fprintf(stderr, "invalid criterion\n");
		free_students(n, firstnames, lastnames, ages);
		return -1;
	}

	sort_students(n, firstnames, lastnames, ages, criterion);
	print_students(n, firstnames, lastnames, ages);
	free_students(n, firstnames, lastnames, ages);

	return 0;
}

// Run:
// $ ./06-mother_of_sorting
// 5
// Roger Federer 39
// Rafael Nadal 34
// Lionel Messi 33
// Cristiano Ronaldo 35
// Novak Djokovic 33
// legend:
//	 1 = asc by lastname
//	 2 = desc by firstname
//	 3 = desc by age, lexicographic by lastname, non-lexicographic by firstname
// criterion = ?
// 1
// (        Ronaldo,       Cristiano,    35)
// (          Messi,          Lionel,    33)
// (       Djokovic,           Novak,    33)
// (          Nadal,          Rafael,    34)
// (        Federer,           Roger,    39)
//
// $ ./06-mother_of_sorting
// 5
// Roger Federer 39
// Rafael Nadal 34
// Lionel Messi 33
// Cristiano Ronaldo 35
// Novak Djokovic 33
// legend:
//	 1 = asc by lastname
//	 2 = desc by firstname
//	 3 = desc by age, lexicographic by lastname, non-lexicographic by firstname
// criterion = ?
// 2
// (        Ronaldo,       Cristiano,    35)
// (          Nadal,          Rafael,    34)
// (          Messi,          Lionel,    33)
// (        Federer,           Roger,    39)
// (       Djokovic,           Novak,    33)
//
// $ ./06-mother_of_sorting
// 5
// Roger Federer 39
// Rafael Nadal 34
// Lionel Messi 33
// Cristiano Ronaldo 35
// Novak Djokovic 33
// legend:
//	 1 = asc by lastname
//	 2 = desc by firstname
//	 3 = desc by age, lexicographic by lastname, non-lexicographic by firstname
// criterion = ?
// 3
// (        Federer,           Roger,    39)
// (        Ronaldo,       Cristiano,    35)
// (          Nadal,          Rafael,    34)
// (          Messi,          Lionel,    33)
// (       Djokovic,           Novak,    33)

// Valgrind check:
// valgrind ./06-mother_of_sorting
// ==474066== Memcheck, a memory error detector
// ==474066== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==474066== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==474066== Command: ./06-mother_of_sorting
// ==474066==
//
// 5
// Roger Federer 39
// Rafael Nadal 34
// Lionel Messi 33
// Cristiano Ronaldo 35
// Novak Djokovic 33
// legend:
//	 1 = asc by lastname
//	 2 = desc by firstname
//	 3 = desc by age, lexicographic by lastname, non-lexicographic by firstname
// criterion = ?
// 3
// (        Federer,           Roger,    39)
// (        Ronaldo,       Cristiano,    35)
// (          Nadal,          Rafael,    34)
// (          Messi,          Lionel,    33)
// (       Djokovic,           Novak,    33)
//
// ==474066==
// ==474066== HEAP SUMMARY:
// ==474066==     in use at exit: 0 bytes in 0 blocks
// ==474066==   total heap usage: 15 allocs, 15 frees, 2,221 bytes allocated
// ==474066==
// ==474066== All heap blocks were freed -- no leaks are possible
// ==474066==
// ==474066== For lists of detected and suppressed errors, rerun with: -s
// ==474066== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
