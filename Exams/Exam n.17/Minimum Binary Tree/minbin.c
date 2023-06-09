#include "tree.h"
#include "elemtype.h"

Node* CreateMinBinTree(const ElemType* v, size_t v_size) {

	Node* MinBin = TreeCreateEmpty();
	if (v_size == 0) {
		return MinBin;
	}
	else if (v_size == 1) {
		MinBin = TreeCreateRoot(&v[0], NULL, NULL);
		return MinBin;
	}

	ElemType min = v[0];
	size_t m = 0;
	for (size_t i = 1; i < v_size; i++) {
		if (v[i] < min) {
			min = v[i];
			m = i;
		}
	}
	
	MinBin = TreeCreateRoot(&min, NULL, NULL);
	MinBin->left = CreateMinBinTree(v, m);
	MinBin->right = CreateMinBinTree(v + m + 1, v_size - m - 1);

	return MinBin;
}