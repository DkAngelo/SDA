#include "elemtype.h"
#include "tree.h"
#include <limits.h>

bool IsFather(const Node* t, int a, int b) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	else if (TreeIsEmpty(t->right) || TreeIsEmpty(t->left)) {
		return false;
	}

	else if (*TreeGetRootValue(t->right) == a && *TreeGetRootValue(t->left) == b){
		return true;
	}
	else if (*TreeGetRootValue(t->right) == b && *TreeGetRootValue(t->left) == a) {
		return true;
	}

	bool l = false;
	l = IsFather(t->left, a, b);
	if (l == false) {
		return IsFather(t->right, a, b);
	}
	return l;
}

int SeekLevel(const Node* t, int n, int i) {
	if (TreeIsEmpty(t)) {
		return INT_MIN;
	}
	else if (*TreeGetRootValue(t) == n) {
		return i;
	}
	int l = SeekLevel(TreeLeft(t), n, i + 1);
	if (l == INT_MIN) {
		return SeekLevel(TreeRight(t), n, i + 1);
	}
	return l;
}

bool Cugini(const Node* t, int a, int b) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	int alvl = SeekLevel(t, a, 0);
	int blvl = SeekLevel(t, b, 0);
	bool f = false;
	f = IsFather(t, a, b);

	if (alvl != blvl) {
		return false;
	}
	else if (alvl == blvl && !f) {
		return true;
	}
	return false;
}