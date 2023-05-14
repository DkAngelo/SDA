#include "list.h"
#include "elemtype.h"

Item* Sort(Item* i) {
	
	if (ListIsEmpty(i)) {
		return i;
	}

	Item fake = { .next = i };


	int dim = 0;
	Item* tmp1 = i;
	while (!ListIsEmpty(tmp1)) {
		dim++;
		tmp1 = ListGetTail(tmp1);
	}

	int l = 0;
	bool ord = false;
	while (dim > 1 && !ord) {
		ord = true;
		Item* prev = &fake;
		Item* curr = ListGetTail(prev);
		for (; l < dim - 1 || !(curr->next == NULL); l++) {
			Item* next = ListGetTail(curr);
			Item* next2 = ListGetTail(next);
			if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(next)) > 0) {
				prev->next = next;
				curr->next = next2;
				next->next = curr;
				ord = false;
				prev = next;
			}
			else {
				prev = curr;
				curr = next;
			}
		}
		dim--;
	}
	return fake.next;
}