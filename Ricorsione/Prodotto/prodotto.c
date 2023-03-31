static int ProdottoRec(int a, int b) {

	if (b == 1) {
		return a;
	}

	return ProdottoRec(a, b - 1) + a;
}

int Prodotto(int a, int b) {
	if (a < 0 || b < 0) {
		return -1;
	} else if (a == 0 || b == 0) {
		return 0;
	}

	return ProdottoRec(a, b);
}