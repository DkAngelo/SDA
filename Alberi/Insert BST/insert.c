#include "elemtype.h"
#include "tree.h"

Node* BstInsert(const ElemType* e, Node* n) {

	if (e == NULL) {
		return TreeCreateEmpty();
	}
	else if (TreeIsEmpty(n)) {
		return TreeCreateRoot(e, NULL, NULL);
	}

	Node* tmp = n;
	while (1) {
		if (TreeIsLeaf(tmp)) {
			if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0) {
				Node* new = TreeCreateRoot(e, NULL, NULL);
				tmp->left = new;
				break;
			}
			else {
				Node* new = TreeCreateRoot(e, NULL, NULL);
				tmp->right = new;
				break;
			}
		}
		if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0) {
			Node * left = TreeLeft(tmp);
			if (TreeIsEmpty(left)) {
				left = TreeCreateRoot(e, NULL, NULL);
				tmp->left = left;
				break;
			}
			tmp = TreeLeft(tmp);
		}
		else {
			Node* right = TreeRight(tmp);
			if (TreeIsEmpty(right)) {
				right = TreeCreateRoot(e, NULL, NULL);
				tmp->right = right;
				break;
			}
			tmp = TreeRight(tmp);
		}
	}

	return n;
}

Node* BstInsertRecRec(const ElemType* e, Node* n) {
	
	Node* tmp = n;

	if (TreeIsLeaf(tmp)) {
		if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0) {
			Node* new = TreeCreateRoot(e, NULL, NULL);
			n->left = new;
			return n;
		}
		else {
			Node* new = TreeCreateRoot(e, NULL, NULL);
			n->right = new;
			return n;
		}
	}

	if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0) {
		Node* left = TreeLeft(tmp);
		if (TreeIsEmpty(left)) {
			left = TreeCreateRoot(e, NULL, NULL);
			tmp->left = left;
			return n;
		}
		BstInsertRecRec(e, TreeLeft(tmp));
		return n;
	}
	else {
		Node* right = TreeRight(tmp);
		if (TreeIsEmpty(right)) {
			right = TreeCreateRoot(e, NULL, NULL);
			tmp->right = right;
			return n;
		}
		BstInsertRecRec(e, TreeRight(tmp));
		return n;
	}
}

Node* BstInsertRec(const ElemType* e, Node* n) {

	if (e == NULL) {
		return TreeCreateEmpty();
	}
	else if (TreeIsEmpty(n)) {
		return TreeCreateRoot(e, NULL, NULL);
	}

	Node* t = n;
	BstInsertRecRec(e, t);
	return n;
}