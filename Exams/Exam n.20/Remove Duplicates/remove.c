#include "remove.h"

Item* RemoveDuplicates(Item* i){

	Item* origin = i;

	if (ListIsEmpty(i)) {
		return NULL;
	}
	else if (ListIsEmpty(i->next)) {
		return origin;
	}
	else {
		Item* head = i;

		for (Item* tmp = i->next; !ListIsEmpty(tmp); ) {
			if (ElemCompare(ListGetHeadValue(head), ListGetHeadValue(tmp)) != 0) {
				head->next = tmp;
				head = ListGetTail(head);
				tmp = ListGetTail(tmp);
			}
			else {
				Item* del = tmp;
				tmp = ListGetTail(tmp);
				free(del);
			}
		}
		head->next = NULL;
	}
	return origin;
}