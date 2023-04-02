#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <time.h>

void StazioniServizioRec(double m, const double* d, const double* p, size_t n, double c, double s, double b, bool* vcurr, bool* vbest, int i, double price, double* bestprice, int cnt, int * cntbest, int *ncall) {

	(*ncall)++;

	if (i == n) {
		if (m > 0) {
			if ((b / c) < m) {
				return;
			}
		}
		if (price < *bestprice) {
			*cntbest = cnt;
			*bestprice = price;
			memcpy(vbest, vcurr, n * sizeof(bool));
		}
		return;
	}

	m -= d[i];
	b -= c * d[i];
	if (b < 0) {
		return;
	}

	vcurr[i] = 0;
	StazioniServizioRec(m, d, p, n, c, s, b, vcurr, vbest, i + 1, price, bestprice, cnt, cntbest, ncall);
	
	vcurr[i] = 1; 
	cnt++;
	double refill = s - b;
	price += refill * p[i];
	b = s;
	StazioniServizioRec(m, d, p, n, c, s, b, vcurr, vbest, i + 1, price, bestprice, cnt, cntbest, ncall);
	vcurr[i] = 0;
	cnt--;
	price -= refill * p[i];
	b = s;

}
void StazioniServizio(double m, const double* d, const double* p, size_t n) {

	double c = 0.05;								//consumo al km
	double s = 30;									//grandezza serbatoio
	bool* vcurr = calloc(n * sizeof(bool), 1);
	bool* vbest = calloc(n * sizeof(bool), 1);
	double bestprice = INT_MAX;						//prezzo sol.migliore
	int cntbest = 0;								//counter stazioni sol.migliore

	int ncall = 0;
	int tick = clock();
	StazioniServizioRec(m, d, p, n, c, s, s, vcurr, vbest, 0, 0, &bestprice, 0, &cntbest, &ncall);
	int tock = clock();
	double elapsed = (tock - tick) / (double)CLOCKS_PER_SEC;
	printf("Elapsed Pruning %f\n", elapsed);
	printf("Ncall: %i\n", ncall);
	
	if (cntbest == 0) {
		printf("Non esistono soluzioni");
	}
	else {
		for (int i = 0; i < n; i++) {
			if (vbest[i]) {
				printf("%i ", i);
			}
		}
		printf("\nSpesa totale: %f euro\n", bestprice);
	}

	free(vbest);
	free(vcurr);
	return;
}

/*int main(void) {

	double m = 2500;
	double d[] = { 260, 284, 308, 332, 356 };
	double p[] = { 35, 35, 33, 29, 23 };
	StazioniServizio(m, d, p, 5);

}*/