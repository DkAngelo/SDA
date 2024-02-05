#include "tree.h"
#include "elemtype.h"

Node* Invert(Node* t) {
	if (TreeIsEmpty(t)) {
		return t;
	}

	Node* r = t->right;
	Node* l = t->left;
	t->right = l;
	t->left = r;

	if (!TreeIsEmpty(TreeRight(t))) {
		Invert(TreeRight(t));
	}
	if (!TreeIsEmpty(TreeLeft(t))) {
		Invert(TreeLeft(t));
	}

	return t;
}