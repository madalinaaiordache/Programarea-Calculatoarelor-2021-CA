
#include <stdio.h>
#include <string.h>

void print_all_char_occurrences(char c, const char *phrase)
{
	const char *s = phrase;
	while (s) {
		s = strchr(s, c);
		if (!s) {
			break;
		}
		printf("%d ", (int)(s - phrase));
		++s;
	}
	printf("\n");
}

void print_all_str_occurrences(const char *word, const char *phrase)
{
	const char *s = phrase;
	while (s) {
		s = strstr(s, word);
		if (!s) {
			break;
		}
		printf("%d ", (int)(s - phrase));
		++s;
	}
	printf("\n");
}

void test_char(void)
{
	char phrase[] = "xlm_xlt_xgm_xmm_xxt";
	char c = 'x';
	print_all_char_occurrences(c, phrase);
}

void test_words(void)
{
	char phrase[] = "xlm_xlt_xgm_xlm_xxt";
	char word[] = "xlm";
	print_all_str_occurrences(word, phrase);
}

int main(void)
{
	test_char();
	test_words();

	return 0;
}

// Run:
// $ /05-print_all_occurrences
// 0 4 8 12 16 17
// 0 12
