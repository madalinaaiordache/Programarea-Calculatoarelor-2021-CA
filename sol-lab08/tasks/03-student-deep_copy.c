
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROUP_NAME_SIZE 5

#define INPUT_LINE_SIZE 100

// Structura pentru un student
typedef struct {
	char *name;
	char groupe[GROUP_NAME_SIZE + 1];
	double grade;
} student_t;

// Funcția care citește o linie din fișierul from
// și realizează parsarea liniei ca o structură de tipul student.
// Funcția întoarce 0 în caz de succes sau != 0 în caz de eroare.
int read_student(student_t *s)
{
	// presupunem ca dimensiunea maxima a numelui este INPUT_LINE_SIZE
	char buff[INPUT_LINE_SIZE + 1];
	if (scanf("%s", buff) != 1) {
		return 0; // nu am reusit sa citesc numele
	}
	s->name = strdup(buff);
	if (!s->name) {
		return 0; // strdup a esuat
	}

	if (scanf("%s%lf", s->groupe, &s->grade) != 2) {
		free(s->name); // love your ponies
		return 0;      // nu am reusit sa citesc grupa si media
	}

	return 1; // toate datele au fost citite si salvate (alocate)
}

void print_student(const student_t *s)
{
	printf("%30s\t%6s\t%10.2lf\n", s->name, s->groupe,
		   s->grade);
}

void destroy_student(student_t *s)
{
	free(s->name);
}

int copy_student(student_t *dst, student_t *src)
{
	// copy name
	dst->name = strdup(src->name);
	if (!dst->name) {
		fprintf(stderr, "strdup() failed\n");
		return 0;
	}

	// copy groupe
	strcpy(dst->groupe, src->groupe);

	// copy grade
	dst->grade =  src->grade;

	return 1; // success
}

int main(void)
{
	// pas a: citire si declarare student
	student_t student;
	read_student(&student);
	printf("student: ");
	print_student(&student);

	// pas b: "copy = student"
	student_t copy;
	copy_student(&copy, &student);
	printf("   copy: ");
	print_student(&copy);

	// pas c: modificam copia
	printf("changing copy ...\n");
	copy.name[0] = 'X';
	copy.groupe[0] = '*';
	copy.grade = 2020;

	// pas d: afisam ambele structuri
	printf("student: ");
	print_student(&student);
	printf("   copy: ");
	print_student(&copy);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ valgrind ./03-student-deep_copy
// ==617590== Memcheck, a memory error detector
// ==617590== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==617590== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==617590== Command: ./03-student-deep_copy
// ==617590==
// gigel 3XXCA 10
// student:                          gigel	 3XXCA	     10.00
//    copy:                          gigel	 3XXCA	     10.00
// changing copy ...
// student:                          gigel	 3XXCA	     10.00
//    copy:                          Xigel	 *XXCA	   2020.00
// ==617590==
// ==617590== HEAP SUMMARY:
// ==617590==     in use at exit: 12 bytes in 2 blocks
// ==617590==   total heap usage: 4 allocs, 2 frees, 2,060 bytes allocated
// ==617590==
// ==617590== LEAK SUMMARY:
// ==617590==    definitely lost: 12 bytes in 2 blocks
// ==617590==    indirectly lost: 0 bytes in 0 blocks
// ==617590==      possibly lost: 0 bytes in 0 blocks
// ==617590==    still reachable: 0 bytes in 0 blocks
// ==617590==         suppressed: 0 bytes in 0 blocks
// ==617590== Rerun with --leak-check=full to see details of leaked memory
// ==617590==
// ==617590== For lists of detected and suppressed errors, rerun with: -s
// ==617590== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
//
