#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void GolaCrestaRec(size_t n, int* vcurr, bool min, bool mag, int i) {

	if (i == (int)n) {
		printf("(");
		for (size_t j = 0; j < n; j++) {
			if (j != n - 1) {
				printf("%i, ", vcurr[j]);
				continue;
			}
			printf("%i), ", vcurr[j]);
		}
		return;
	}

	if (i == 0) {
		for (int k = 0; k < 3; k++) {
			vcurr[i] = k;
			GolaCrestaRec(n, vcurr, true, true, i + 1);
			vcurr[i] = -1;
		}
		return;
	}
	for (int k = 0; k < 3; k++) {
		if (k > vcurr[i - 1] && min) {
			vcurr[i] = k;
			GolaCrestaRec(n, vcurr, false, true, i + 1);
		}
		else if (k < vcurr[i - 1] && mag) {
			vcurr[i] = k;
			GolaCrestaRec(n, vcurr, true, false, i + 1);
		}
		vcurr[i] = -1;
	}
}
void GolaCresta(size_t n) {
	if (n < 3) {
		return;
	}

	int* vcurr = malloc(n * sizeof(int));
	GolaCrestaRec(n, vcurr, true, true, 0);
	free(vcurr);
	return;
}