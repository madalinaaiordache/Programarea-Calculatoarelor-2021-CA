
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 100

// print all tokens found in phrase
void print_tokens(const char *phrase)
{
	static char *delimiters = " \t\n.;,!?";

	// make a copy for phrase, as strtok wants to change it
	char *s = strdup(phrase);
	if (!s) {
		fprintf(stderr, "strdup() failed\n");
		return;
	}

	char *token = strtok(s, delimiters);
	while (token) {
		printf("token = \"%s\"\n", token);
		token = strtok(NULL, delimiters);
	}

	// love your ponies
	free(s);
}

// return 1 iff s is a word (contains only letters)
int is_word(const char *s)
{
	while (*s) {
		if (!isalpha(*s)) {
			return 0;
		}

		++s;
	}

	return 1;
}

// count real words from a phrase
int count_words(const char *phrase)
{
	static char *delimiters = " \t\n.;,!?";

	// make a copy for phrase, as strtok wants to change it
	char *s = strdup(phrase);
	if (!s) {
		fprintf(stderr, "strdup() failed\n");
		return -1;
	}

	int word_count = 0;
	char *token = strtok(s, delimiters);
	while (token) {
		if (is_word(token)) {
			++word_count;
		}

		token = strtok(NULL, delimiters);
	}

	// love your ponies
	free(s);

	return word_count;
}

int main(void)
{
	char phrase[NMAX];
	fgets(phrase, NMAX, stdin);
	phrase[strlen(phrase) - 1] = '\0';

	print_tokens(phrase);
	printf("%d real words found\n", count_words(phrase));

	return 0;
}

// Run:
// $ valgrind ./03-tokens
// gcc -Wall -Wextra -o 03-tokens 03-tokens.c -lm
// ==442951== Memcheck, a memory error detector
// ==442951== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==442951== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==442951== Command: ./03-tokens
// ==442951==
// Who is number #5 in this top, according to Gigel?
// token = "Who"
// token = "is"
// token = "number"
// token = "#5"
// token = "in"
// token = "this"
// token = "top"
// token = "according"
// token = "to"
// token = "Gigel"
// 9 real words found
// ==442951==
// ==442951== HEAP SUMMARY:
// ==442951==     in use at exit: 0 bytes in 0 blocks
// ==442951==   total heap usage: 4 allocs, 4 frees, 2,148 bytes allocated
// ==442951==
// ==442951== All heap blocks were freed -- no leaks are possible
// ==442951==
// ==442951== For lists of detected and suppressed errors, rerun with: -s
// ==442951== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
