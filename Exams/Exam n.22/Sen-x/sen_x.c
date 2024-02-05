#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double Factorial(double n) {

	if (n == 1) {
		return 1;
	}

	return n * Factorial(n - 1);
}

double Sen(double x, int i) {

	if (i == 0) {
		return x;
	}

	if (i % 2 != 0) {
		return (- 1 / Factorial(2 * i + 1))* pow(x, 2 * i + 1) + Sen(x, i - 1);
	}
	return (1/ Factorial(2 * i + 1)) * pow(x, 2 * i + 1) + Sen(x, i - 1);
}

int main(int argv, char* argc[]) {

	if (argv != 3) {
		return 1;
	}

	double x = atof(argc[1]);
	int i = atoi(argc[2]);
	if (i < 0) {
		return 1;
	}

	double sen = Sen(x, i);
	printf("%f", sen);
	return 0;
}