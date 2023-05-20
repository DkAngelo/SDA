#include <string.h>
#include <stdbool.h>

bool IsPalindromoRec(const char* str, size_t i, size_t j) {

	if (str[i] == '\0') {
		return true;
	}
	else if (str[i] != str[j]) {
		return false;
	}
	else {
		return IsPalindromoRec(str, i + 1, j - 1);
	}
}

bool IsPalindromo(const char* str) {
	if (str == NULL) {
		return false;
	}
	else if(strcmp(str, "") == 0) {
		return true;
	}
	size_t len = strlen(str);
	return IsPalindromoRec(str, 0, len - 1);
}