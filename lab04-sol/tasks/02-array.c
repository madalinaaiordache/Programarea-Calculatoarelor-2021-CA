
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

// sum_array: computes the sume of all elements from array
// n        - the array size
// v        - the array
// @return  - the computed sum
int sum_array(int n, int v[NMAX])
{
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		sum += v[i];
	}

	return sum;
}

// min_array: the minimum element from array
// n        - the array size
// v        - the array
// @return  - the minimum element
int min_array(int n, int v[NMAX])
{
	int min = v[0];

	for (int i = 1; i < n; ++i) {
		if (v[i] < min) {
			min = v[i];
		}
	}

	return min;
}

// posmax: find the position of the maximum element from array
// n        - the array size
// v        - the array
// @return  - the position of the maximum element
int posmax_array(int n, int v[NMAX])
{
	int max = v[0], posmax = 0;

	for (int i = 1; i < n; ++i) {
		if (v[i] > max) {
			max = v[i];
			posmax = i;
		}
	}

	return posmax;
}

// avg_array: compute the average of all elements from array
// n        - the array size
// v        - the array
// @return  - the computed average
double avg_array(int n, int v[NMAX])
{
	return 1.0 * sum_array(n, v) / n;
}

// find_array: find the first position of an element in array
// n        - the array size
// v        - the array
// x        - the target element
// @return  - the position of the target element if exits
//            otherwise return -1
int find_array(int n, int v[NMAX], int x)
{
	for (int i = 0; i < n; ++i) {
		if (v[i] == x) {
			return i;
		}
	}

	return -1;
}

int main(void)
{
	int v[NMAX];
	int n = read_array(v);
	print_array(n, v);

	printf("sum_array = %d\n", sum_array(n, v));
	printf("min_array = %d\n", min_array(n, v));
	printf("posmax_array = %d\n", posmax_array(n, v));
	printf("avg_array = %.3f\n", avg_array(n, v));
	printf("find_array(n, v, 10) = %d\n", find_array(n, v, 10));
	printf("find_array(n, v, 5) = %d\n", find_array(n, v, 5));

	return 0;
}

// Run:
// $ make
// $ ./01-array
// 5
// 10 30 -1 4 5
// 10 30 -1 4 5
// sum_array = 48
// min_array = -1
// posmax_array = 1
// avg_array = 9.600
// find_array(n, v, 10) = 0
// find_array(n, v, 5) = 4
