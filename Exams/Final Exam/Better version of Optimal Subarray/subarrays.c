#include <stdlib.h>
#include <stdio.h>

void Rec(const int* v, size_t n, int sum, int *vcurr, int i, int *max, int last) {

	if (sum > *max) {
		*max = sum;
	}
	if (i == (int)n || last == (int)n) {
		return;
	}

	if (i == 0) {
		for (int j = last; j < (int)n; j++) {
			vcurr[i] = v[j];
			Rec(v, n, sum + v[j], vcurr, i + 1, max, j + 1);
			vcurr[i] = 0;
		}
	}
	else {
		vcurr[i] = v[last];
		Rec(v, n, sum + v[last], vcurr, i + 1, max, last + 1);
		vcurr[i] = 0;
	}
}
int OptimalSubarray(const int* v, size_t n) {

	if (n == 0 || v == NULL) {
		return 0;
	}
	int max = 0;
	int* vcurr = malloc(n * sizeof(int));
	Rec(v, n, 0, vcurr, 0, &max, 0);
	free(vcurr);
	return max;
}