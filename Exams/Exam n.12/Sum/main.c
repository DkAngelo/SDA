#include "elemtype.h"
#include "list.h"

extern Item* Sum(const Item* i1, const Item* i2);

int main(void) {

	Item* i1 = ListCreateEmpty();
	ElemType a = 7, b = 2, c = 5, d = 4;
	i1  = ListInsertBack(i1, &a);
	ListInsertBack(i1, &b);
	ListInsertBack(i1, &c);
	ListInsertBack(i1, &d);

	Item* i2 = ListCreateEmpty();
	a = 3, b = 2, c = 4;
	i2 = ListInsertBack(i2, &a);
	ListInsertBack(i2, &b);
	ListInsertBack(i2, &c);
	Sum(i1, i2);
}