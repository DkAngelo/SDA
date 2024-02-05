#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void ParentesiRec(int n, char* vcurr, int *nsol, int i, int a, int c) {

	if (i == (n*2) - 1) {
		(*nsol)++;
		vcurr[i] = ')';
		printf("%s\n", vcurr);
		vcurr[i] = 0;
		return;
	}
	else if (i == n * 2) {
		return;
	}

	if (i == 0) {
		vcurr[i] = '(';
		ParentesiRec(n, vcurr, nsol, i + 1, a + 1, c);
		return;
	}

	if (a == n) {
		vcurr[i] = ')';
		ParentesiRec(n, vcurr, nsol, i + 1, a, c + 1);
		vcurr[i] = 0;
		return;
	}
	
	if (c < a) {
		vcurr[i] = ')';
		ParentesiRec(n, vcurr, nsol, i + 1, a, c + 1);
		vcurr[i] = 0;
	}
	vcurr[i] = '(';
	ParentesiRec(n, vcurr, nsol, i + 1, a + 1, c);
	vcurr[i] = 0;
	
}
int Parentesi(int n) {

	if (n < 0) {
		return -1;
	}

	char* vcurr = calloc((n * 2 + 1), sizeof(char));
	int nsol = 0;
	ParentesiRec(n, vcurr, &nsol, 0, 0, 0);

	free(vcurr);
	return nsol;
}