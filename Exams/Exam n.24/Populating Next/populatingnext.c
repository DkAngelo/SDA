#include "tree.h"
#include "elemtype.h"
#include <stdlib.h>

size_t TreeSize(Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	else if (TreeIsLeaf(t)) {
		return 1;
	}
	return 1 + TreeSize(TreeLeft(t)) + TreeSize(TreeRight(t));
}

void PopulatingNextRec(Node* t, Node** vett, size_t *v_size) {

	if (TreeIsEmpty(t)) {
		return;
	}

	if (TreeIsLeaf(t)) {
		size_t i;
		for (i = 0; i < *v_size; i++) {
			if (vett[i] == t) {
				break;
			}
		}
		if (i == *v_size) {
			vett[*v_size] = t;
			(* v_size)++;
			return;
		}
	}

	PopulatingNextRec(TreeLeft(t), vett, v_size);

	size_t i;
	for (i = 0; i < *v_size; i++) {
		if (vett[i] == t) {
			break;
		}
	}
	if (i == *v_size) {
		vett[*v_size] = t;
		(*v_size)++;
	}

	PopulatingNextRec(TreeRight(t), vett, v_size);
}
void PopulatingNext(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}

	size_t treesize = TreeSize(t);

	Node** vett = malloc(treesize * sizeof(Node));
	size_t v_size = 0;

	PopulatingNextRec(t, vett, &v_size);

	for (size_t i = 0; i < treesize - 1; i++) {
		vett[i]->next = vett[i + 1];
	}
	free(vett);
}