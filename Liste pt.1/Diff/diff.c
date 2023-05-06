#include "list.h"

Item* Diff(const Item* i1, const Item* i2) {

	Item* list = ListCreateEmpty();
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return list;
	}

	const Item* tmp1 = i1;
	while (!ListIsEmpty(tmp1)) {

		const Item* tmp2 = i2;
		const ElemType* e1 = ListGetHeadValue(tmp1);
		int c = -1;

		while(!ListIsEmpty(tmp2)){
			const ElemType* e2 = ListGetHeadValue(tmp2);
			if (ElemCompare(e1, e2) == 0) {
				c = 0;
				break;
			}
			tmp2 = ListGetTail(tmp2);
		}
		if (c != 0) {
			list = ListInsertBack(list, e1);
		}
		tmp1 = ListGetTail(tmp1);
	}

	return list;
}