#include "elemtype.h"
#include "list.h"

extern Item* CopiaDaN(const Item* i, int n);

int main(void) {
	Item* i = ListCreateEmpty();
	ElemType a = 12;
	i = ListInsertBack(i, &a);
	ElemType b = 2;
	i = ListInsertBack(i, &b);
	ElemType c = 37;
	i = ListInsertBack(i, &c);
	ElemType d = 4;
	i = ListInsertBack(i, &d);

	Item* i1 = CopiaDaN(i, 2);
}