#include "elemtype.h"
#include "tree.h"

//BstTreeMin
void BstTreeMinRec(const Node* n, const ElemType** min) {
	if (TreeIsEmpty(n)) {
		return;
	}
	*min = TreeGetRootValue(n);
	BstTreeMinRec(TreeLeft(n), min);
}
const ElemType* BstTreeMin(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType* min = TreeGetRootValue(n);
	BstTreeMinRec(TreeLeft(n), &min);
	return min;
}

//TreeMin
void TreeMinRec(const Node* n, const ElemType** min, int* lvlmin, int i) {
	if (TreeIsEmpty(n)) {
		return;
	}
	if (ElemCompare(TreeGetRootValue(n), *min) < 0 || (ElemCompare(TreeGetRootValue(n), *min) == 0 && i > *lvlmin)) {
		*min = TreeGetRootValue(n);
		*lvlmin = i;
	}
	TreeMinRec(TreeRight(n), min, lvlmin, i + 1);
	TreeMinRec(TreeLeft(n), min, lvlmin, i + 1);
}
const ElemType* TreeMin(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType* min = TreeGetRootValue(n);
	int lvlmin = 0;
	TreeMinRec(TreeRight(n), &min, &lvlmin, 1);
	TreeMinRec(TreeLeft(n), &min, &lvlmin, 1);
	return min;
}