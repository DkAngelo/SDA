#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void OmbrelloniRec(int k, int n, bool* vcurr, int i, int* nsol, int cnt) {

	if (cnt == k) {
		int j;
		(*nsol)++;
		printf("%4i) ", (* nsol));
		for (j = 0; j < n; j++) {
			printf("%i ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	if (i == n) {
		return;
	}
	
	vcurr[i] = 0;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, cnt);
	
	if (vcurr[i - 1] != 1) {
		vcurr[i] = 1;
		OmbrelloniRec(k, n, vcurr, i + 1, nsol, cnt + 1);
		vcurr[i] = 0;
	}
}

int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0 || n <= (k+(k-1))) {
		return 0;
	}

	bool* vcurr = calloc(sizeof(bool) * n, 1);
	int nsol = 0;
	int tick = clock();												//controllare se il pruning è stato fatto effettivamente bene
	OmbrelloniRec(k, n, vcurr, 0, &nsol, 0);
	int tock = clock();
	double elapsed = (tock - tick) / (double)CLOCKS_PER_SEC;
	printf("Elapsed Pruning %f\n", elapsed);
	free(vcurr);

	return nsol;
}

/*int main(void) {
	Ombrelloni(2, 4);
	return 0;
}*/