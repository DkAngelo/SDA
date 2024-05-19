#include "elemtype.h"
#include "list.h"

Item* Reverse(Item* i) {

	if (ListIsEmpty(i)) {
		return i;
	}

	size_t n_item = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		n_item++;
	}

	Item* cmp = ListCreateEmpty();
	Item* head = ListCreateEmpty();
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		cmp = tmp;
		head = tmp;
	}

	for (size_t j = 0; j < n_item; j++) {

		if (j == n_item - 1) {
			i->next = NULL;
			break;
		}

		for (Item* tmp = i; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
			Item* uno = tmp;
			Item* due = tmp->next;
			if (due == cmp) {
				due->next = uno;
				cmp = uno;
				break;
			}
		}
	}

	return head;
}