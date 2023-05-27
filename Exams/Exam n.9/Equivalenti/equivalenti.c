#include "elemtype.h"
#include "tree.h"

bool Equivalenti(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	else if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2))) {
		return false;
	}
	else if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		ElemType a = *TreeGetRootValue(t1);
		ElemType b = *TreeGetRootValue(t2);
		if ((a % b) == 0 || (b % a) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (TreeIsLeaf(t1) && !TreeIsLeaf(t2)) {
		return false;
	}
	else if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
		return false;
	}

	bool left = Equivalenti(TreeLeft(t1), TreeLeft(t2));
	bool right = Equivalenti(TreeRight(t1), TreeRight(t2));
	return left && right;
}