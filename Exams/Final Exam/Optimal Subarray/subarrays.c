#include <stdlib.h>
#include <stdbool.h>

void OptimalSubarrayRec(const int* v, size_t n, int* vcurr, int sum, int* maxsum, int i, size_t start) {

	if (sum > *maxsum) {
		*maxsum = sum;
	}
	if (i == (int)n || start == n - 1) {
		return;
	}

	if (i == 0) {
		for (size_t k = 0; k < n; k++) {
			vcurr[i] = v[k];
			OptimalSubarrayRec(v, n, vcurr, sum + v[k], maxsum, i + 1, k);
			vcurr[i] = rand();
		}
		return;
	}
	
	vcurr[i] = v[start + 1];
	OptimalSubarrayRec(v, n, vcurr, sum + v[start + 1], maxsum, i + 1, start + 1);
	vcurr[i] = rand();
}
int OptimalSubarray(const int* v, size_t n) {

	if (v == NULL || n == 0) {
		return 0;
	}

	int* vcurr = calloc(n * sizeof(int), 1);
	int maxsum = 0;

	OptimalSubarrayRec(v, n, vcurr, 0, &maxsum, 0, 0);
	free(vcurr);
	return maxsum;
}