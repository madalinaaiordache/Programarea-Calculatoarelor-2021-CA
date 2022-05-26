
#include <stdio.h>
#define NMAX 100

// Vi s-a dat aceasta semnatura, care este similara cu a functiei memcpy
// din string.h
//
// Sa intelegem semnificatia:
//
// 0. Functia are ca scop copierea de bytes dintr-o locatie in alta. Intrucat
// am dori sa putem copia bytes si dintr-un int, si dintr-un vector de char,
// si dintr-o matrice de double-uri etc (pe scurt orice tip de date),
// solutia este sa primi pointeri de tipul void*, care inseamna pointeri catre
// o locatie unde nu stie ce date sunt.
//      Reamintim ca operatia de cast la void* se face automat.
//
// 1. void* destination vs const void* source
//      - void*: nu stim ce date sunt acolo
//          - source pointeaza catre o zona cu date constante
//              (dorim sa copiam datele, prin urmare nu are sens ca functia sa
//               poata modifica datele din source)
//          - destination pointeaza catre o zona cu date care pot modifica
//              (lucru necesar daca dorim sa copiam noile date)
// 2. num reprezinta numar de bytes care se vor copia din source in destination
//
void my_memcpy(void *destination, const void *source, int num)
{
	// daca cel putin unul dintre parametri este NULL,
	// nu putem afectua operatia
	if (!destination || !source) {
		return;
	}

	// Deoarece nu pot sa aplic * pe cei 2 pointeri void * (ca sa iau valori)
	// o sa ii convertesc la pointeri catre byte (unsigned char),
	// pe care pot aplica * (dereferentiere)
	unsigned char *dst = (unsigned char *)destination;
	const unsigned char *src = (const unsigned char *)source;

	// copiez byte cu byte
	for (int i = 0; i < num; ++i) {
		dst[i] = src[i];
		// *(dst + i) = *(src + i);
		// *dst++ = *src++;
	}
}

void print_vect(int n, int *v)
{
	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(void)
{
	int n = 6;
	int v[NMAX] = {1, 2, 3, 4, 5, 6};

	int w[NMAX]; // neinitializat

	// Vreau sa copiez cu my_memcpy toate numerele din v in w
	// 1. Cine e destination? (void *destination)
	//      - destinatia este w (care este deja un pointer catre locatia
	//           unde vreau sa copiez datele)
	// 2. Cine e source?
	//      - sursa este v (care este deja pointer catre locatia unde
	//          amdatele de intrare)
	// 3. Cine este num? (int num == numarul de bytes)
	//      - eu vreau sa copiez n elemente
	//      - fiecare element este un int (are dimensiune sizeof(int))
	//          - deci n elemente vor avea n * sizeof(int) bytes
	my_memcpy(w, v, n * sizeof(int));
	// Mai sus nu am mentionat ca se fac 2 cast-uri
	// - w este un "int*", v este tot un "int *"
	// De ce merge totusi cand functia asteapta "void*"?
	// Se face cast automat. Putem privi ca destination si source
	// sunt "declarate" asa:
	//      void *destination = (void *) w;
	//      void *source = (void *) v;
	print_vect(n, w);

	// Trebuie retinut ca aceasta functie poate fi folosita sa se copieze
	// orice sir de bytes (care poate reprezenta o variabila de tip int,
	// vector, matrice, struct etc)

	// Tema: exersati copiat elemente din urmatoarele surse:
	// double src[NMAX] = {1, 2, 3, 4.5};
	// char src = 'A';
	// long double gigel = 4.5f;
	// int a[NMAX][NMAX] = {{1,2}, {3, 4}};

	return 0;
}

// Rulare:
// $ ./04-my_memcpy
// 1 2 3 4 5 6
