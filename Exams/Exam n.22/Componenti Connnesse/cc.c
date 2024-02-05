#include "cc.h"

void ComponentiConnesseRec(const Item* i, const ElemType* v, bool* vused, size_t v_size, int* cc) {

	int used = 0;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {

		for (size_t j = 0; j < v_size; j++) {
			
			if (ElemCompare(ListGetHeadValue(tmp), &v[j]) == 0 && !vused[j]) {
				(*cc)++;
				vused[j] = 1;
				used++;

				for (const Item* tmp2 = ListGetTail(tmp); !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
					bool cons = false;
					for (size_t k = 0; k < v_size; k++) {
						if (ElemCompare(ListGetHeadValue(tmp2), &v[k]) == 0 && !vused[k]) {
							cons = true;
							vused[k] = 1;
							used++;
						}
					}
					if (!cons) {
						break;
					}
				}
				break;
			}
		}
		if (used == (int)v_size) {
			break;
		}
	}
}
int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (ListIsEmpty(i) || v == NULL) {
		return 0;
	}

	int cc = 0;
	bool* vused = calloc(v_size, sizeof(bool));
	ComponentiConnesseRec(i, v, vused, v_size, &cc);
	free(vused);
	return cc;
}