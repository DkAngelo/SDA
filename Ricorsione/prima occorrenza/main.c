#include <stdlib.h>
#include <stdbool.h>
extern bool occorrenza(char* x[], char y, size_t n);

int main(void) {
	char* a[5] = {'a', 'b', 'c', '3', '$'};
	char b = '$';
	occorrenza(a, b, 5);
}