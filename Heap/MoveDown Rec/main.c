#include "elemtype.h"
#include "minheap.h"
#include <string.h>
#include <stdlib.h>

extern void HeapMinMoveDownRec(Heap* h, int i);

int main(void) {

	ElemType v[] = { 24, 1, 2, 4, 6, 12, 23, 17};
	Heap* h = HeapCreateEmpty();
	h->data = malloc(8 * sizeof(ElemType));
	memcpy(h->data, v, sizeof(ElemType) * 8);
	h->size = 8;
	HeapMinMoveDownRec(h, 0);
}