#include "elemtype.h"
#include "list.h"

extern Item* Append(const Item* i1, const Item *i2);

int main(void) {

	Item* i1 = ListCreateEmpty();

	ElemType a = { "andrea", "firenze", 12, "modena", "mo", "41126" };
	i1 = ListInsertBack(i1, &a);
	ElemType b = { "michele", "firenze", 12, "modena", "mo", "41126" };
	i1 = ListInsertBack(i1, &b);
	ElemType c = { "alessandro", "roma", 16, "moliterno", "pz", "41100" };
	i1 = ListInsertBack(i1, &c);
	ElemType d = { "massimo", "peschiera", 54, "modena", "mo", "41126" };
	i1 = ListInsertBack(i1, &d);
	
	Item* i2 = ListCreateEmpty();

	ElemType I = { "orazio", "firenze", 12, "modena", "mo", "41126" };
	i2 = ListInsertBack(i2, &I);
	ElemType II = { "asdrubale", "firenze", 12, "modena", "mo", "41126" };
	i2 = ListInsertBack(i2, &II);
	ElemType III = { "gordon", "roma", 16, "moliterno", "pz", "41100" };
	i2 = ListInsertBack(i2, &III);
	ElemType IV = { "ernesto", "peschiera", 54, "modena", "mo", "41126" };
	i2 = ListInsertBack(i2, &IV);
	
	Append(i1, i2);
}