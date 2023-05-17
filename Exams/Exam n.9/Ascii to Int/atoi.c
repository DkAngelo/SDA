#include <stdlib.h>
#include <string.h>
#include <math.h>

int AToIRec(const char* str, size_t exp, int i) {

	if (str[i + 1] != '\0') {
		int b = pow(10, exp);
		int a = str[i] - '0';
		return AToIRec(str, --exp, ++i) + a * b;
	}
	else {
		return str[i] - '0';
	}
}

int AToI(const char* str) {
	
	if (str == NULL) {
		return 0;
	}
	size_t len = strlen(str);

	return AToIRec(str, len - 1, 0);
}

/*int main(void) {
	AToI("1233");
}*/