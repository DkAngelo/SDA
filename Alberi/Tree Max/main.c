#include "elemtype.h"
#include "tree.h"

extern const ElemType* BstTreeMax(const Node* n);
extern const ElemType* TreeMax(const Node* n);

int main(void) {
	ElemType e[] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23, 77 };
	Node* t = TreeCreateRoot(e + 12,
		TreeCreateRoot(e + 4,
			TreeCreateRoot(e + 0,
				TreeCreateRoot(e + 24, NULL, NULL),
				TreeCreateRoot(e + 8, NULL, NULL)),
			TreeCreateRoot(e + 2,
				TreeCreateRoot(e + 9, NULL, NULL), NULL)),
		TreeCreateRoot(e + 21,
			TreeCreateRoot(e + 5, NULL, NULL),
			TreeCreateRoot(e + 18, NULL, NULL)));

	Node* bst = TreeCreateRoot(e + 12,
		TreeCreateRoot(e + 4,
			TreeCreateRoot(e + 0, NULL,
				TreeCreateRoot(e + 2, NULL, NULL)),
			TreeCreateRoot(e + 5, NULL,
				TreeCreateRoot(e + 8, NULL,
					TreeCreateRoot(e + 9, NULL, NULL)))),
		TreeCreateRoot(e + 21,
			TreeCreateRoot(e + 18,
				TreeCreateRoot(e + 13, NULL, NULL), NULL),
			TreeCreateRoot(e + 24, NULL, NULL)));

	BstTreeMax(bst);
	TreeMax(t);
}