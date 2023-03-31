#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"mul <a> <b>\"");
		return 1;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = a * b;
	printf("%i", c);
	return 0;
}