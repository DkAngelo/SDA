#include "tree.h"
#include "elemtype.h"

void Check(const Node* t, const Node* cmp, int n, bool* check) {\
	if(TreeIsEmpty(t)){
		return;
	}
	if (cmp == t) {
		Check(TreeLeft(t), cmp, n, check);
		if (!(*check)) {
			Check(TreeRight(t), cmp, n, check);
		}
		return;
	}
	ElemType a = *TreeGetRootValue(cmp) + * TreeGetRootValue(t);
	if (a != n) {
		Check(TreeLeft(t), cmp, n, check);
		if (!(*check)) {
			Check(TreeRight(t), cmp, n, check);
		}
		return;
	}
	else {
		*check = true;
		return;
	}
}
bool CheckSumNRec(const Node* t, const Node* cmp, int n) {
	if (TreeIsEmpty(cmp)) {
		return false;
	}
	bool check = false;
	Check(t, cmp, n, &check);
	if (!check) {
		bool a = CheckSumNRec(t, TreeRight(cmp), n);
		if (!a) {
			bool b = CheckSumNRec(t, TreeLeft(cmp), n);
			return b;
		}
		return a;
	}
	return check;
}
bool CheckSumN(const Node* t, int n) {
	if (TreeIsEmpty(t)) {
		return NULL;
	}
	return CheckSumNRec(t, t, n);
}