#include <stdlib.h>
#include <stdio.h>

int Triangular(int n) {

	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 3;
	}

	return 3 * Triangular(n - 1) - 3 * Triangular(n - 2) + Triangular(n - 3);
}
int main(int argv, char* argc[]) {

	if (argv != 2) {
		return 1;
	}

	int n = atoi(argc[1]);
	if (n < 0) {
		return 1;
	}

	printf("%i", Triangular(n));
	return 0;
}