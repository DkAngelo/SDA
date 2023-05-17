#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int* CacciatorePredaRec(const char* v, size_t v_size, int u, int* vcurr, int* vbest, int cnt, int *cntbest, int i) {

	int j;
	for (j = i; j < v_size; j++) {						//cerco il cacciatore
		if (v[j] == 'c' || v[j] == 'C') {
			break;
		}
	}
	
	if (j == v_size) {
		printf("|");
		for (int k = 0; k < v_size; k++) {
			printf(" %3i |", vcurr[k]);
		}
		printf("\n");

		if (*cntbest < cnt) {
			memcpy(vbest, vcurr, v_size * sizeof(int));
			*cntbest = cnt;
		}
		return;
	}
	
	int min, max;
	if (j - u < 0) {
		min = 0;
	}
	else {
		min = j - u;
	}
	if (j + u > v_size) {
		max = v_size - 1;
	}
	else {
		max = j+u;
	}

	for (int k = min; k <= max; k++) {	//cerco la preda da assegnare al cacciatore
		if ((v[k] == 'P' || v[k] == 'p') && vcurr[k] != -2) {
			vcurr[j] = k;
			vcurr[k] = -2;
			CacciatorePredaRec(v, v_size, u, vcurr, vbest, cnt + 1, cntbest, j + 1);
			vcurr[j] = -1;
			vcurr[k] = -1;
		}
	}
	CacciatorePredaRec(v, v_size, u, vcurr, vbest, cnt, cntbest, j + 1);
}

int* CacciatorePreda(const char* v, size_t v_size, int u) {

	int* vcurr = malloc(v_size * sizeof(int));
	for (int i = 0; i < v_size; i++) {
		vcurr[i] = -1;
	}
	int* vbest = malloc(v_size * sizeof(int));
	for (int i = 0; i < v_size; i++) {
		vbest[i] = -1;
	}

	printf("|");
	for (int i = 0; i < v_size; i++) {
		printf(" %i-", i);
		if (islower(v[i])) {
			printf("%c |", toupper(v[i]));
			continue;
		}
		printf("%c |", v[i]);
	}
	printf("\n");

	int cntbest = 0;

	CacciatorePredaRec(v, v_size, u, vcurr, vbest, 0, &cntbest, 0);

	free(vcurr);
	return vbest;
}