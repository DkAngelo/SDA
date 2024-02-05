#include <stdio.h>
#include <stdlib.h>

int leonardo(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return leonardo(n - 1) + leonardo(n - 2) + 1;
}

int main(int argc, char* argv[]) {

	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}

	for (int i = 0; i <= n; i++) {
		printf("%i, ", leonardo(i));
	}
	return 0;
}