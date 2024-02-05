#include "reverse.h"

Item* Reverse(Item* list, int right) {
	if (ListIsEmpty(list) || right <= 1) {
		return list;
	}

	int len = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); len++, tmp = ListGetTail(tmp)) {}
	if (right >= len) {
		return list;
	}

	Item* ret, *ret1, *head;
	Item* tmp = list;
	for (int i = 0; i < right - 1; i++) {
		tmp = ListGetTail(tmp);
	}
	head = tmp;
	ret = tmp;
	ret1 = tmp->next;
	
	for (tmp = list; !ListIsEmpty(tmp); ) {
		if (tmp == list && ret == tmp->next) {
			ret->next = tmp;
			ret = ListGetTail(ret);
			break;
		}
		if (tmp->next == ret) {
			ret->next = tmp;
			ret = ListGetTail(ret);
			tmp = list;
			continue;
		}
		tmp = ListGetTail(tmp);
	}
	ret->next = ret1;
	return head;
}