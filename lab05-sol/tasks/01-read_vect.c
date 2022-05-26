
#include <stdio.h>
#define NMAX 100

// ATENTIE!
//  n   = pointer in functia urmatoare
// *n   = valoarea indicata de pointer
void read_vect(int *n, int *v)
{
	scanf("%d", n); // n este deja pointer catre numarul pe care
					// vreau sa il citesc
	for (int i = 0; i < *n; ++i) { // numarul de elemente este *n
		scanf("%d", &v[i]);
	}
}

// Observatie: Pentru vector declarat static, am fi putut sa avem si urmatoarea
// semnatura:
// void read_vect(int *n, int v[NMAX]);

void print_vect(int n, int *v)
{
	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

// Observatie: Pentru vector declarat static, am fi putut sa avem si urmatoarea
// semnatura:
// void print_vect(int n, int v[NMAX]);

int main(void)
{
	int n, v[NMAX];
	read_vect(&n, v); // pasez pointer catre n
	print_vect(n, v);
	return 0;
}

// Rulare:
// $ ./01-read_vect
// 5
// 10 20 30 40 50
// 10 20 30 40 50
