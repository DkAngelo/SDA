#include <stdlib.h>
#include <stdio.h>

long long Catalan(long long n) {

	if (n == 0) {
		return 1;
	}

	long long c = 0;
	for (long long i = 0; i < n; i++) {
		c += Catalan(i) * Catalan(n - 1 - i);
	}
	return c;
}
int main(int argv, char* argc[]) {

	if (argv != 2) {
		return 1;
	}
	
	long long n = atoll(argc[1]);
	
	if (n < 0) {
		return 1;
	}

	long long rec = Catalan(n);
	printf("%lli", rec);

	return 0;
}