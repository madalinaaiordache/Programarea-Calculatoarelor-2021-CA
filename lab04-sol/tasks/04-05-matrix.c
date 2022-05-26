
#include <stdio.h>
#include <string.h> // memcpy, memset

// maximum number of rows/columns for a matrix (in this problem)
#define NMAX 100

// read_matrix: read a matrix from stdin
// n        - the number of rows
// m        - the number of columns
// a        - the matrix
void read_matrix(int n, int m, int a[NMAX][NMAX])
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
}

// read_matrix: print a matrix to stdout
// n        - the number of rows
// m        - the number of columns
// a        - the matrix
void print_matrix(int n, int m, int a[NMAX][NMAX])
{
	printf("n = %d, m = %d:\n", n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// transpose_matrix: compute the matrix transpose (b = a')
// n        - the number of rows
// m        - the number of columns
// a        - the input matrix
// b        - the output matrix (the transpose)
void transpose_matrix(int n, int m, int a[NMAX][NMAX], int b[NMAX][NMAX])
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			b[j][i] = a[i][j];
		}
	}
}

// copy_matrix: copy elements from a matrix (b = a)
// n        - the number of rows
// m        - the number of columns
// a        - the input matrix
// b        - the output matrix (the copy)
void copy_matrix(int n, int m, int a[NMAX][NMAX], int b[NMAX][NMAX])
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			b[i][j] = a[i][j];
		}
	}
}

// check this alternative:
// memcpy(b, sizeof(a), a);

// add_matrix: computex matrix addition (c = a + b)
// n        - the number of rows
// m        - the number of columns
// a        - the input matrix
// b        - the input matrix
// c        - the output matrix (the sum)
void add_matrix(int n, int m, int a[NMAX][NMAX], int b[NMAX][NMAX],
				int c[NMAX][NMAX])
{
	int tmp[NMAX][NMAX];

	// tmp = a * b
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			tmp[i][j] = a[i][j] + b[i][j];
		}
	}

	// c = tmp
	copy_matrix(n, m, tmp, c);
}

// add_matrix: computex matrix product (c = a * b)
// n, m, p  - matrix dimensions: n x m - m x p
// a        - the input matrix
// b        - the input matrix
// c        - the output matrix (the product)
void multiply_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX],
					 int c[NMAX][NMAX])
{
	// tmp = O
	int tmp[NMAX][NMAX];
	memset(tmp, 0, sizeof(tmp));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			for (int k = 0; k < m; ++k) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	memcpy(c, tmp, sizeof(tmp));
}

// power_matrix: computex matrix power (b = a ^ k)
// n        - matrix dimensions: n x n
// a        - the input matrix
// b        - the output matrix (the power)
void power_matrix(int n, int k, int a[NMAX][NMAX], int b[NMAX][NMAX])
{
	// power = O(n)
	int power[NMAX][NMAX] = {0};
	// power = I(n) (identity matrix)
	for (int i = 0; i < n; ++i) {
		power[i][i] = 1;
	}

	// power = a ^ k
	for (int i = 1; i <= k; ++i) {
		// power = power * a
		multiply_matrix(n, n, n, power, a, power);
	}

	// b = power
	memcpy(b, power, sizeof(power));
}

void test_transpose(void)
{
	int n = 3, m = 4;
	int a[NMAX][NMAX] = {
		{ 1,  2,  3,  4},
		{ 5,  6,  7,  8},
		{ 9, 10, 11, 12}
	};
	print_matrix(n, m, a);

	int b[NMAX][NMAX];

	// b = a'
	transpose_matrix(n, m, a, b);
	print_matrix(m, n, b);
}

void test_add(void)
{
	int n = 3, m = 4;
	int a[NMAX][NMAX] = {
		{ 1,  2,  3,  4},
		{ 5,  6,  7,  8},
		{ 9, 10, 11, 12}
	};

	print_matrix(n, m, a);

	// a = a + a
	add_matrix(n, m, a, a, a);
	print_matrix(n, m, a);
}

void test_multiply(void)
{
	int n = 3, m = 4, p = 2;
	int a[NMAX][NMAX] = {
		{ 1,  2,  3,  4},
		{ 5,  6,  7,  8},
		{ 9, 10, 11, 12}
	};

	int b[NMAX][NMAX] = {
		{ 2, 2},
		{ 1, 1},
		{ 0, 0},
		{-1, -1}
	};

	// print a, b
	print_matrix(n, m, a);
	print_matrix(m, p, b);

	// a = a * b
	multiply_matrix(n, m, p, a, b, a);
	print_matrix(n, p, a);
}

void test_power_matrix(void)
{
	int n = 2, k = 6;
	int a[NMAX][NMAX] = {
		{ 0,  1 },
		{ 1,  1 },
	};
	print_matrix(n, n, a);

	// a = a ^ k
	power_matrix(n, k, a, a);
	print_matrix(n, n, a);
}

int main(void)
{
	// test_transpose();
	// test_add();
	// test_multiply();
	test_power_matrix();

	return 0;
}

// Run:
// $ ./04-05-matrix
// n = 2, m = 2:
// 0 1
// 1 1
// n = 2, m = 2:
// 5 8
// 8 13
