#include "elemtype.h"
#include "doublelist.h"
#include <stdlib.h>

extern Item* ConcatenaN(Item** v, size_t v_size);

int main(void) {

	Item* i1 = DListCreateEmpty();
	ElemType a = 1, b = 2, c = 3, d = 4;
	i1 = DListInsertBack(i1, &a);
	DListInsertBack(i1, &b);
	DListInsertBack(i1, &c);
	DListInsertBack(i1, &d);

	Item* i2 = DListCreateEmpty();
	a = 5, b = 6, c = 7;
	i2 = DListInsertBack(i2, &a);
	DListInsertBack(i2, &b);
	DListInsertBack(i2, &c);

	Item* i3 = DListCreateEmpty();
	a = 8, b = 9, c = 10;
	i3 = DListInsertBack(i2, &a);
	DListInsertBack(i2, &b);
	DListInsertBack(i3, &c);

	Item** v = malloc(3 * sizeof(Item));
	v[0] = i1;
	v[1] = i2;
	v[2] = i3;

	ConcatenaN(v, 3);
}