#include "elemtype.h"
#include "tree.h"

extern Node* MergeTree(const Node* t1, const Node* t2);

int main(void) {
	ElemType e[] = { -2, 5, 8, 2, 4, 1, 1};
	ElemType e1[] = { -3, 10, 1, 9, -1 };
	Node* t1 = TreeCreateRoot(e,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 2, NULL, NULL),
			TreeCreateRoot(e + 3, NULL,
				TreeCreateRoot(e + 4, NULL, NULL))),
		TreeCreateRoot(e + 5, NULL, 
			TreeCreateRoot(e + 6, NULL, NULL)));

	Node* t2 = TreeCreateRoot(e1,
		TreeCreateRoot(e1 + 1, NULL, NULL),
		TreeCreateRoot(e1 + 2, 
			TreeCreateRoot(e1 + 3, NULL, NULL),
			TreeCreateRoot(e1 + 4, NULL, NULL)));

	Node* t3 = MergeTree(t1, t2);
}