#include "elemtype.h"
#include "list.h"

Item* Reverse(const Item* i) {
	
	Item* list = ListCreateEmpty();
	if (ListIsEmpty(i)) {
		return list;
	}
	const Item* tmp = i;
	while (!ListIsEmpty(tmp)) {
		list = ListInsertHead(ListGetHeadValue(tmp), list);
		tmp = ListGetTail(tmp);
	}
	return list;
}