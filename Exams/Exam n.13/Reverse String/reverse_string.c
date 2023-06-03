#include <string.h>
#include <stdlib.h>

void ReverseStringRec(const char* str, size_t len, char *res, size_t i) {
	if (str[i] == '\0') {
		return;
	}
	res[i] = str[len];
	ReverseStringRec(str, len - 1, res, i + 1);
}
char* ReverseString(const char* str) {

	if (str == NULL) {
		return NULL;
	}
	char* res = calloc((strlen(str) + 1), sizeof(char));
	ReverseStringRec(str, strlen(str) - 1, res, 0);
	return res;
}

/*int main(void) {
	ReverseString("stringa di prova");
}*/