#include "elemtype.h"
#include "list.h"

Item* AppendMod(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return i1;
	}
	else if (ListIsEmpty(i1) && !ListIsEmpty(i2)) {
		return i2;
	}
	else if (!ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return i1;
	}
	else {
		Item* tmp = i1;
		while (!ListIsEmpty(ListGetTail(tmp))) {
			tmp = ListGetTail(tmp);
		}
		tmp->next = i2;
		return i1;
	}
}