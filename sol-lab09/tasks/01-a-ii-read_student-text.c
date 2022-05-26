
#include <stdio.h>

#define NMAX 100

int main(void)
{
	static const char *filename = "01-gen.txt";

    // 1. deschidere fisier
	FILE *in = fopen(filename, "rt");
	if (!in) {
		fprintf(stderr, "Cannot open file %s\n", filename);
		return -1;
	}

    // 2. citire fisier
	char name[NMAX + 1];
	int age;
	fscanf(in, "%s%d", name, &age);
	printf("save_name = %s\nsave_age = %d\n", name, age);

    // 3. inchidere fisier
	fclose(in);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ cat 01-gen.txt
// gigel 69
//
// ./01-a-ii-read_student-text
// save_name = gigel
// save_age = 69
//
