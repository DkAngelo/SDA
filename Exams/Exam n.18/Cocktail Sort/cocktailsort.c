#include <stdlib.h>
#include <stdbool.h>

void CocktailSort(int* v, size_t v_size) {

	if (v == NULL) {
		return;
	}

	size_t start = 0;
	size_t end = v_size - 1;
	bool scambio = true;

	while (end > start && scambio) {
		scambio = false;
		for (size_t i = 0; i < v_size - 1; i++) {
			if (v[i] > v[i + 1]) {
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				scambio = true;
			}
		}

		if (!scambio) {
			break;
		}
		for (size_t i = end; i > start; i--) {
			if (v[i - 1] > v[i]) {
				int tmp = v[i];
				v[i] = v[i - 1];
				v[i - 1] = tmp;
				scambio = true;
			}
		}
	}
}