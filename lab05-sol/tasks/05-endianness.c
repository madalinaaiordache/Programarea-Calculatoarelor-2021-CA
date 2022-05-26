
#include <stdio.h>

int main(void)
{
	// pentru unsigned int x
	//           &x = pointer la adresa de memorie unde sunt 4 bytes
	// (char *)  &x = pointer la adresa de memorie unde incepe x,
	//                  dar pointeaza doar catre primul octet!
	// *(char *) &x = valoarea stocata in primul octet
	//                  acest poate sa fie:
	//                      - cel mai putin semnificativ byte
	//                      - cel mai semnificativ byte

	unsigned int x = 1; // numarul meu care are 4 bytes
						// 0|0|0|1 sau 1|0|0|0
						// (in memorie este reprentat in una
						// din conventiile anterioare)
	// Sa presupunem ca &x = 100 (x e la adresa 100)
	// 100 101 102 103   sau 100 101 102 103
	//   0   0   0   1         1   0   0   0
	// Little-endian           Big-endian

	char *o = (char *)&x; // adresa primul octet
						   // first_address == 100
	// *o = valoarea primului octet
	unsigned int first_byte_value = (unsigned int)*o;

	if (first_byte_value != x) {
		printf("Big-endian!\n");
	} else {
		printf("Little-endian!\n");
	}

	return 0;
}

// Rulare:
// $ ./05-endianness
// Little-endian!
