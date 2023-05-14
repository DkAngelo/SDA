#include "elemtype.h"
#include "list.h"

extern Item* Sort(Item* i);

int main(void) {

	Item* i = ListCreateEmpty();

	ElemType a = { "andrea", "firenze", 12, "modena", "mo", "41126" };
	i = ListInsertBack(i, &a);
	ElemType b = { "michele", "firenze", 12, "modena", "mo", "41126" };
	i = ListInsertBack(i, &b);
	ElemType c = { "alessandro", "roma", 16, "moliterno", "pz", "41100" };
	i = ListInsertBack(i, &c);
	ElemType d = { "massimo", "peschiera", 54, "modena", "mo", "41126" };
	i = ListInsertBack(i, &d);
	
	i = Sort(i);
}