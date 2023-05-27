#include "elemtype.h"
#include "maxheap.h"

void HeapMaxPop(Heap* h) {

	if (HeapIsEmpty(h)) {
		return;
	}
	ElemSwap(&h->data[0], &h->data[h->size - 1]);
	ElemDelete(&h->data[h->size - 1]);
	h->size--;
	HeapMaxMoveDown(h, 0);
}

void HeapMaxHeapsort(Heap* h) {
	size_t orig = h->size;
	for (size_t i = 0; i < orig; i++) {
		HeapMaxPop(h);
	}
	h->size = orig;
}