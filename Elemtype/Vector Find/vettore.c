#include "vettore.h"

int VectorFind(const Vector* v, const ElemType* e) {
	
	if (v == NULL || e == NULL || v->data == NULL) {
		return -1;
	}

	int pos = -1;
	for (int i = 0; i < v->size; i++) {
		if (ElemCompare(e, &v->data[i]) == 0) {
			pos = i;
			break;
		}
	}
	return pos;
}