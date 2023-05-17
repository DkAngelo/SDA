#include "colora.h"

int main(void) {

	struct Matrix h = { .size = 5, .data = malloc(25 * sizeof(bool)) };
	bool data[] = { 1, 1, 1, 1, 1, 1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1 };
	memcpy(h.data, data, 25 * sizeof(bool));
	MappaColori(&h, "rvbg", 4);
}