#include "vettore.h"

size_t SeekPosMax(Vector* v, size_t n) {
	size_t i, p = 0;
	for (i = 1; i < n; i++) {
		if (ElemCompare(&v->data[p], &v->data[i]) < 0) {
			p = i;
		}
	}
	return p;
}

void VectorSort(Vector* v) {

	if (v == NULL || v->data == NULL) {
		return;
	}
	
	size_t dim = v->size;
	size_t pos;
	while (dim > 1) {
		pos = SeekPosMax(v, dim);
		if (pos < dim - 1) {
			ElemSwap(&v->data[pos], &v->data[dim - 1]);
		}
		dim--;
	}

}

/*int main(void) {

	Vector v = { .size = 10, .capacity = 10, .data = malloc(10 * sizeof(ElemType)) };
	srand(time(NULL));
	for (size_t i = 0; i < v.capacity; i++) {
		v.data[i] = rand();
	}
	VectorSort(&v);

}*/