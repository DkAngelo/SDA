#include <stdlib.h>
#include <string.h>

void InsertionSort(int* v, size_t v_size) {
	for (size_t j = 1; j < v_size; j++) {
		for (size_t i = 0; i < j; i++) {
			if (v[i] > v[j]) {
				int tmp = v[j];
				memmove(v + i + 1, v + i, (j - i) * sizeof(int));
				v[i] = tmp;
				break;
			}
		}
	}
}