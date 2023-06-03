#include "minheap.h"
#include "elemtype.h"

bool IsHeap(const Heap* h) {

	if (h == NULL) {
		return false;
	}
	else if (HeapIsEmpty(h)) {
		return true;
	}

	for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
		if (HeapRight(i) < h->size) {
			if (HeapRight(i) < h->data[i]) {
				return false;
			}
		}
		if (HeapLeft(i) < h->data[i]) {
			return false;
		}
	}

	return true;
}