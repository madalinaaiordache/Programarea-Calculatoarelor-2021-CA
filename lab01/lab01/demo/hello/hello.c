
// Asta este o linie care contine comentarii, ea nu reprezinta ceva pentru
// compilator, ci este o notita pusa de mine aici
// Compilatorul ignora aceste linii

/*
	Daca vreau sa comentez mai multe linii, includ aceste linii
	ca in acest exemplu

								acesta.
*/

//   Este bine sa punem comentarii in cod pentru ca oricine care citeste
// codul nostru sa inteleaga foarte usor ceea ce vrem sa facem acolo..
// nu are rost sa ne luam injuraturi
// Alt motiv: peste ceva timp nici tu nu mai intelegi ce ai scris acolo!

// Orice program incepe cu includere de biblioteci (si altele.. vom vedea)

#include <stdio.h>  // Aici am inclus biblioteca stdio.h

// Orice program C are o functie main. Momentan nu ne intereseaza ce este
// o functie,
// asa ca pentru inceput tinem minte ca orice program
// are textul
	/*
		int main(void)
		{
			// aici pun ce vreau sa fac programul meu
			...

			return 0; // aici spun ca programul s-a terminat cu 0 erori
					  // momentan nu ne intereseaza ce putem scrie inafara de 0
		}
	*/

int main(void)
{
	printf("Hello\n");  // afisez mesajul "Hello"

	return 0;
}

// Tema:
// * Modificati programul astfel incat sa afisze "Hello World!" pe o linie.

// Compilare:
// $ make
// (rulati comanda "make" in terminal, in directorul unde se afla hello.c)
// $ make run
// ./hello
// Hello
// (rulati comanda "make run" in terminal, in directorul unde se afla hello.c)

// Documentatia oficiala C: http://cpp.arh.pub.ro/c/language
//
// Exemplu folosire documentatie:
// 1) https://man7.org/linux/man-pages/man3/stdio.3.html
//      Hint: man something (in terminal sau pe Google)
//          Exmple:
//              - documentatie pentru o biblioteca: man stdio.h
//              - documentatie pentru o functie:    man scanf
//                                                  man printf
//
// 2) http://www.cplusplus.com/reference/cstdio/
//
// 3) https://ocw.cs.pub.ro/courses/programare/laboratoare/lab01#interactiunea_program-utilizator
//
// Recomandam sursele de documentatie in ordinea mentionata (1, 2, 3).
