#include "elemtype.h"
#include "minheap.h"

void HeapMinMoveUpRec(Heap* h, int i) {

	ElemType *e = HeapGetNodeValue(h, i);
	ElemType *par = HeapGetNodeValue(h, HeapParent(i));
	if (ElemCompare(par, e) < 0) {
		return;
	}
	else {
		ElemSwap(par, e);
		HeapMinMoveUpRec(h, HeapParent(i));
		return;
	}
}