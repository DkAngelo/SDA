#include "elemtype.h"
#include "list.h"

const ElemType *Find(const Item *i, const char *name){

	if (ListIsEmpty(i)) {
		return NULL;
	}

	const Item *tmp = i;
	while (!ListIsEmpty(tmp)) {
		const ElemType* a = ListGetHeadValue(tmp);
		if (strcmp(name, a->name) == 0) {
			return ListGetHeadValue(tmp);
		}
		tmp = ListGetTail(tmp);
	}
	return NULL;
}