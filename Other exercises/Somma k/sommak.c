#include <stdio.h>
#include <stdlib.h>

void SommaKRec(int n, int k, int* vcurr, int i, int sum, int *nsol, int last) {

	if (sum == k) {
		(*nsol)++;
		printf("{");
		for (int j = 0; j < i; j++) {
			printf("%i, ", vcurr[j]);
		}
		printf("}, ");
		return;
	}
	else if (sum > k) {
		return;
	}
	else if (i == n) {
		return;
	}

	for (int j = last + 1; j <= n; j++) {
		vcurr[i] = j;
		SommaKRec(n, k, vcurr, i + 1, sum + j, nsol, j);
	}

}

int SommaK(int n, int k) {

	int nsol = 0;
	int* vcurr = malloc(n * sizeof(int));
	SommaKRec(n, k, vcurr, 0, 0, &nsol, 0);
	free(vcurr);
	return nsol;

}