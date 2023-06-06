#include "list.h"
#include "elemtype.h"

Item* Rotate(Item* i, int n) {

	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}

	Item* fake = i;
	Item* nh = i;
	for (size_t k = 0; k < n; k++) {
		nh = ListGetTail(nh);
	}

	Item* tmp = nh;
	for (; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {}
	tmp->next = fake;

	while (tmp->next != nh) {
		tmp = ListGetTail(tmp);
	}
	tmp->next = NULL;
	
	return nh;
}