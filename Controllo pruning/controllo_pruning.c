#include <time.h>
#include <stdio.h>

int main(void) {
	int ncall = 0;
	int tick = clock();												
	//OmbrelloniRec(k, n, vcurr, 0, &nsol, 0, &ncall);      <chiamata ricorsiva> 
	int tock = clock();
	double elapsed = (tock - tick) / (double)CLOCKS_PER_SEC;
	printf("Elapsed Pruning %f\n", elapsed);
}

//andiamo ad aggiungere +1 ad ncall ogni volta che chiamiamo la funzione ricorsiva