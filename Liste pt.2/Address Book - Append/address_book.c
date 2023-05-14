#include "elemtype.h"
#include "list.h"

Item* Append(const Item* i1, const Item* i2) {

	Item* list = ListCreateEmpty();
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return list;
	}

	const Item* tmp1 = i1;
	const Item* tmp2 = i2;
	while (!ListIsEmpty(tmp1)) {
		list = ListInsertBack(list, ListGetHeadValue(tmp1));
		tmp1 = ListGetTail(tmp1);
	}
	while (!ListIsEmpty(tmp2)) {
		list = ListInsertBack(list, ListGetHeadValue(tmp2));
		tmp2 = ListGetTail(tmp2);
	}
	return list;
}