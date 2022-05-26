
#include <stdio.h>  // pentru scanf/printf

/* Functia de afisare este printf, de citire de la stdin e scanf
Documentatia lor este explicata in lab
http://ocw.cs.pub.ro/courses/programare/laboratoare/lab01 */

// Cateva exemple
int main(void)
{
	int z, l, a;  // declar 3 numere intregi care inseanma zi, luna, an

	// "%d%d%d" inseamna ca vreau sa citesc 3 numere
	// (intregi in baza zece - decimal),
	// apoi separate prin virgula pun variabilele unde sa le salveze
	scanf("%d%d%d", &z, &l, &a);
	// remember: puneti & inainte de fiecare variabila DOAR la citire

	// ca sa afisez un mesaj pompos
	printf("Gigel este nascut pe %d-%d-%d\n\n", z, l, a);
	// Atentie! aici nu trebuie sa puneti &

	// Vreau sa il intreb pe Gigel cat costa un suc?
	// Numarul este un numar real, deci il declar float
	float price;
	printf("Gigele, cat costa sucul? (introdu pretul apoi apasa enter)\n");
	printf("price:\n");
	scanf("%f", &price);  // %f corespunde lui float
	printf("Ok... ma imprumuti cu (%5.2f) RON? :))\n", price);
	/*
		Obs: vreau sa afisez mereu minimum  5 caractere,
		dintre care fix 2 dupa virgula
		(doar pentru exemplu asta folosesc "_" pentru spatiu :D)
		ex:
		2.2 => "_2.20"
		23.2 => "23.20"
		3.343 => "_3.34"
	*/

	return 0;
}

// Tema:
// * Discutati cu asistentul de ce este nevoie de newline ('\n') la linia
//

// Compilare:
// $ make
// ./main
//./main
// 10 10 2020                          // aici se tasteaza 3 numere intregi
// Gigel este nascut pe 10-10-2020

// Gigele, cat costa sucul? (introdu pretul apoi apasa enter)
// price:
// 123                                 // aici se tasteaza un numar real
// Ok... ma imprumuti cu (123.00) RON? :))

// Ce observati? Prima oara am citit direct de la tastura,
// dar nu i-am spus userului ce sa tastez...
// El astepta, programul astepta...
// In cea de-a doua situatie i-am afisat un mesaj sugestiv, asa ca Gigel
// s-a prins ce trebuie sa scrie
//     Concluzie: puteti afisa un mesaj sugestiv inainte sa asteptati
// ca userul sa introduca ceva, ca sa scrie cam ce asteapta programul.
// ATENTIE! Vom face asta doar in primele laboratoare, pana vom invata
// sa folosim redirectari sau fisiere, caz in care datele vor fi
// citite dintr-un fisier.
