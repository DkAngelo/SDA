#include <stdlib.h>
#include <stdbool.h>

void BrickSort(int* v, size_t v_size) {

	if (v == NULL) {
		return;
	}

	bool ord = false;
	while (!ord) {
		ord = true;
		for (size_t i = 1; i < v_size; i += 2) {
			if (v[i] > v[i + 1] && i + 1 < v_size) {
				ord = false;
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
			}
		}

		if (!ord) {
			ord = true;
			for (size_t i = 0; i < v_size; i += 2) {
				if (v[i] > v[i + 1] && i + 1 < v_size) {
					ord = false;
					int tmp = v[i];
					v[i] = v[i + 1];
					v[i + 1] = tmp;
				}
			}
		}
	}
}