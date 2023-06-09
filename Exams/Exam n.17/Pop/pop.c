#include "minheap.h"
#include "elemtype.h"
#include <stdlib.h>

bool Pop(Heap* h, ElemType* e) {

	if (h->size == 0) {
		return false;
	}
	*e = h->data[0];
	h->data[0] = h->data[--h->size];
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
	return true;

}