#include <stdlib.h>

void GnomeSort(int* v, size_t v_size) {

	size_t i = 1;
	while (i != v_size) {
		if (v[i] >= v[i - 1]) {
			i++;
		}
		else {
			int tmp = v[i];
			v[i] = v[i - 1];
			v[i - 1] = tmp;
			i--;
		}
	}
}