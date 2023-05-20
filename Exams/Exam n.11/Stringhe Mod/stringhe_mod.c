#include <stdio.h>
#include <stdlib.h>

void BacktrackStrModRec(int n, int k, char * vcurr, int i) {

	if (i == k) {
		printf("{");
		for (int j = 0; j < k; j++) {
			printf("%c", vcurr[j]);
		}
		printf("}, ");
		return;
	}

	for (char j = 0; j < n; j++) {
		vcurr[i] = 'a' + j;
		BacktrackStrModRec(n, k, vcurr, i + 1);
		vcurr[i] = 0;
	}
}

void BacktrackStrMod(int n, int k) {
	if (n <= 0 || n > 26 || k <= 0) {
		return;
	}

	char* vcurr = calloc((k + 1) * sizeof(char), 1);
	BacktrackStrModRec(n, k, vcurr, 0);
	free(vcurr);

}