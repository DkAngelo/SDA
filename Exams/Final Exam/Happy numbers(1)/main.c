#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool ishappy(int n) {

	if (n == 1) {
		return true;
	}
	else if (n == 4) {
		return false;
	}

	int cifre;
	int num = n;
	for (cifre = 0; num == 0; cifre++) {
		num /= 10;
	}

	int sum = 0;
	num = n;
	for (int i = 0; i < cifre; i++) {
		sum += ((num % 10) * (num % 10));
		num /= 10;
	}

	return ishappy(sum);
}

int main(int argc, char* argv[]) {
	
	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}
	else if (n == 0) {
		printf("Infelice");
	}

	bool f = ishappy(n);
	if (f) {
		printf("Felice");
	}
	else {
		printf("Infelice");
	}
	return 0;

}