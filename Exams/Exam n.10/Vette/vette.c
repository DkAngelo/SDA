#include "elemtype.h"
#include "list.h"

int ContaVette(const Item* i) {
	int cnt = 0;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		bool vetta = true;
		for (const Item* tmp2 = ListGetTail(tmp); !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(tmp2)) != 1) {
				vetta = false;
				break;
			}
		}
		if (vetta) {
			cnt++;
		}
	}
	return cnt;
}