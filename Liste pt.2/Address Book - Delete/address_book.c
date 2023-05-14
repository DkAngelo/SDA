#include "elemtype.h"
#include "list.h"


const ElemType* Find(const Item* i, const char* name) {

	if (ListIsEmpty(i)) {
		return NULL;
	}

	const Item* tmp = i;
	while (!ListIsEmpty(tmp)) {
		const ElemType* a = ListGetHeadValue(tmp);
		if (strcmp(name, a->name) == 0) {
			return ListGetHeadValue(tmp);
		}
		tmp = ListGetTail(tmp);
	}
	return NULL;
}

Item* Delete(Item* i, const char* name) {

	if (ListIsEmpty(i)) {
		return i;
	}
	const ElemType* del = Find(i, name);
	if (del == NULL) {
		return i;
	}
	else {
		Item* tmp = i;
		while (!ListIsEmpty(tmp)) {
			if (tmp->next == del) {
				Item* next1 = ListGetTail(tmp);
				tmp->next = tmp->next->next;
				ElemDelete(ListGetHeadValue(next1));
				free(next1);
				break;
			}
			tmp = ListGetTail(tmp);
		}
		return i;
	}
}