#include "list.h"

Item* DiffNoRep(const Item* i1, const Item* i2) {

	Item* list = ListCreateEmpty();
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return list;
	}

	const Item* tmp1 = i1;
	
	while (!ListIsEmpty(tmp1)) {

		const Item* tmp2 = i2;
		const ElemType* e1 = ListGetHeadValue(tmp1);
		int c = -1;

		while (!ListIsEmpty(tmp2)) {
			const ElemType* e2 = ListGetHeadValue(tmp2);
			if (ElemCompare(e1, e2) == 0) {
				c = 0;
				break;
			}
			tmp2 = ListGetTail(tmp2);
		}
		if (c != 0) {
			int comp = -1;
			const Item* tmp3 = list;
			while (!ListIsEmpty(tmp3)) {
				const ElemType* e3 = ListGetHeadValue(tmp3);
				if (ElemCompare(e1, e3) == 0) {
					comp = 0;
					break;
				}
				tmp3 = ListGetTail(tmp3);
			}
			if (comp != 0) {
				list = ListInsertBack(list, e1);
			}
		}
		tmp1 = ListGetTail(tmp1);
	}

	return list;
}

Item* IntersectNoRep(const Item* i1, const Item* i2) {

	Item* list = ListCreateEmpty();
	if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
		return list;
	}

	const Item* tmp1 = i1;
	const ElemType* e1, * e2;
	int c = -1;

	while (!ListIsEmpty(tmp1)) {
		e1 = ListGetHeadValue(tmp1);
		const Item* tmp2 = i2;
		while (!ListIsEmpty(tmp2)) {
			e2 = ListGetHeadValue(tmp2);
			if (ElemCompare(e1, e2) == 0) {
				const Item* tmp3 = list;
				while (!ListIsEmpty(tmp3)) {
					const ElemType* e3 = ListGetHeadValue(tmp3);
					if (ElemCompare(e1, e3) == 0) {
						c = 0;
						break;
					}
					tmp3 = ListGetTail(tmp3);
				}
				if (c != 0) {
					list = ListInsertBack(list, e1);
					break;
				}
			}
			tmp2 = ListGetTail(tmp2);
		}
		tmp1 = ListGetTail(tmp1);
	}

	return list;
}