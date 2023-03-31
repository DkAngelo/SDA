#include <limits.h>

int DivisioneNegativiRec(int a, int b) {

	int t = 0;
	if ((a - b) >= 0) {
		t++;
	}
	else {
		return t;
	}

	return DivisioneNegativiRec(a - b, b) + t;
}

int DivisioneNegativi(int a, int b) {

	if (b == 0) {
		return INT_MAX;
	}
	else if ((b > a && a> 0) || a == 0) {
		return 0;
	}
	if(a < 0 && b > 0){
		return -(DivisioneNegativiRec(-a, b));
	}
	else if (b < 0 && a > 0) {
		return -(DivisioneNegativiRec(a, -b));
	}
	else if (a < 0 && b < 0) {
		return DivisioneNegativiRec(-a, -b);
	}

	return DivisioneNegativiRec(a, b);
}