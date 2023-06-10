#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void ParoleT9Rec(const char* str, char* t9[], char* vcurr, int* nsol, size_t i) {

	if (i == strlen(str)) {
		(*nsol)++;
		for (size_t j = 0; j < strlen(vcurr); j++) {
			printf("%c", vcurr[j]);
		}
		printf("\n");
		return;
	}

	int num = str[i] - '0';
	for (size_t j = 0; j < strlen(t9[num - 2]); j++) {
		vcurr[i] = t9[num - 2][j];
		ParoleT9Rec(str, t9, vcurr, nsol, i + 1);
		vcurr[i] = 0;
	}
}
int ParoleT9(const char* str) {

	if (str == NULL) {
		return 0;
	}

	char* vcurr = calloc((strlen(str)+1) * sizeof(char), 1);
	int nsol = 0;
	char* t9[] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXTY" };
	
	ParoleT9Rec(str, t9, vcurr, &nsol, 0);
	
	free(vcurr);
	return nsol;
}