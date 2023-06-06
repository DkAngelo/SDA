#include <stdlib.h>
#include <limits.h>
#include <string.h>

void flip(int* v, size_t i) {
	int* f = malloc(sizeof(int) * (i + 1));
	for (int j = (int)i, k = 0; k <= i; j--, k++) {
		f[k] = v[j];
	}
	memcpy(v, f, sizeof(int) * (i+1));
	free(f);
}

void PancakeSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return;
	}

	for(size_t curr_size = v_size; curr_size != 1;){
		int max = INT_MIN;
		size_t m;
		for (size_t i = 0; i < curr_size; i++) {
			if (v[i] > max) {
				max = v[i];
				m = i;
			}
		}
		flip(v, m);
		flip(v, --curr_size);
	}
}
