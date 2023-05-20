#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>

Item* BucketSort(Item* l) {
	
	if (ListIsEmpty(l) || ListIsEmpty(ListGetTail(l))) {
		return l;
	}
	
	int dim;
	int min, max;
	GetMinMaxSize(l, &min, &max, &dim);
	
	Item** v = calloc(sizeof(Item*) * dim, 1);
	
	for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		ElemType e = *ListGetHeadValue(tmp);
		int pos = ((dim - 1) * (e - min)) / (max - min);
		v[pos] = ListInsertBack(v[pos], &e);
	}

	for (int i = 0; i < dim; i++) {
		v[i] = BucketSort(v[i]);
	}

	Item* newl = ListCreateEmpty();
	for (int i = 0; i < dim; i++) {
		newl = ConcatList(newl, v[i]);
	}
	free(v);
	free(l);
	return newl;
}

int main(void) {

	Item* i = ListCreateEmpty();
	ElemType a = 7, b = 2, c = 5, d = 4;
	i = ListInsertBack(i, &a);
	i = ListInsertBack(i, &b);
	i = ListInsertBack(i, &c);
	i = ListInsertBack(i, &d);
	i = BucketSort(i);
}