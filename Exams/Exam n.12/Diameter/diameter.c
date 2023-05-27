#include "elemtype.h"
#include "tree.h"

int Highness(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	if (TreeIsLeaf(t)) {
		return 1;
	}
	int hl = Highness(TreeLeft(t));
	int hr = Highness(TreeRight(t));
	if (hl >= hr) {
		return 1 + hl;
	}
	else {
		return 1 + hr;
	}
}

int MaxDim(int dm, int dl, int dr) {
	int maxdim;
	if (dl >= dr) {
		maxdim = dl;
	}
	else {
		maxdim = dr;
	}
	if (maxdim >= dm) {
		return maxdim;
	}
	else {
		return dm;
	}
}

int Diameter(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	if (TreeIsLeaf(t)) {
		return 1;
	}
	
	int dm = 1 + Highness(TreeLeft(t)) + Highness(TreeRight(t));
	int dl = Diameter(TreeLeft(t));
	int dr = Diameter(TreeRight(t));

	return MaxDim(dm, dl, dr);
}
