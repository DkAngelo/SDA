#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
//una variabile condivisa da più funzioni è passata PER INDIRIZZO (nsol e vcurr)
//se invece devo "ricordare" a quale passaggio sono, vengono passate PER COPIA (i)

void SubSetKRec(int n, int k, bool* vcurr, int i, int* nsol, int cnt) {

	if (cnt == k) {
		(*nsol)++;
		printf("{ ");
		for (int j = 0; j < i; j++) {
			if (vcurr[j]) {
				printf("%i ", j);
			}
		}
		printf("}, ");
	}
	if (i == n) {							//caso base
		/*int cnt = 0;
		for (size_t j = 0; j < n; j++) {        //il conteggio può essere fatto all'interno dell funzione
			if (vcurr[j] == 1) {
				cnt++;
			}
		}*/
		return;
	}

	vcurr[i] = 0;								//NON scelgo l'elemento in i
	SubSetKRec(n, k, vcurr, i + 1, nsol, cnt);
	
	vcurr[i] = 1;								//scelgo l'elemento in i
	SubSetKRec(n, k, vcurr, i + 1, nsol, cnt+1);
	vcurr[i] = 0;
}

int SubSetK(int n, int k) {
	bool* vcurr = calloc(n * sizeof(bool), 1);
	int nsol = 0;

	SubSetKRec(n, k, vcurr, 0, &nsol, 0);

	free(vcurr);
	return nsol;
}

int main(void) {
	int sol = SubSetK(4, 2);
	return 0;
}