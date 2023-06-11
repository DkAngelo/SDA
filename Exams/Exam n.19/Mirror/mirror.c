#include "tree.h"
#include "elemtype.h"

bool TreeIsMirrorRec(Node* t1, Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	else if (TreeIsEmpty(t1) && !TreeIsEmpty(t2)) {
		return false;
	}
	else if (!TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return false;
	}
	else if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
		return false;
	}

	bool l = TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2));
	if (l) {
		return TreeIsMirrorRec(TreeRight(t1), TreeLeft(t2));
	}
	return l;
}

bool TreeIsMirror(Node* t) {
	if (TreeIsEmpty(t)) {
		return true;
	}
	else if (TreeIsLeaf(t)) {
		return true;
	}

	return TreeIsMirrorRec(TreeLeft(t), TreeRight(t));
}