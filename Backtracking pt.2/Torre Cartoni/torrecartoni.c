#include "torrecartoni.h"

void TorreCartoniRec(const Cartone* c, size_t n,  int* hmax, int i, int* vcurr, int* vbest, size_t *temp, int *ncall, int *weight, int *height) {

	(*ncall)++;
	for (int k = 0; k < n; k++) {

		if (i == 0) {
			vcurr[i] = k;
		}
		else {
			for (size_t j = 0; j < i; j++) {
				if (vcurr[j] == k) {
					k++;
				}
			}
			if (k >= n) {
				return;
			}
			if (c[k].l >= *weight) {
				vcurr[i] = k;
				*weight += c[vcurr[i]].p;
				*height += c[vcurr[i]].a;
			}
			else return;
		}

		if (i == *temp) {
			if (vbest[0] == -1) {
				*hmax = *height;
				for (size_t j = 0; j < *temp; j++) {
					vbest[j] = vcurr[j];
				}
			}
			if (*height > *hmax) {
				*hmax = *height;
				for (size_t j = 0; j < *temp; j++) {
					vbest[j] = vcurr[j];
				}
			}
			return;
		}
		
		TorreCartoniRec(c, n, hmax, i + 1, vcurr, vbest, temp, ncall, weight, height);
		*weight -= c[vcurr[i]].p;
		*height -= c[vcurr[i]].a;
	}
	
}

void TorreCartoni(const Cartone* c, size_t n) {

	int* vcurr = malloc(n * sizeof(int));
	int* vbest = malloc(n * sizeof(int));
	vbest[0] = -1;

	int hmax;
	int weight = 0;
	int height = 0;
	
	size_t temp = n;

	int ncall = 0;
	int tick = clock();

	while (vbest[0] == -1) {
		TorreCartoniRec(c, n, &hmax, 0, vcurr, vbest, &temp, &ncall, &weight, &height);
		if (vbest[0] == -1) {
			temp--;
			vcurr = realloc(vcurr, temp * sizeof(int));
			vbest = realloc(vbest, temp * sizeof(int));
		}
	}

	int tock = clock();
	double elapsed = (tock - tick) / (double)CLOCKS_PER_SEC;
	printf("Elapsed Pruning %f\nN. chiamate ricorsive: %i", elapsed, ncall);

	for (size_t l = 0; l < temp; l++) {
		printf("%i\n", vbest[l]);
	}
	printf("Altezza: %i cm\n", hmax);

	free(vbest);
	free(vcurr);
	return;
}

int main(void) {

	Cartone b[] = { {.p = 10,.a = 10,.l = 8 },
	{.p = 10, .a = 20, .l = 40},
	{.p = 9, .a = 3, .l = 5} };
	TorreCartoni(b, 3);
 }