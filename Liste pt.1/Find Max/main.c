#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

Item* ListLoad(const char* filename);
const ElemType* MaxElement(const Item* i);

int main(void) {

	Item* i1 = ListLoad("data_00.txt");
	const ElemType* e = MaxElement(i1);

 }