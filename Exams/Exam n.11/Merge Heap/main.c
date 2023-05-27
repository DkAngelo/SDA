#include "elemtype.h"
#include "minheap.h"
#include <string.h>
#include <stdlib.h>

extern Heap* MergeHeap(const Heap* h1, const Heap* h2);

int main(void) {

	ElemType v1[] = { 1, 2, 4, 6, 12, 23 , 16 };
	Heap* h1 = HeapCreateEmpty();
	h1->data = malloc(7 * sizeof(ElemType));
	memcpy(h1->data, v1, sizeof(ElemType) * 7);
	h1->size = 7;

	ElemType v2[] = { 10, 14, 19, 26, 31, 42, 27, 44, 35, 33 };
	Heap* h2 = HeapCreateEmpty();
	h2->data = malloc(10 * sizeof(ElemType));
	memcpy(h2->data, v2, sizeof(ElemType) * 10);
	h2->size = 10;

	Heap *hn = MergeHeap(h2, h1);
	HeapDelete(hn);
}