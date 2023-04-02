#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void TiroAllaFune(int* vcurr, int* v1, int* v2, int* sub, int i, int n) {

	int tmp;
	if (i == n) {
		int sumA = 0;
		for (size_t k = 1; k < (n / 2); k++) {
			sumA += vcurr[k];
		}
		int sumB = 0;
		for (size_t k = (n / 2); k < n; k++) {
			sumB += vcurr[k];
		}
		int subRec = abs(sumA - sumB);
		if (subRec < *sub) {
			*sub = subRec;
			size_t k;
			for (k = 0; k < n / 2; k++) {
				v1[k] = vcurr[k];
			}
			for (size_t j = 0; k < n; k++, j++) {
				v2[j] = vcurr[k];
			}
		}
		return;
	}

	for (int j = i; j < n; j++) {
		tmp = vcurr[i]; vcurr[i] = vcurr[j]; vcurr[j] = tmp;
		TiroAllaFune(vcurr, v1, v2, sub, i + 1, n);
		tmp = vcurr[i]; vcurr[i] = vcurr[j]; vcurr[j] = tmp;
	}
}

int main(int argc, char* argv[]) {

	int* vett = malloc((argc - 1) * sizeof(int));
	int* v1 = malloc(((argc - 1) / 2) * sizeof(int));
	int* v2 = malloc(((argc - 1) - ((argc - 1) / 2)) * sizeof(int));

	for (size_t i = 1; i < argc; i++) {
		vett[i - 1] = atoi(argv[i]);
	}

	int sub = INT_MAX;
	TiroAllaFune(vett, v1, v2, &sub, 0, argc - 1);

	printf("{");
	size_t i;
	for (i = 0; i < ((argc - 1) / 2) - 1; i++) {
		printf(" %i,", v1[i]);
	}
	printf(" %i },", v1[i]);
	printf(" {");
	for (i = 0; i < ((argc - 1) - (argc - 1) / 2) - 1; i++) {
		printf(" %i,", v2[i]);
	}
	printf(" %i }", v2[i]);

	free(vett);
	free(v1);
	free(v2);
	return 0;
}