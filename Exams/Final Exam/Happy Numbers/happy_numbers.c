#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool Felice(int n) {

	if (n == 4) {
		return false;
	}
	if (n == 1) {
		return true;
	}

	int sum = 0;
	for (int tmp = n; tmp != 0; tmp /= 10) {
		sum += (int)pow(tmp % 10, 2);
	}
	return Felice(sum);
}
int main(int argv, char* argc[]) {

	if (argv != 2) {
		return 1;
	}

	int n = atoi(argc[1]);
	if (n < 0) {
		return 1;
	}
	else if (n == 0) {
		printf("Infelice");
		return 0;
	}
	
	bool felice = Felice(n);
	if (felice) {
		printf("Felice");
	}
	else {
		printf("Infelice");
	}
	return 0;
}