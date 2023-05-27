#include "elemtype.h"
#include "list.h"

Item* Sum(const Item* i1, const Item* i2) {
	
	Item *list = ListCreateEmpty();
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return list;
	}

	const Item* tmp1 = i1, * tmp2 = i2;
	bool r = false;
	while (!ListIsEmpty(tmp1) || !ListIsEmpty(tmp2)) {
		ElemType a = 0;
		if (r) {
			a += 1;
			r = false;
		}
		if (!ListIsEmpty(tmp1)) {
			a += *ListGetHeadValue(tmp1);
			tmp1 = ListGetTail(tmp1);
		}
		if (!ListIsEmpty(tmp2)) {
			a += *ListGetHeadValue(tmp2);
			tmp2 = ListGetTail(tmp2);
		}

		if ((int)a >= 10) {
			r = true;
			a %= 10;
		}
		list = ListInsertBack(list, &a);
	}
	if (r) {
		ElemType a = 1;
		list = ListInsertBack(list, &a);
	}
	return list;
}