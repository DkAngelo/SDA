#include "elemtype.h"
#include "minheap.h"
#include <string.h>
#include <stdlib.h>

extern void HeapMinHeapsort(Heap* h);

int main(void) {

	ElemType v[] = { 1, 2, 4, 6, 12, 23 , 16};
	Heap* h = HeapCreateEmpty();
	h->data = malloc(7 * sizeof(ElemType));
	memcpy(h->data, v, sizeof(ElemType) * 7);
	h->size = 7;
	HeapMinHeapsort(h);
}