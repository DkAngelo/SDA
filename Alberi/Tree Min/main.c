#include "elemtype.h"
#include "tree.h"

extern const ElemType* BstTreeMin(const Node* n);
extern const ElemType* TreeMin(const Node* n);

int main(void) {
	ElemType e[] = {4, -4, -4, 5, 1, 8, 2, -4, 8 };
	Node* t = TreeCreateRoot(e + 0,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 2,
				TreeCreateRoot(e + 3, NULL, NULL),
				TreeCreateRoot(e + 4, NULL, NULL)),
			TreeCreateRoot(e + 5, NULL, NULL)),
		TreeCreateRoot(e + 6,
			TreeCreateRoot(e + 7, NULL, NULL),
			TreeCreateRoot(e + 8, NULL, NULL)));

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

	TreeMin(t);
	BstTreeMin(bst);
}