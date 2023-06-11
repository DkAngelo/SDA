#include <stdlib.h>

int SeekMax(int *v, size_t v_size) {
	int max = v[0];
	for (size_t i = 1; i < v_size; i++) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	return max;
}

int SeekMin(int* v, size_t v_size) {
	int min = v[0];
	for (size_t i = 1; i < v_size; i++) {
		if (min > v[i]) {
			min = v[i];
		}
	}
	return min;
}

void CountingSort(int* v, size_t v_size) {

	if (v == NULL) {
		return;
	}

	int max = SeekMax(v, v_size);
	int min = SeekMin(v, v_size);

	int* tmp = calloc((max - min + 1)*sizeof(int), 1);
	
	for (size_t i = 0; i < (max - min + 1); i++) {
		for (size_t j = 0; j < v_size; j++) {
			if (v[j] == (int)i + min) {
				tmp[i]++;
			}
		}
	}
	
	for (size_t i = 0, j = 0; i < (max - min + 1); i++) {
		for (size_t k = 0; k < tmp[i]; k++, j++) {
			v[j] = (int)i + min;
		}
	}
}