
#include <stdio.h>

#define NMAX 100

int main(void)
{
	char name[NMAX + 1];
	int age;
	scanf("%s%d", name, &age);

	static const char *filename = "01-gen.txt";

    // 1. deschidere fisier
	FILE *out = fopen(filename, "wt");
	if (!out) {
		fprintf(stderr, "Cannot open file %s\n", filename);
		return -1;
	}

    // 2. scriere fisier
	fprintf(out, "%s %d\n", name, age);

    // 3. inchidere fisier
	fclose(out);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./01-a-i-write_student-text
// gigel 69
//
// $ cat 01-gen.txt
// gigel 69
// $ ls -l 01-gen.txt
// -rw-rw-r-- 1 darius 9 Dec 15 13:02 01-gen.txt
//
