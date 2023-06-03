#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void SubsetEqualRec(int n, int s, int* vcurr, int sum, int first, int i) {

	if (sum == s) {
		printf("{ ");
		for (int k = 0; vcurr[k] != -1; k++) {
			printf("%i ", vcurr[k]);
		}
		printf("}, ");
		return;
	}

	if (sum > s) {
		return;
	}
	if (i == n) {
		return;
	}

	for (int k = first; k <= n; k++) {
		vcurr[i] = k;
		SubsetEqualRec(n, s, vcurr, sum + k, k + 1, i + 1);
		vcurr[i] = -1;
	}
}

void SubsetEqual(int n, int s) {

	if (n <= 0 || s <= 0) {
		return;
	}

	int* vcurr = malloc(n * sizeof(int));
	memset(vcurr, -1, n * sizeof(int));

	SubsetEqualRec(n, s, vcurr, 0, 1, 0);
}