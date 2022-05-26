
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

// sort_array: sort an array using Insertion Sort
// n        - the array size
// v        - the array
void sort_array(int n, int v[NMAX])
{
	for (int i = 0; i < n; ++i) {
		// at every step find the minimum element from [i, n - 1]
		// move the minimum element on position i
		int posmin = i;
		for (int j = i + 1; j < n; ++j) {
			if (v[j] < v[posmin]) {
				posmin = j;
			}
		}

		// swap v[i] with v[posmin]
		if (i != posmin) {
			int tmp = v[i];
			v[i] = v[posmin];
			v[posmin] = tmp;
		}
	}
}

int main(void)
{
	int v[NMAX];
	int n = read_array(v);
	print_array(n, v);

	sort_array(n, v);
	print_array(n, v);

	return 0;
}

// Run:
// $ make
// $ ./03-selection_sort
// 5
// 1 -1 2 -3 5
// 1 -1 2 -3 5
// -3 -1 1 2 5
