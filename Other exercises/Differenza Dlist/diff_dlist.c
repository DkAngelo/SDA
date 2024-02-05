#include "diff_dlist.h"

Item* DListDiff(const Item* i1, const Item* i2) {

	Item* i3 = DListCreateEmpty();
	if (DListIsEmpty(i1)) {
		return i3;
	}
	else if (DListIsEmpty(i2)) {
		const Item* tmp1 = i1;
		for (; !DListIsEmpty(tmp1); tmp1 = DListGetTail(tmp1)) {
				i3 = DListInsertBack(i3, DListGetHeadValue(tmp1));
		}
		return i3;
	}

	const Item* tmp1 = i1;
	for (; !DListIsEmpty(DListGetTail(tmp1)); tmp1 = DListGetTail(tmp1)) {}

	const Item* tmp2 = i2;
	for (; !DListIsEmpty(DListGetTail(tmp2)); tmp2 = DListGetTail(tmp2)) {}

	int p = 0;
	for (; !DListIsEmpty(tmp1); tmp1 = DListGetPrev(tmp1)) {
		ElemType a = *DListGetHeadValue(tmp1);
		if (p) {
			a -= p;
			p = 0;
			if (a == -1) {
				p = 1;
			}
		}

		ElemType b;
		if (!DListIsEmpty(tmp2)) {
			b = *DListGetHeadValue(tmp2);
		}
		else {
			b = 0;
		}

		if (ElemCompare(&a, &b) < 0) {
			a += 10;
			p = 1;
		}
		ElemType ris = a - b;
		i3 = DListInsertHead(&ris, i3);

		if (!DListIsEmpty(tmp2)) {
			tmp2 = DListGetPrev(tmp2);
		}
	}

	return i3;
}