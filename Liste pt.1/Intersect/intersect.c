#include "list.h"

Item* Intersect(const Item* i1, const Item* i2) {

	Item* list = ListCreateEmpty();
	if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
		return list;
	}

	const Item* tmp1 = i1;
	const ElemType* e1, *e2;
	while (!ListIsEmpty(tmp1)){
		e1 = ListGetHeadValue(tmp1);
		const Item* tmp2 = i2;
		while (!ListIsEmpty(tmp2)) {
			e2 = ListGetHeadValue(tmp2);
			if (ElemCompare(e1, e2) == 0) {
				list = ListInsertBack(list, e1);
				break;
			}
			tmp2 = ListGetTail(tmp2);
		}
		tmp1 = ListGetTail(tmp1);
	}

	return list;
}