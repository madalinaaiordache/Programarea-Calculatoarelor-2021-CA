
#include <stdio.h>

// 1. Eu vreau sa schimb 2 pointer la int => int *p, *q;
// 2. Daca functia va fi apelata de undeva asa:
//     swap_ptr(p, q), in functie se vor copia valorile lui p si q...
// 3. Atunci functia trebuie sa primeasca adresele lui p si q
//     => in main: swap_ptr(&p, &q)
//   Obs: Rationamentul este analog celui de la swap_int.
// 4. Inseamna va functia are semnatura de mai jos
void swap_ptr(int **p, int **q)
{
	int *tmp = *p; // ATENTIE! tmp e un int *
				   // interschimb pointeri in acesta problema
	*p = *q;
	*q = tmp;
}

int main(void)
{
	int a = 2, b = 3;
	int *p = &a, *q = &b; // voi interschimba p si q

	printf("before:  p = %p,  q = %p\n", p, q);
	swap_ptr(&p, &q); // dau adresele (se vor copia adresele, NU valorile!!!)
	printf("after :  p = %p,  q = %p\n", p, q);

	return 0;
}

// Rulare:
// $ ./03-swap_ptr
// before:  p = 0x7ffef8ac9280,  q = 0x7ffef8ac9284
// after :  p = 0x7ffef8ac9284,  q = 0x7ffef8ac9280
