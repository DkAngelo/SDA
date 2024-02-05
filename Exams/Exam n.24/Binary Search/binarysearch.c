#include <stdlib.h>

int BinarySearch(const int* v, size_t v_size, int value) {

	int cmp = v[v_size / 2];
	size_t newsize = v_size / 2 + 1;

	if ((v_size == 0 || v_size == 1) && cmp != value) {
		return -1;
	}
	else if (value == cmp) {
		return (int)v_size / 2;
	}
	else if (value > cmp) {
		return BinarySearch(v + v_size / 2 + 1, v_size - newsize , value);
	}
	else {
		return BinarySearch(v, v_size - newsize + 1, value);
	}
	
}