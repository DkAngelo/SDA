#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void PasswordRec(const char* str, int n, char* vcurr, int* nsol, int i) {

	if (i == n) {
		(*nsol)++;
		printf("%s\n", vcurr);
		return;
	}

	for (size_t j = 0; j < strlen(str); j++) {
		vcurr[i] = str[j];
		PasswordRec(str, n, vcurr, nsol, i + 1);
		vcurr[i] = 0;
	}
}

int Password(const char* str, int n) {
	if (str == NULL) {
		return 0;
	}

	char* vcurr = calloc((n + 1) * sizeof(char), 1);
	int nsol = 0;

	PasswordRec(str, n, vcurr, &nsol, 0);
	
	free(vcurr);
	return nsol;
}