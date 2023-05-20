#include "elemtype.h"
#include "tree.h"

//BstTreeMax
void BstTreeMaxRec(const Node* n, const ElemType** max) {
	if (TreeIsEmpty(n)) {
		return;
	}
	*max = TreeGetRootValue(n);
	BstTreeMaxRec(TreeRight(n), max);
}
const ElemType* BstTreeMax(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}
	const ElemType* max = TreeGetRootValue(n);
	BstTreeMaxRec(TreeRight(n), &max);
	return max;
}

//TreeMax
void TreeMaxRec(const Node* n, const ElemType** max, int* lvlmax, int i) {

	if (TreeIsEmpty(n)) {
		return;
	}
	if (ElemCompare(TreeGetRootValue(n), *max) > 0 || (ElemCompare(TreeGetRootValue(n), *max) == 0 && i < *lvlmax)) {
		*lvlmax = i;
		*max = TreeGetRootValue(n);
	}
	TreeMaxRec(TreeLeft(n), max, lvlmax, i + 1);
	TreeMaxRec(TreeRight(n), max, lvlmax, i + 1);
}
const ElemType* TreeMax(const Node* n) {

	if (TreeIsEmpty(n)) {
		return NULL;
	}
	const ElemType* max = TreeGetRootValue(n);
	int lvl = 0;
	TreeMaxRec(TreeLeft(n), &max, &lvl, 1);
	TreeMaxRec(TreeRight(n), &max, &lvl, 1);
	return max;
}
