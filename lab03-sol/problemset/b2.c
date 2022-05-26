
//    Sa se verifice ca un numar natural n e prim

#include <stdio.h>

// int p = is_prime(n);
// p va fi 1 daca n este prim
//         0 altfel

// numar de pasi = n
int is_prime_brute(int n)
{
	// tot ce e mai mic decat 2 NU e prim
	if (n < 2) {
		return 0;
	}

	// 2 e singurul numar prim si par
	if (n == 2) {
		return 1;
	}

	// orice altceva care este par NU e prim
	if (n % 2 == 0) {
		return 0;
	}

	// caut un divizor nebanal impar i al lui n
	for (int i = 3; i < n; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	// daca se ajunge aici n e prim
	return 1;
}

// numar de pasi = sqrt(n)
// deci mai rapida aceasta solutie
int is_prime(int n)
{
	// tot ce e mai mic decat 2 NU e prim
	if (n < 2) {
		return 0;
	}

	// 2 e singurul numar prim si par
	if (n == 2) {
		return 1;
	}

	// orice altceva care este par NU e prim
	if (n % 2 == 0) {
		return 0;
	}

	// caut un divizor nebanal impar i al lui n
	for (int i = 3; 1LL * i * i <= n; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	// daca se ajunge aici n e prim
	return 1;
}

int main(void)
{
	// verificam pentru toate numerele de la 1 la n care sunt prime
	int n = 100;

	for (int i = 1; i <= n; ++i) {
		int state_1 = is_prime(i);
		int state_2 = is_prime_brute(i);

		// vreau ca programul meu sa crape daca cele doua functii nu dau la fel
		if (state_1 != state_2) {
			printf("pentru n = %d: "
				   "[is_prime(%d) = %d] != [is_prime_brute(%d) = %d]\n",
				   i, i, state_1, i, state_2);
			return -2;
		}

		if (state_1) {  // daca i e prim: state_1 == state_2 == 1
			printf("%3d => PRIM\n", i);
		}
	}

	return 0;
}
