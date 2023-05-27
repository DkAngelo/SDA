#include "elemtype.h"
#include "maxheap.h"

bool HeapMaxPop(Heap* h, ElemType* e) {

	if (HeapIsEmpty(h)) {
		return false;
	}
	*e = h->data[0];
	ElemSwap(&h->data[0], &h->data[h->size - 1]);
	ElemDelete(&h->data[h->size - 1]);
	h->size--;
	HeapMinMoveDown(h, 0);
	return true;
}