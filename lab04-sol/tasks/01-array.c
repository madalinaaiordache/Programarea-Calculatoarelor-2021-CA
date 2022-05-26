
#include <stdio.h>

// maximum length of an array (in this problem)
#define NMAX 100

// read_array: read an array from stdin
// v        - the array (vector) where to store the elements
// @return  - n, the number of elements
int read_array(int v[NMAX])
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}

	return n;
}

// print_array: print an array to stdout
// n        - the array size
// v        - the array
void print_array(int n, int v[NMAX])
{
	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(void)
{
	int v[NMAX];
	int n = read_array(v);
	print_array(n, v);
	return 0;
}

// Run:
// $ make
// $ ./01-array
// 5
// 10 30 -1 4 5
// 10 30 -1 4 5
