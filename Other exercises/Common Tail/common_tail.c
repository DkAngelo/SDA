#include "list.h"
#include "elemtype.h"

const Item* CommonTail(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}

	for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
		for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if (tmp1 == tmp2) {
				return tmp2;
			}
		}
	}

	return ListCreateEmpty();
}