#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool IsPrime(int n, int i) {
	if (i == 1) {
		return true;
	}
	else if(n % i == 0){
		return false;
	}
	return IsPrime(n, i - 1);
}
int main(int argv, char*argc[]) {

	if (argv != 2) {
		return 1;
	}
	
	int n = atoi(argc[1]);
	if (n < 0) {
		return 1;
	}
	else if (n <= 1) {
		printf("false");
		return 0;
	}

	bool prime = IsPrime(n, n/2);
	if (prime) {
		printf("true");
		return 0;
	}
	else {
		printf("false");
		return 0;
	}
}