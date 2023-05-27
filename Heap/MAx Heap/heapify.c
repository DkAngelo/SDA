#include "elemtype.h"
#include "maxheap.h"
#include <stdlib.h>
#include <string.h>

Heap* HeapMaxHeapify(const ElemType* v, size_t v_size) {
	
	Heap* h = HeapCreateEmpty();
	if (v == NULL) {
		return h;
	}
	h->size = v_size;
	h->data = malloc(sizeof(ElemType) * h->size);
	memcpy(h->data, v, sizeof(ElemType) * h->size);

	for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
		HeapMaxMoveDown(h, i);
	}
	return h;
}