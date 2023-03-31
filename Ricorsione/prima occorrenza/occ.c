#include <stdlib.h>
#include <stdbool.h>

bool occorrenza(char* x[], char y, size_t n) {
	if (n == 0)
		return false;
	else if (*x == y)
		return true;
	else
		occorrenza((x + 1), y, (n - 1));

	return -1;
}