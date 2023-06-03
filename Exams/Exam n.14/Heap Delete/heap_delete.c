#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>

void HeapDeleteNode(Heap* h, int k) {
	if (k < 0 || k >= (int)h->size) {
		return;
	}

	ElemSwap(HeapGetNodeValue(h, k), HeapGetNodeValue(h, (int)h->size - 1));
	h->data = realloc(h->data, (--h->size) * sizeof(ElemType));
	HeapMinMoveDown(h, k);
}