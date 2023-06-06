#include "elemtype.h"
#include "tree.h"

extern Node* CreateMaxBinTree(const ElemType* v, size_t v_size);

int main(void) {

	ElemType v[] = { 0, 4, 7, 12, 45, 88, 23, 6, 2, 90, 35, 11 };
	Node* t = CreateMaxBinTree(v, 12);
	TreeDelete(t);
}