#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

void FrazioneEgiziaRec(int n, int d, int i) {

	int div, mod = d % n;
	if (mod != 0) {
		div = d / n + 1;
	}
	else {
		div = d / n;
	}

	if(i != 0) {
		printf("+ 1/%i ", div);
	}
	else {
		printf("1/%i ", div);
	}
	
	if (mod == 0) {
		return;
	}

	int newn = div * n - d;
	int newd = div * d;
	FrazioneEgiziaRec(newn, newd, ++i);
}

void FrazioneEgizia(int n, int d) {

	if (d <= n || d <= 0 || n <= 0) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}
	else {
		FrazioneEgiziaRec(n, d, 0);
	}

	return;
}