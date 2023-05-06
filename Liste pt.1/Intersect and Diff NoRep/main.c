#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

extern Item* DiffNoRep(const Item* i1, const Item* i2);

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

	Item* i1 = ListLoad("data_00.txt");
	Item* i2 = ListCreateEmpty();
	Item* list = DiffNoRep(i1, i2);
 }