#include "sum_dilist.h"

int main(void) {

	Item* i1 = DListCreateEmpty();
	ElemType a = 9, b = 5, c = 4, d = 4, e = 5, f = 6, g = 7, h = 8;
	i1 = DListInsertBack(i1, &a);
	DListInsertBack(i1, &b);
	DListInsertBack(i1, &c);


	Item* i2 = DListCreateEmpty();
	a = 6, b = 9, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8;
	i2 = DListInsertBack(i2, &a);
	DListInsertBack(i2, &b);


	Item* i3 = DListSum(i1, i2);
}