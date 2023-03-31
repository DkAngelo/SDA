int Minimo(const int* v, int v_size) {

	int a = v[0];
	int b;
	if (v_size != 1) {
		b = Minimo((v + 1), v_size - 1);
		if (a > b)
			return b;
		else
			return a;
	}
	if (v_size == 1) {
		return a;
	}
}