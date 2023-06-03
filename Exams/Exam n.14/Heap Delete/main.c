#include "elemtype.h"
#include "minheap.h"
#include <string.h>
#include <stdlib.h>

extern void HeapDeleteNode(Heap* h, int k);

int main(void) {

	ElemType v1[] = { 1, 2, 4, 6, 12, 23 , 28 };
	Heap* h1 = HeapCreateEmpty();
	h1->data = malloc(7 * sizeof(ElemType));
	memcpy(h1->data, v1, sizeof(ElemType) * 7);
	h1->size = 7;

	HeapDeleteNode(h1, 0);
}