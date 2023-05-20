int Potenza(int a, int b) {
	if (b == 0) {
		return 1;
	}
	return Potenza(a, --b) * a;
}