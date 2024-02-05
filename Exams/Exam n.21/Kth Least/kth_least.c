#include <stdlib.h>
#include <string.h>
#include "elemtype.h"
#include "minheap.h"

int KthLeastRec(Heap *h, int k) {
	int min;
	for (int i = 0; i < k; i++) {
		min = h->data[0];
		h->data[0] = h->data[h->size - 1];
		h->data = realloc(h->data, --h->size * sizeof(int));
		HeapMinMoveDown(h, 0);
	}
	return min;
}

int KthLeast(const int* v, size_t n, int k) {

	Heap* h = HeapCreateEmpty();
	for (int i = 0; i < (int)n; i++) {
		HeapMinInsertNode(h, &v[i]);
	}

	int min = KthLeastRec(h, k);
	HeapDelete(h);
	return min;
}