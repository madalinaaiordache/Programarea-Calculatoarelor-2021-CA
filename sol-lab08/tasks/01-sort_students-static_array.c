
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_SIZE 29
#define GROUP_MAX_SIZE 5

#define INPUT_LINE_SIZE 100

// Structura pentru un student
typedef struct {
	char name[NAME_MAX_SIZE + 1];
	char groupe[GROUP_MAX_SIZE + 1];
	double grade;
} student_t;

// Funcția de comparație folosită pentru a sorta vectorul de studenți
// folosind qsort().
// Conform semnăturii qsort(), funcția de comparație primește ca parametri
// adresele a două elemente, iar valoarea intoarsa trebuie sa fie:
// - = 0, dacă elementele sunt egale;
// - < 0, dacă primul element este mai mic decât al doilea;
// - > 0, dacă primul element este mai mare decât al doilea.
int student_compare(const void *a, const void *b)
{
	const student_t *sa = (const student_t *)a;
	const student_t *sb = (const student_t *)b;

	return strcmp(sa->name, sb->name);
}

// Funcția care citește o linie din fișierul from
// și realizează parsarea liniei ca o structură de tipul student.
// Despre fișiere urmează să vorbim în laboratorul 9. Acum vom
// seta acest parametru la stdin, pentru ca citirea să se facă
// de la intrarea standard.
// Mai mult, lungimea maximă a liniei este acum un parametru.
// Funcția întoarce 0 în caz de succes sau != 0 în caz de eroare.
int read_student(student_t* dest, FILE *from)
{
	char line[INPUT_LINE_SIZE];
	if (!fgets(line, sizeof(line), from)) {
		return 1;
	}

	// fgets citește până la caracterul newline (\n) sau până la EOF.
	// Dacă acesta nu există în linia citită, înseamnă că bufferul (line) este prea mic sau fișierul de intrare s-a încheiat
	// înainte să ajungem la un \n.
	if (!strchr(line, '\n')) {
		return 2;
	}

	// %30s citește un string de maximum 30 de caractere (incluzând \0)
	int rc = sscanf(line, "%30s %6s %lf", dest->name, dest->groupe, &dest->grade);
	if (rc != 3) {
		return 3;
	}

	return 0;
}

void print_student(const student_t *s)
{
	printf("%30s\t%6s\t%10.2lf\n", s->name, s->groupe,
		   s->grade);
}

int main(void)
{
	// In aceasta solutie vom arata si un exemplu de parsare de date,
	// linie cu linie!
	char line[INPUT_LINE_SIZE];

	int rc; // return code pentru apeluri

	// Citim prima linie din input
	fgets(line, sizeof(line), stdin);

	int no_students;
	rc = sscanf(line, "%d", &no_students);
	if (rc != 1) {
		fprintf(stderr, "Failed to parse.\n");
		exit(1); // echivalent cu return 1; , deoarece suntem in main()
	}

	// Alocăm vectorul in care vom stoca studentii
	student_t *students = (student_t *)malloc(no_students * sizeof(student_t));
	if (!students) {
		fprintf(stderr, "malloc() failed()\n");
		exit(-1);
	}

	for (int i = 0; i < no_students; i++) {
		rc = read_student(&students[i], stdin);
		if (rc != 0) {
			fprintf(stderr, "failed to read student #%d\n", i);
			free(students);
			exit(1);
		}
	}

	// Sortăm (după name) lista de studenți citită.
	// Functia qsort() din stdlib.h implementează sortarea unui vector,
	// a unui tablou unidimensional de orice tip.
	// Funcția primește ca parametrii:
	// - adresa de început a tabloului de sortat;
	// - numărul de elemente din tablou;
	// - dimensiunea (în octeți) a unui element;
	// - o funcție de comparație.
	qsort(students, no_students, sizeof(student_t), student_compare);

	// Afișăm vectorul sortat
	for (int i = 0; i < no_students; i++) {
		print_student(&students[i]);
	}

	// Eliberăm memoria alocată pentru vector
	free(students);

	return 0;
}

// Compile:
// $ make
//
// Run:
// valgrind ./01-sort_students-static_array < sort_students.in
// ==611476== Memcheck, a memory error detector
// ==611476== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==611476== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==611476== Command: ./01-sort_students
// ==611476==
//                           gige	   395	      5.00
//                          gigel	 393CX	      3.00
//                         gigela	  394X	      4.00
//                      gigelinho	 392CX	      2.00
//                          legig	 391CX	      1.00
// ==611476==
// ==611476== HEAP SUMMARY:
// ==611476==     in use at exit: 0 bytes in 0 blocks
// ==611476==   total heap usage: 3 allocs, 3 frees, 5,360 bytes allocated
// ==611476==
// ==611476== All heap blocks were freed -- no leaks are possible
// ==611476==
// ==611476== For lists of detected and suppressed errors, rerun with: -s
// ==611476== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
//
