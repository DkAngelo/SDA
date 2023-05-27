#include "elemtype.h"
#include "minheap.h"

void HeapMinMoveDownRec(Heap* h, int i) {

	ElemType* f = HeapGetNodeValue(h, i);
	ElemType* l;
	ElemType* r;
	ElemType* min; int minpos;

	if (HeapRight(i) < h->size && HeapLeft(i) < h->size) {
		l = HeapGetNodeValue(h, HeapLeft(i));
		r = HeapGetNodeValue(h, HeapRight(i));

		if (ElemCompare(l, r) > 0) {
			min = r;
			minpos = HeapRight(i);
		}
		else {
			min = l;
			minpos = HeapLeft(i);
		}
		if (ElemCompare(f, min) >= 0) {
			ElemSwap(f, min);
			HeapMinMoveDownRec(h, minpos);
		}
		else {
			return;
		}
	}
	else if (!(HeapRight(i) < h->size) && HeapLeft(i) < h->size) {
		if (ElemCompare(f, HeapGetNodeValue(h, HeapLeft(i))) >= 0) {
			ElemSwap(f, HeapGetNodeValue(h, HeapLeft(i)));
			HeapMinMoveDownRec(h, HeapLeft(i));
		}
		else {
			return;
		}
	}
	else {
		return;
	}
}