#include "elemtype.h"
#include "minheap.h"

Heap* MergeHeap(const Heap* h1, const Heap* h2) {

	Heap* nh = HeapCreateEmpty();
	if (HeapIsEmpty(h1) && HeapIsEmpty(h2)) {
		return nh;
	}
	
	size_t max;
	if (h1->size >= h2->size) {
		max = h1->size;
	}
	else {
		max = h2->size;
	}
	for (size_t i = 0; i < max; i++) {
		if (i < h1->size) {
			HeapMinInsertNode(nh, &h1->data[i]);
		}
		if (i < h2->size) {
			HeapMinInsertNode(nh, &h2->data[i]);
		}
	}
	return nh;
}