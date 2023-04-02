#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

void StazioniServizioRec(double m, const double* d, const double* p, size_t n, double c, double s, bool* vcurr, bool* vbest, int i, double price, double* bestprice, int *cnt) {

	if (i == n) {
		double b = s;
		int cntrec = 0;
		for (size_t j = 0; j < n; j++) {
			m -= d[j];
			b -= c * d[j];
			if (b < 0) {
				return;
			}
			if (vcurr[j]) {
				cntrec++;
				double refill = s - b;
				price += refill * p[j];
				b = s;
			}
		}
		if (price < *bestprice) {
			*cnt = cntrec;
			*bestprice = price;
			memcpy(vbest, vcurr, n * sizeof(bool));
		}
		return;
	}
	vcurr[i] = 0;
	StazioniServizioRec(m, d, p, n, c, s, vcurr, vbest, i + 1, price, bestprice, cnt);
	vcurr[i] = 1;
	StazioniServizioRec(m, d, p, n, c, s, vcurr, vbest, i + 1, price, bestprice, cnt);

}
void StazioniServizio(double m, const double* d, const double* p, size_t n) {

	double c = 0.05;							//consumo al km
	double s = 30;								//grandezza serbatoio
	bool* vcurr = calloc(n * sizeof(bool), 1);
	bool* vbest = calloc(n * sizeof(bool), 1);
	double bestprice = INT_MAX;					//prezzo sol.migliore
	int cnt = 0;								//counter stazioni sol.migliore

	StazioniServizioRec(m, d, p, n, c, s, vcurr, vbest, 0, 0, &bestprice, &cnt);
	
	if (cnt == 0) {
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
	return;
}

/*int main(void) {

	double m = 1540;
	double d[] = { 260, 284, 308, 332, 356 };
	double p[] = { 35, 35, 33, 29, 23 };
	StazioniServizio(m, d, p, 5);

}*/