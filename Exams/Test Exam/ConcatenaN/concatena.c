#include "elemtype.h"
#include "doublelist.h"

Item* ConcatenaN(Item** v, size_t v_size) {

	if (v_size == 0) {
		return DListCreateEmpty();
	}

	size_t k;
	for (k = 0; k < v_size; k++) {
		if (!DListIsEmpty(v[k])) {
			break;
		}
	}
	if (k == v_size) {
		return  DListCreateEmpty();
	}

	for (size_t i = k; i < v_size; i++) {
		
		Item *tmp = v[i];
		if (DListIsEmpty(tmp)) {
			continue;
		}

		while (!DListIsEmpty(DListGetTail(tmp))) {
			tmp = DListGetTail(tmp);
		}

		for (size_t j = i + 1; j < v_size; j++) {

			Item* tmp1 = v[j];
			if (DListIsEmpty(tmp1)) {
				continue;
			}
			tmp->next = tmp1;
			tmp1->prev = tmp;
			break;
		}

	}

	return v[k];
}