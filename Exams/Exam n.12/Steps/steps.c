#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StepsRec(int n, int* vcurr, int* nsol, int sum, int i) {

	if (sum > n) {
		return;
	}
	else if (sum == n) {
		(*nsol)++;
		printf("[");
		for (int j = 0; ; j++) {
			if (vcurr[j + 1] == -1) {
				printf("%i], ", vcurr[j]);
				break;
			}
			printf("%i, ", vcurr[j]);
		}
		return;
	}

	for (int j = 1; j <= 3; j++) {
		vcurr[i] = j;
		StepsRec(n, vcurr, nsol, sum + j, i + 1);
		vcurr[i] = -1;
	}
}

int Steps(int n) {
	if (n <= 0) {
		return 0;
	}
	
	int *vcurr = malloc((n+1) * sizeof(int));
	memset(vcurr, -1, (n+1) * sizeof(int));
	int nsol = 0;
	StepsRec(n, vcurr, &nsol, 0, 0);
	
	free(vcurr);
	return nsol;
}