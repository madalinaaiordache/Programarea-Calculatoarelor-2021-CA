
#include <stdio.h>
#include <string.h>

#define NMAX 100

int main(void)
{
	char name[NMAX + 1];
	int age;
	scanf("%s%d", name, &age);

	static const char *filename = "01-gen.bin";

    // 1. deschidere fisier
	FILE *out = fopen(filename, "wb");
	if (!out) {
		fprintf(stderr, "Cannot open file %s\n", filename);
		return -1;
	}

    // 2. scriere fisier
    // 2.1. scriere string
    // conventie: scriem lungimea, apoi toti bytes, inclusiv '\0'
    // exemplu: "gigel" -> strlen == 5, scriem 6 bytes
	int len = strlen(name) + 1;
	fwrite(&len, sizeof(int), 1, out);
	fwrite(name, sizeof(char), len, out);
    // 2.2. scriere age
	fwrite(&age, sizeof(int), 1, out);

    // 3. inchidere fisier
	fclose(out);

	return 0;
}

// Compile:
// $ make
//
// Run:
// ./01-b-i-write_student-binary
// gigel 69
//
// $ hexdump -v -C 01-gen.bin
// 00000000  06 00 00 00 67 69 67 65  6c 00 45 00 00 00        |....gigel.E...|
// 0000000e
//
// Explanation:
// "gigel\0" -> strlen == 5, but we have 6 bytes with '\0' -> len = 5 + 1 = 6
//      len == 06 00 00 00
//  gigel\0 == 67 69 67 65  6c 00
//       69 == 45 00 00 00
//
