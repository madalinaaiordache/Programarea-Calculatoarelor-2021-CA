
#include <stdio.h>

// 1. Eu vreau sa schimb 2 int-uri => int a, b;
// 2. Daca functia va fi apelata de undeva asa:
//     swap(a, b), in functie vor primi copie pentru a si b ... nu e ok
// 3. Atunci functia trebuie sa primeasca adresele lui a si b =
//     in main: swap(&a, &b)
// 4. Inseamna ca functia are semnatura de mai jos
void swap(int *a, int *b)
{
	int tmp = *a; // ATENTIE! tmp e tot int (eu tot int-uri interschimb)
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int a = 2, b = 3;
	printf("before:  a = %d,  b = %d\n", a, b);
	swap(&a, &b); // dau adresele (se vor copia adresele, NU valorile!!!)
	printf("after :  a = %d,  b = %d\n", a, b);
	return 0;
}

// Rulare:
// $ ./02-swap_int
// before:  a = 2,  b = 3
// after :  a = 3,  b = 2
