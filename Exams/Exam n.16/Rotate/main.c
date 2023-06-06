#include "list.h"
#include "elemtype.h"

extern Item* Rotate(Item* i, int n);

int main(void) {

	Item* i1 = ListCreateEmpty();
	ElemType a = 1, b = 3, c = 4, d = 7, e = 8;
	i1 = ListInsertBack(i1, &a);
	ListInsertBack(i1, &b);
	ListInsertBack(i1, &c);
	ListInsertBack(i1, &d);
	ListInsertBack(i1, &e);

	Item *i2 = Rotate(i1, 2);
}