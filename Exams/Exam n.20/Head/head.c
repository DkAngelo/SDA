#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv, char* argc[]) {

	if (argv != 2) {
		return 1;
	}

	FILE* f = fopen(argc[1], "r");
	int cnt = 0;
	while (1) {
		if (cnt == 10) {
			break;
		}
		int c = fgetc(f);
		if (c == EOF) {
			break;
		}
		if (c == '\n') {
			cnt++;
		}
		int b = fputc(c, stdout);
	}
	if (cnt != 10) {
		fputc('n', f);
	}

	return 0;
}