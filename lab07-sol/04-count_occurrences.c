
#include <stdio.h>
#include <string.h>

int count_occurrences(const char *word, const char *phrase)
{
	int count = 0;

	const char *s = phrase;
	while (s) {
		s = strstr(s, word);
		if (!s) {
			break;
		}
		++count;
		printf("occurrence found at position %d\n", (int)(s - phrase));
		++s; // advance one position
	}

	return count;
}

int main(void)
{
	const char *phrase = "Gigel is Gigel all the time except when isn't Gigel,"
			   " but he is still a gigel...";
	const char *word = "Gigel";

	printf("phrase = \"%s\"\n", phrase);
	printf("word = \"%s\"\n", word);
	printf("%d occurrences found for \"%s\"\n",
		   count_occurrences(word, phrase), word);

	return 0;
}

// Run:
// $ ./04-count_occurrences
// phrase = "Gigel is Gigel all the time except when isn't Gigel, but he is still a gigel..."
// word = "Gigel"
// occurrence found at position 0
// occurrence found at position 9
// occurrence found at position 46
// 3 occurrences found for "Gigel"
