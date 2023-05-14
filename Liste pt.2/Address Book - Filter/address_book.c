#include "list.h"
#include "elemtype.h"

Item* Filtra(const Item* i, const char* city) {
	
	Item* list = ListCreateEmpty();
	
	if (ListIsEmpty(i)) {
		return list;
	}

	const Item* tmp = i;

	while (!ListIsEmpty(tmp)) {
		const ElemType *cmp = ListGetHeadValue(tmp);
		if (strcmp(cmp->city, city) == 0) {
			list = ListInsertBack(list, cmp);
		}
		tmp = ListGetTail(tmp);
	}

	return list;
}