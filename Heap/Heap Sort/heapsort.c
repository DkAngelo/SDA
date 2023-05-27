#include "elemtype.h"
#include "minheap.h"

void HeapMinPop(Heap* h) {

	if (HeapIsEmpty(h)) {
		return;
	}
	ElemSwap(&h->data[0], &h->data[h->size - 1]);
	ElemDelete(&h->data[h->size - 1]);
	h->size--;
	HeapMinMoveDown(h, 0);
}

void HeapMinHeapsort(Heap* h) {
	size_t orig = h->size;
	for (size_t i = 0; i < orig; i++) {
		HeapMinPop(h);
	}
	h->size = orig;
}