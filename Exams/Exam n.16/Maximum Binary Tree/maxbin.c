#include "elemtype.h"
#include "tree.h"
#include <limits.h>

Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	
	Node* maxbin = TreeCreateEmpty();
	if (v == NULL || v_size == 0) {
		return maxbin;
	}
	if (v_size == 1) {
		maxbin = TreeCreateRoot(&v[0], NULL, NULL);
		return maxbin;
	}

	ElemType max = INT_MIN;
	size_t posmax;

	for (size_t i = 0; i < v_size; i++) {
		if (ElemCompare(&max, &v[i]) < 0) {
			max = v[i];
			posmax = i;
		}
	}

	maxbin = TreeCreateRoot(&v[posmax], NULL, NULL);
	if (posmax != v_size) {
		maxbin->right = CreateMaxBinTree(v + posmax + 1, v_size - posmax - 1);
	}
	if (posmax != 0) {
		maxbin->left = CreateMaxBinTree(v, posmax);
	}
	return maxbin;
}