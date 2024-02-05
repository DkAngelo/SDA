#include "next_greater.h"

ElemType* NextGreater(const Item* list, size_t* answer_size) {

	if (ListIsEmpty(list)) {
		*answer_size = 0;
		return NULL;
	}

	size_t n = 0;
	for (const Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		n++;
	}

	*answer_size = n;
	ElemType* answer = malloc(n * sizeof(ElemType));
	
	const Item* tmp1 = list;
	for (size_t i = 0; i < n; i++) {
		
		answer[i] = INT_MIN;
		
		for (const Item* tmp2 = ListGetTail(tmp1); !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp2), ListGetHeadValue(tmp1)) > 0) {
				answer[i] = *ListGetHeadValue(tmp2);
				break;
			}
		}
		tmp1 = ListGetTail(tmp1);
	}
	return answer;
}