int DivisioneRec(int a, int b) {

	int t = 0;
	if ((a-b) >= 0) {
		t ++;
	} else {
		return t;
	}

	return DivisioneRec(a - b, b) + t;
}

int Divisione(int a, int b) {
	
	if (a < 0 || b <= 0) {
		return -1;
	} else if (b > a || a == 0) {
		return 0;
	}

	return DivisioneRec(a, b);
}
