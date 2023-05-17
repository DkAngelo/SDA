#include "colora.h"

void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size, char* vcurr, int* nsol, int i) {

	if (i == (int)m->size) {
		(*nsol)++;
		
		for (int j = 0; j < (int)m->size; j++) {
			printf("%i -> %c; ", j, vcurr[j]);
		}
		printf("\n");
		return;
	}
	
	for (size_t k = 0; k < c_size; k++) {
		bool ad = false;
		for (size_t j = 0; j < i; j++) {
			if (m->data[i * m->size + j] && vcurr[j] == c[k] && (int)j != i) {
				ad = true;
				break;
			}
		}
		if (!ad) {
			vcurr[i] = c[k];
			MappaColoriRec(m, c, c_size, vcurr, nsol, i + 1);
		}
	}
}
int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {

	char* vcurr = malloc(sizeof(char) * m->size);
	memset(vcurr, -1, sizeof(char) * m->size);

	int nsol = 0;
	MappaColoriRec(m, c, c_size, vcurr, &nsol, 0);
	free(vcurr);
	return nsol;
}