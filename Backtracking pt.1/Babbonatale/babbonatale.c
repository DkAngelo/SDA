#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, int* ncall, int* cnt, int* sum, bool* vcurr, int i, bool* vres, int* cntres) {

	(*ncall)++;

	if (*sum > p) {
		return;
	}
	if (i == pacchi_size) {
		if (*cntres > *cnt) {
			* cnt = * cntres;
			for (size_t j = 0; j < pacchi_size; j++) {
				vres[j] = vcurr[j];
			}
		}
		return;
	}
	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, ncall, cnt, sum, vcurr, i + 1, vres, cntres);
	
	vcurr[i] = 1; *sum += pacchi[i]; (*cntres)++;
	BabboNataleRec(pacchi, pacchi_size, p, ncall, cnt, sum, vcurr, i + 1, vres, cntres);
	vcurr[i] = 0; *sum -= pacchi[i]; (*cntres)--;
	
}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p, int *ncall) {
	
	bool* vcurr = calloc(pacchi_size * sizeof(bool), 1);
	int cnt = 0;
	bool* vres = calloc(pacchi_size * sizeof(bool), 1);
	int sum = 0;
	int cntres = 0;
	int tick = clock();
	BabboNataleRec(pacchi, pacchi_size, p, ncall, &cnt, &sum, vcurr, 0, vres, &cntres);
	int tock = clock();
	double elapsed = (tock - tick) / (double)CLOCKS_PER_SEC;

	for (size_t j = 0; j < pacchi_size; j++) {
		printf("%i ", vres[j]);
	}
	printf("\n");
	printf("Elapsed pruning %f\nN. chiamate ricorsive = %i", elapsed, *ncall);

	free(vres);
	free(vcurr);
	return;
}

int main(void) {
	int pacchi[] = { 1, 2, 20, 10, 15, 13, 100, 23, 49, 30, 5 };
	int ncall = 0;
	BabboNatale(pacchi, 11, 100, &ncall);
	return 0;
}