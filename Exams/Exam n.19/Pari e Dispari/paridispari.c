#include "list.h"
#include "elemtype.h"

Item* PariDispari(Item* i) {
	if (ListIsEmpty(i)) {
		return NULL;
	}

	Item* pari = NULL;
	Item* dispari = NULL;
	Item* headp = NULL;
	Item* headd = NULL;

	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (*ListGetHeadValue(tmp) % 2 == 0) {

			if (ListIsEmpty(pari)) {
				pari = tmp;
				headp = tmp;
				continue;
			}
			pari->next = tmp;
			pari = ListGetTail(pari);
		}
		else{
			if (ListIsEmpty(dispari)) {
				dispari = tmp;
				headd = tmp;
				continue;
			}
			dispari->next = tmp;
			dispari = ListGetTail(dispari);
		}
	}

	for (Item* tmp = headp; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (!ListIsEmpty(tmp->next) && tmp->next->value % 2!= 0) {
			tmp->next = headd;
			break;
		}
		else if (ListIsEmpty(tmp->next)) {
			tmp->next = headd;
			break;
		}
	}
	
	for (Item* tmp = headd; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (!ListIsEmpty(tmp->next) && tmp->next->value %2 == 0) {
			tmp->next = NULL;
			break;
		}
	}

	if (headp != NULL) {
		return headp;
	}
	else {
		return headd;
	}
}