#include "list.h"

const ElemType* MaxElement(const Item* i) {

	if (ListIsEmpty(i)) {
		return NULL;
	}

	const ElemType* tmp = ListGetHeadValue(i);  //ipotizzo primo elemento come massimo
	const Item* list = ListGetTail(i);			//siccome ho gia' il valore in head, posso confrontare a partire dal secondo elemento in poi

	while (!ListIsEmpty(list)) {

		int cmp = ElemCompare(tmp, ListGetHeadValue(list));		//"compare" tra tmp e la value attuale della lista
		if (cmp < 0) {
			tmp = ListGetHeadValue(list);						//se tmp e' minore, lo modifico assegnandogli il valore attuale della lista
		}
		list = ListGetTail(list);								//scorro la lista
	}

	return tmp;
}