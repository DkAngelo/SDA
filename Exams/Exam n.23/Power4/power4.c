#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool Power4(int n, int* x) {

	if (n == 1) {
		return true;
	}
	if (n % 4 != 0) {
		return false;
	}

	(*x)++;
	return Power4(n / 4, x);
}
int main(int argv, char* argc[]) {

	if (argv != 2) {
		return 1;
	}

	int n = atoi(argc[1]);
	if (n <= 0) {
		return 1;
	}
	int x = 0;
	bool pow = Power4(n, &x);

	if (!pow) {
		printf("!p4");
	}
	else {
		printf("4^%i = %i", x, n);
	}

	return 0;
}