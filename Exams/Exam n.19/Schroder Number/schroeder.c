#include <stdlib.h>
#include <stdio.h>

int Schroeder(int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 2;
	}
	else {
		return (((6 * n - 3) * Schroeder(n - 1)) / (n + 1)) - (((n - 2) * Schroeder(n - 2)) / (n + 1));
	}
}
int main(int argv, char* argc[]) {

	if (argv != 2) {
		return 1;
	}
	int n = atoi(argc[1]);
	if (n < 0) {
		return 1;
	}

	int Sn = Schroeder(n);
	printf("%i", Sn);
	return 0;
}