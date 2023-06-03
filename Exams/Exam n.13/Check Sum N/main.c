#include "elemtype.h"
#include "tree.h"

extern bool CheckSumN(const Node* t, int n);

int main(void) {
	
	ElemType e[] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23, 77 };

	Node* bst = TreeCreateRoot(e + 12, 
		TreeCreateRoot(e + 4,
			TreeCreateRoot(e + 0, NULL,
				TreeCreateRoot(e + 2, NULL, NULL)),
			TreeCreateRoot(e + 5, NULL,
				TreeCreateRoot(e + 8, NULL,
					TreeCreateRoot(e + 9, NULL, NULL)))),
		TreeCreateRoot(e + 21,
			TreeCreateRoot(e + 18, 
				TreeCreateRoot(e + 16, NULL, NULL), NULL),
			TreeCreateRoot(e + 24, 
				TreeCreateRoot(e+22, NULL, NULL), NULL)));

	CheckSumN(bst, 23);
	CheckSumN(bst, 0);
}
