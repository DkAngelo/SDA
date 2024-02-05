#include "tree.h"
#include "elemtype.h"

bool PercorsoSommaRec(Node* t, const ElemType* target, ElemType sum) {

	if (TreeIsEmpty(t)) {
		return false;
	}

	sum += *TreeGetRootValue(t);
	if (ElemCompare(target, &sum) == 0) {
		return true;
	}

	bool road = PercorsoSommaRec(TreeLeft(t), target, sum);
	if (!road) {
		road = PercorsoSommaRec(TreeRight(t), target, sum);
	}
	sum -= *TreeGetRootValue(t);
	return road;
}

bool PercorsoSomma(Node* t, const ElemType* target) {

	if (TreeIsEmpty(t)) {
		return false;
	}
	else if (TreeIsLeaf(t)) {
		return false;
	}

	return PercorsoSommaRec(t, target, 0);
}