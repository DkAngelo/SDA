#include "elemtype.h"
#include "tree.h"

extern bool Equivalenti(const Node* t1, const Node* t2);

int main(void) {
	
	ElemType e[] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23, 77 };

	Node* i1 = TreeCreateRoot(e + 1, 
		TreeCreateRoot(e + 2,
			TreeCreateRoot(e + 4, 
				TreeCreateRoot(e + 7, NULL, NULL),
				TreeCreateRoot(e + 8, NULL, NULL)),
			TreeCreateRoot(e + 5, NULL, NULL)),
		TreeCreateRoot(e + 3,
			TreeCreateRoot(e + 6, NULL, NULL),NULL));

	Node* i2 = TreeCreateRoot(e + 1,
		TreeCreateRoot(e + 2,
			TreeCreateRoot(e + 4,
				TreeCreateRoot(e + 14, NULL, NULL),
				TreeCreateRoot(e + 16, NULL, NULL)),
			TreeCreateRoot(e + 10, NULL, NULL)),
		TreeCreateRoot(e + 3, NULL, NULL));

	Equivalenti(NULL, i2);
}