#include "elemtype.h"
#include "tree.h"

extern bool TreeIsMirror(const Node* t);

int main(void) {
	
	ElemType e[] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23, 77 };

	Node* mirr = TreeCreateRoot(e + 0, NULL, NULL);

	TreeIsMirror(NULL);
}