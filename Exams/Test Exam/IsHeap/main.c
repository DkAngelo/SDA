#include "minheap.h"
#include "elemtype.h"
#include <stdlib.h>
#include <string.h>

extern bool IsHeap(const Heap* h);

int main(void) {
	ElemType v1[] = { 1, 2, 8, 3, 4, 12, 10, 32 6 };
	Heap* h1 = HeapCreateEmpty();
	h1->data = malloc(7 * sizeof(ElemType));
	memcpy(h1->data, v1, sizeof(ElemType) * 7);
	h1->size = 7;

	IsHeap(HeapCreateEmpty());
}