#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

extern Item* Intersect(const Item* i1, const Item* i2);

Item* ListLoad(const char* filename) {

	if (filename == NULL) {
		return NULL;
	}

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Item* list = ListCreateEmpty();
	ElemType tmp;

	while (1) {

		int c = ElemRead(f, &tmp);
		if (c == EOF) {
			break;
		}
		list = ListInsertHead(&tmp, list);
	}

	fclose(f);
	return list;
}

int main(void) {

	Item * List1 = ListLoad("data_00.txt");
	Item* List2 = ListLoad("data_01.txt");
	Item* List3 = Intersect(List1, List2);
}