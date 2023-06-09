#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int RadiceNumerica(int n) {

	int a = 0;
	for (size_t i = 0; n != 0; i++) {
		a += n % 10;
		n /= 10;
	}
	if (a >= 10) {
		return RadiceNumerica(a);
	}
	else {
		printf("%i", a);
		return 0;
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

	return RadiceNumerica(n);
}