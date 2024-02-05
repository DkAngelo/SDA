#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void RisolviProdottoRec(int n, const int* s, int* vcurr, bool* used, int* sol, int i, bool *done) {

	if (i == n * n) {
		int prod = 1;
		for (int c = 0; c < n; c++) {
			prod *= vcurr[c];
		}

		for (int r = 1; r < n; r++) {
			int tmp = 1;
			for (int c = 0; c < n; c++) {
				tmp *= vcurr[r * n + c];
			}
			if (tmp != prod) {
				return;
			}
		}
		for (int c = 0; c < n; c++) {
			int tmp = 1;
			for (int r = 0; r < n; r++) {
				tmp *= vcurr[r * n + c];
			}
			if (tmp != prod) {
				return;
			}
		}

		memcpy(sol, vcurr, n * n * sizeof(int));
		*done = true;
		return;
	}

	for (int k = 0; k < n * n; k++) {
		if (!used[k]) {
			used[k] = 1;
			vcurr[i] = s[k];
			RisolviProdottoRec(n, s, vcurr, used, sol, i + 1, done);
			if (!(*done)) {
				vcurr[i] = rand();
				used[k] = 0;
				continue;
			}
			break;
		}
	}
}

int* RisolviProdotto(int n, const int* s) {

	int* vcurr = malloc(n * n * sizeof(int));
	bool* used = calloc(n * n * sizeof(bool), 1);
	int* sol = malloc(n * n * sizeof(int));
	bool done = false;

	RisolviProdottoRec(n, s, vcurr, used, sol, 0, &done);
	free(vcurr);
	free(used);
	if (!done) {
		free(sol);
		return NULL;
	}
	return sol;
}