#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

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
		if (c == 0) {
			break;
		}
		list = ListInsertHead(&tmp, list);
	}

	fclose(f);
	return list;
}

/*int main(void) {

	ListLoad("data_00.txt");
}*/