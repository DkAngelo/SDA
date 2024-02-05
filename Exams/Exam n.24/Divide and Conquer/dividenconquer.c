#include <stdlib.h>
#include <stdio.h>

int Divide_n_Conquer(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	if (n % 2 == 0) {
		return Divide_n_Conquer(n / 2) * 2 + n;
	}
	return Divide_n_Conquer(n / 2) + Divide_n_Conquer(n / 2 + 1) + n;
}
int main(int argv, char *argc[]) {
	if (argv != 2) {
		return 1;
	}
	int n = atoi(argc[1]);
	if (n < 0) {
		return 1;
	}

	printf("%i", Divide_n_Conquer(n));
	return 0;
}