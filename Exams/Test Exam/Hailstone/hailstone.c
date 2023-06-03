#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int Hailstone(int n, int c) {

	c++;

	if (n == 1) {
		printf("1");
		return c;
	}

	printf("%i, ", n);
	if (n % 2 == 0) {
		return Hailstone(n / 2, c);
	}
	else {
		return Hailstone(3*n +1, c);
	}

}
int main(int argv, char* argc[]) {

	if (argv != 2) {
		return -1;
	}

	int n = atoi(argc[1]);
	if (n <= 0) {
		return 0;
	}
	
	return Hailstone(n, 0);
}