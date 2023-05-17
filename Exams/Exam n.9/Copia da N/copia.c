#include "elemtype.h"
#include "list.h"

int ListSize(const Item* i) {
	int size = 0;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		size++;
	}
	return size;
}

Item* CopiaDaN(const Item* i, int n) {
	Item* list = ListCreateEmpty();
	if (ListIsEmpty(i)) {
		return list;
	}

	int dim = ListSize(i);
	if (dim < n) {
		return list;
	}

	const Item* tmp = i;
	for (int cnt = 1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp), cnt++) {
		if (cnt < n) {
			continue;
		}
		list = ListInsertBack(list, ListGetHeadValue(tmp));
	}
	return list;
}