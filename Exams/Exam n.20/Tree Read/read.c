#define _CRT_SECURE_NO_WARNINGS

#include "tree.h"
#include "elemtype.h"

Node* TreeReadRec(FILE *f) {
	Node* t = TreeCreateEmpty();

	ElemType a;
	int c = fscanf(f, " %c", &a);
	if (a == '.') {
		c = fscanf(f, " %c", &a);
		t = TreeCreateRoot(&a, NULL, NULL);
		return t;
	}
	t = TreeCreateRoot(&a, NULL, NULL);
	t->left = TreeReadRec(f);
	t->right = TreeReadRec(f);
	return t;
}

Node* TreeRead(const char* filename) {

	Node* t = TreeCreateEmpty();
	if (filename == NULL) {
		return t;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	ElemType a;
	int c = fscanf(f, " %c", &a);
	if (a == '.') {
		c = fscanf(f, " %c", &a);
		t = TreeCreateRoot(&a, NULL, NULL);
		fclose(f);
		return t;
	}
	t = TreeCreateRoot(&a, NULL, NULL);
	t->left = TreeReadRec(f);
	t->right = TreeReadRec(f);
	fclose(f);
	return t;
}