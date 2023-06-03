#include "list.h"
#include "elemtype.h"

extern Item* ElementiPari(const Item* i);

int main(void) {

	Item* i1 = ListCreateEmpty();
	ElemType a = 1, b = 2, c = 3, d = 4, e = 5;
	i1 = ListInsertBack(i1, &a);
	ListInsertBack(i1, &b);
	ListInsertBack(i1, &c);
	ListInsertBack(i1, &d);
	ListInsertBack(i1, &e);

	ElementiPari(i1);
}