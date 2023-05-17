#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void RegoleRec(const char* r, int* vcurr, bool* vused, size_t len, size_t i) {
	
	if (i == len + 1) {
		for (size_t j = 0; j < len + 1; j++) {
			printf("%i ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	
	for (int j = 1; j <= (int)(len + 1); j++) {
		bool I = !vused[j - 1];
		bool a = i == 0;
		bool b = (r[i - 1] == 'i' || r[i - 1] == 'I') && vcurr[i - 1] < j;
		bool c = (r[i - 1] == 'd' || r[i - 1] == 'D') && vcurr[i - 1] > j;
		bool II = a || b || c;
		if (I && II) {
			vcurr[i] = j;
			vused[j - 1] = true;
			RegoleRec(r, vcurr, vused, len, i + 1);
			vcurr[i] = 0;
			vused[j - 1] = false;
		}
	}
	
}
void Regole(const char* r) {
	if (r == NULL) {
		printf("1");
		return;
	}
	size_t len = strlen(r);
	int* vcurr = calloc(sizeof(int) * (len + 1), 1);
	bool* vused = calloc(sizeof(bool) * (len + 1), 1);

	RegoleRec(r, vcurr, vused, len, 0);
	free(vcurr);
	free(vused);
	return;
}