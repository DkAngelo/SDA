#include "elemtype.h"
#include "tree.h"

void CountDominantRec(const Node* t, int* dom) {
	
	if (TreeIsLeaf(t) || TreeIsEmpty(t)) {
		return;
	}
	
	const ElemType * a = TreeGetRootValue(t);
	ElemType l = 0,  r = 0;
	if (!TreeIsEmpty(TreeLeft(t))) {
		l = *TreeGetRootValue(TreeLeft(t));
	}
	
	if (!TreeIsEmpty(TreeRight(t))) {
		r = *TreeGetRootValue(TreeRight(t));
	}
	
	ElemType sum = (l + r);
	if (ElemCompare(a, &sum) > 0) {
		(*dom)++;
	}
	CountDominantRec(TreeLeft(t), dom);
	CountDominantRec(TreeRight(t), dom);
}

int CountDominant(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}

	int dom = 0;
	CountDominantRec(t, &dom);
	return dom;	
}