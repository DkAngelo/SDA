#include "sum_dlist.h"

Item* DListSum(const Item* i1, const Item* i2) {

	Item* ret = DListCreateEmpty();

	if (DListIsEmpty(i1) && DListIsEmpty(i2)) {
		return ret;
	}
	else if (!DListIsEmpty(i1) && DListIsEmpty(i2)) {
		for (const Item* tmp = i1; !DListIsEmpty(tmp); tmp = DListGetTail(tmp)) {
			ret = DListInsertBack(ret, DListGetHeadValue(tmp));
		}
	}
	else if (DListIsEmpty(i1) && !DListIsEmpty(i2)) {
		for (const Item* tmp = i2; !DListIsEmpty(tmp); tmp = DListGetTail(tmp)) {
			ret = DListInsertBack(ret, DListGetHeadValue(tmp));
		}
	}

	const Item* tmp1 = i1;
	for(;!DListIsEmpty(tmp1->next); tmp1 = DListGetTail(tmp1)){}
	const Item* tmp2 = i2;
	for (; !DListIsEmpty(tmp2->next); tmp2 = DListGetTail(tmp2)){}

	ElemType Resto = 0;

	for (;;) {
		
		if (DListIsEmpty(tmp1) && DListIsEmpty(tmp2)) {
			break;
		}

		ElemType Cifra1 = 0;
		if (Resto) {
			Cifra1++;
			Resto--;
		}
		if (!DListIsEmpty(tmp1)) {
			Cifra1 += *DListGetHeadValue(tmp1);
			tmp1 = DListGetPrev(tmp1);
		}

		ElemType Cifra2 = 0;
		if (!DListIsEmpty(tmp2)) {
			Cifra2 += *DListGetHeadValue(tmp2);
			tmp2 = DListGetPrev(tmp2);
		}
		ElemType Cifra = Cifra1 + Cifra2;
		if (Cifra >= 10) {
			Resto++;
			Cifra -= 10;
		}

		ret = DListInsertHead(&Cifra, ret);
	}

	if (Resto) {
		ret = DListInsertHead(&Resto, ret);
	}
	return ret;
}