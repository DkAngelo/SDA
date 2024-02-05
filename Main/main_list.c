#include "list.h"
#include "elemtype.h"

//extern

int main(void) {

	Item* i1 = ListCreateEmpty();
	ElemType a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8;
	i1 = ListInsertBack(i1, &a);
	ListInsertBack(i1, &b);
	ListInsertBack(i1, &c);
	ListInsertBack(i1, &d);
	ListInsertBack(i1, &e);
	ListInsertBack(i1, &f);
	ListInsertBack(i1, &g);
	ListInsertBack(i1, &h);

	//funzione()
}