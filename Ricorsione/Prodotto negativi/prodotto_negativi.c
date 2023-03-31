static int ProdottoNegativiRec(int a, int b) {

	if (b == 1) {
		return a;
	}

	return ProdottoNegativiRec(a, b - 1) + a;
}

int ProdottoNegativi(int a, int b) {
	int t = a;

	if (t == 0 || b == 0) {
		return 0;
	}

	if (b < 0) {
		b = -b;
		t = -a;
	}

	return ProdottoNegativiRec(t, b);
}