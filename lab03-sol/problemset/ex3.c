
// Fie funcţia f:[u,v] − > [min,max],f(x) = a * x2 + b * x + c,
// în care a, b, c, u si v sunt date.
// Determinaţi min si max, apoi rezolvaţi ecuaţia f(x)=0
// în mulţimea numerelor reale.
// Afişaţi doar rădăcinile din intervalul [u,v].

#include <stdio.h>
#include <math.h>
#define eps 0.001

// functia f =  ax^2 + bx + c
double f(double x, double a, double b, double c)
{
	return (double)(a * x * x + b * x + c);
}

int main(void)
{
	double u, v, a, b, c, min, max;
	scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &u, &v);

	if (fabs(a) < eps) {
		if (b > 0) {
			min = f(u, 0, b, c);
			max = f(v, 0, b, c);
		} else {
			min = f(v, 0, b, c);
			max = f(u, 0, b, c);
		}

		return 0;
	}

	double delta = (double)(b * b - 4 * a * c);
	double x_vf = (double)-b / (2 * a), y_vf = (double)-delta / (4 * a);

	if (u <= x_vf && x_vf <= v) {
		if (a > 0) {
			min = y_vf;
			if (f(u, a, b, c) > f(v, a, b, c)) {
				max = f(u, a, b, c);
			} else {
				max = f(v, a, b, c);
			}
		} else  {
			max = y_vf;
			if (f(u, a, b, c) < f(v, a, b, c)) {
				min = f(u, a, b, c);
			} else {
				min = f(v, a, b, c);
			}
		}
	}

	if (x_vf <= u || x_vf >= v) {
		if (a > 0) {
			min = f(u, a, b, c);
			max = f(v, a, b, c);
		} else {
			min = f(v, a, b, c);
			max = f(u, a, b, c);
		}
	}
	printf("min = %f\nmax = %f\n", min, max);

	double x1, x2;
	if (delta > 0) {
		x1 = (double)(-b + sqrt(delta)) / (2 * a);
		x2 = (double)(-b - sqrt(delta)) / (2 * a);

		if (u <= x1 && x1 <= v) {
			printf("x1 = %f\n", x1);

			if (u <= x2 && x2 <= v) {
				printf("x2 = %f\n", x2);
			}
		} else {
			if (u <= x2 && x2 <= v) {
				printf("x2 = %f\n", x2);
			} else {
				printf("Ecuatia nu are solutii in intervalul [%f,%f]\n", u, v);
			}
		}
	} else if (fabs(delta) < eps) {
		x1 = (double)(-b) / (2 * a);
		if (u <= x1 && x1 <= v) {
			printf("x1 = x2 = %f\n", x1);
		} else {
			printf("Ecuatia nu are solutii in intervalul [%f,%f]\n", u, v);
		}
	} else {
		printf("Nu are solutii reale!\n");
	}

	return 0;
}
