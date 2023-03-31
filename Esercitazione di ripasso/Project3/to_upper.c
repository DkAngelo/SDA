#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ToUpper(char* str) {
	if (str == NULL)
		return;
	size_t len;

	for (size_t i = 0; *(str + i) != 0; i++) {
		if (*(str+i) >= 'a' && *(str+i) <= 'z') {
			*(str +i) = *(str + i) - ('a' - 'A');
		}
	}
}