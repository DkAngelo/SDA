#define _CRT_SECURE_NO_WARNINGS

#include "gioielli.h"

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {

	if (filename == NULL) {
		return NULL;
	}

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	
	size_t i;
	for (i = 0; ; i++) {
		int a;
		float b, c;
		int n = fscanf(f, "%i%f%f", &a, &b, &c);
		if (n == EOF) {
			break;
		}
	}

	rewind(f);
	size_t struct_size = i;
	Gioiello* g = malloc(struct_size * sizeof(Gioiello));
	for (i = 0; i < struct_size; i++) {
		int a = fscanf(f, "%i%a%a", &g[i].codice, &g[i].peso,& g[i].prezzo);
	}

	float* app = malloc(struct_size * sizeof(float));
	for(i = 0; i < struct_size; i++){
		app[i] = g[i].peso / g[i].prezzo;
	}

	bool* vbool = calloc(struct_size, sizeof(bool));
	for (i = 0; i < struct_size; i++) {
		float a = 0;
		size_t pos;
		for (size_t j = 0; j < struct_size; j++) {
			if (a < app[j]) {
				a = app[j];
				pos = j;
			}
		}
		float b = budget - g[pos].prezzo;
		if (b < 0) {
			app[pos] = 0;
			continue;
		}
		budget -= g[pos].prezzo;
		vbool[pos] = 1;
		app[pos] = 0;
	}

	size_t cnt = 0;
	for (i = 0; i < struct_size; i++) {
		if (vbool[i]) {
			cnt++;
		}
	}
	*ret_size = cnt;

	Gioiello* ret = malloc(cnt * sizeof(Gioiello));
	size_t j = 0;
	for (i = 0; i < struct_size; i++) {
		if (vbool[i]) {
			ret[j] = g[i];
			j++;
		}
	}

	fclose(f);
	free(g);
	free(vbool);
	free(app);

	return ret;
}