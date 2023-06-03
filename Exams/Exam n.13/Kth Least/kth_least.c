#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <string.h>

ElemType KthLeast(const Heap* h, int k) {

	ElemType a;
	Heap* tmp = HeapCreateEmpty();
	tmp->data = malloc(h->size * sizeof(ElemType));
	tmp->size = h->size;
	memcpy(tmp->data, h->data, h->size * sizeof(ElemType));

	for (int i = 0; i < k; i++) {
		a = tmp->data[0];
		tmp->data[0] = tmp->data[tmp->size - 1];
		tmp->data = realloc(tmp->data, (--tmp->size) * sizeof(ElemType));
		HeapMinMoveDown(tmp, 0);
	}
	HeapDelete(tmp);
	return a;
}