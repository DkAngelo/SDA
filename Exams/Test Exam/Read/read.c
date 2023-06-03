#define _CRT_SECURE_NO_WARNINGS

#include "tree.h"
#include "elemtype.h"


Node* TreeReadRec(FILE* f) {

	Node* t = TreeCreateEmpty();
	ElemType c;
	ElemType p = '.';

	int a = fscanf(f, " %c", & c);
	if (a == EOF) {
		return t;
	}
	else if (ElemCompare(&c, &p) == 0) {
		a = fscanf(f, " %c", &c);
		t = TreeCreateRoot(&c, NULL, NULL);
		return t;
	}

	t = TreeCreateRoot(&c, NULL, NULL);
	t->left = TreeReadRec(f);
	t->right = TreeReadRec(f);
	return t;

}

Node* TreeRead(const char* filename) {

	if (filename == NULL) {
		return NULL;
	}

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Node* t = TreeCreateEmpty();
	ElemType c;
	ElemType p = '.';

	int a = fscanf(f, " %c", &c);
	if (a == EOF) {
		fclose(f);
		return t;
	}
	else if (ElemCompare(&c, &p) == 0){
		a = fscanf(f, " %c", &c);
		t = TreeCreateRoot(&c, NULL, NULL);
		fclose(f);
		return t;
	}

	t = TreeCreateRoot(&c, NULL, NULL);
	t->left = TreeReadRec(f);
	t->right = TreeReadRec(f);

	fclose(f);
	return t;
}