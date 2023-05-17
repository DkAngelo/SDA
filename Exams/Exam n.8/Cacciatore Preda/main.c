#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

extern int* CacciatorePreda(const char* v, size_t v_size, int u);

int main(void) {

	size_t vsize = 5;
	int u = 1;
	int *vbest = CacciatorePreda("CPPCP", vsize, u);

}