#include "list.h"
#include "elemtype.h"

const Item* CommonTail(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
		return NULL;
	}

	const Item* tmp1 = i1;
	while (!ListIsEmpty(tmp1)) {
		const Item* tmp2 = i2;
		while (!ListIsEmpty(tmp2)) {
			if (tmp1 == tmp2) {
				return tmp1;
			}
			tmp2 = ListGetTail(tmp2);
		}
		tmp1 = ListGetTail(tmp1);
	}
	return NULL;
}