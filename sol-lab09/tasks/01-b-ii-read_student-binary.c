
#include <stdio.h>
#include <string.h>

#define NMAX 100

int main(void)
{
	static const char *filename = "01-gen.bin";

    // 1. deschidere fisier
	FILE *in = fopen(filename, "rb");
	if (!in) {
		fprintf(stderr, "Cannot open file %s\n", filename);
		return -1;
	}

    // 2. citire fisier
	char name[NMAX + 1];
	int age;
    // 2.1. citire string
    // conventie: citim lungimea, apoi toti bytes, inclusiv '\0'
    // exemplu: "gigel" -> strlen == 5, citim 6 bytes
	int len;
	fread(&len, sizeof(int), 1, in);
	fread(name, sizeof(char), len, in);
    // 2.2. scriere age
	fread(&age, sizeof(int), 1, in);

	printf("save_name = %s\nsave_age = %d\n", name, age);

    // 3. inchidere fisier
	fclose(in);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ hexdump -v -C 01-gen.bin
// 00000000  06 00 00 00 67 69 67 65  6c 00 45 00 00 00        |....gigel.E...|
// 0000000e
//
// $ ./01-b-ii-read_student-binary
// save_name = gigel
// save_age = 69
//
