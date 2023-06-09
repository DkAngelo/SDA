#include "list.h"
#include "elemtype.h"

Item* Reverse(Item* i) {

	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}
	
	Item* nh, *tmp;
	for (tmp = i; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {};
	nh = tmp;
	Item* fake = nh;

	for (tmp = i; ; ) {
		if (tmp->next == nh) {
			if (tmp == i) {
				tmp->next = NULL;
				nh->next = tmp;
				break;
			}
			else {
				nh->next = tmp;
				nh = ListGetTail(nh);
				tmp = i;
				continue;
			}
		}
		tmp = ListGetTail(tmp);
	}
	return fake;
}