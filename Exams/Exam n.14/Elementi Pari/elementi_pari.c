#include "list.h"
#include "elemtype.h"

Item* ElementiPari(const Item* i) {

	Item* list = ListCreateEmpty();
	if (ListIsEmpty(i)) {
		return list;
	}

	int cnt = 0;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp), cnt++) {
		if (cnt % 2 == 0) {
			list = ListInsertBack(list, ListGetHeadValue(tmp));
		}
	}

	return list;
}