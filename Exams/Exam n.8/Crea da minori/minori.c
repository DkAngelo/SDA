#include "elemtype.h"
#include "list.h"

Item* CreaDaMinori(const Item* i, int v) {

	if (ListIsEmpty(i)) {
		return NULL;
	}

	Item* list = ListCreateEmpty();
	ElemType a = v;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), &a) < 0) {
			list = ListInsertBack(list, ListGetHeadValue(tmp));
		}
	}
	return list;
}