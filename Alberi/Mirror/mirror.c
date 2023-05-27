#include "tree.h"
#include "elemtype.h"

bool TreeIsMirrorRec(const Node* t1, const Node* t2) {

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	else if (!TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return false;
	}
	else if (TreeIsEmpty(t1) && !TreeIsEmpty(t2)) {
		return false;
	}
	else if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
		return false;
	}
	else {
		bool a = TreeIsMirrorRec(TreeRight(t1), TreeLeft(t2));
		bool b = TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2));
		if (a && b) {
			return true;
		}
		else {
			return false;
		}
	}
}
bool TreeIsMirror(const Node* t) {

	if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
		return true;
	}
	
	return TreeIsMirrorRec(TreeLeft(t), TreeRight(t));
}