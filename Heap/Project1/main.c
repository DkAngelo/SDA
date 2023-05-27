#include "elemtype.h"
#include "minheap.h"

extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);

int main(void) {

	ElemType v[] = { 10, 34, 1, 16, 7, 14, 23 , 5, 3};
	size_t v_size = 9;
	HeapMinHeapify(v, v_size);

}