#include <string.h>
#include <stdlib.h>
#include <stdio.h>

double LogisticMap(double x0, int r, int n) {
	if (n == 0) {
		return x0;
	}
	return r * LogisticMap(x0, r, n - 1) * (1 - LogisticMap(x0, r, n - 1));
}

int main(int argv, char* argc[]) {

	if (argv != 4) {
		return 1;
	}

	double x0 = atof(argc[1]);
	if (x0 < 0 || x0 > 1) {
		return 1;
	}

	int r = atoi(argc[2]);
	if (r < 0) {
		return 1;
	}

	int n = atof(argc[3]);
	if (n < 0) {
		return 1;
	}

	double lm = LogisticMap(x0, r, n);
	printf("%f", lm);

	return 0; 
}