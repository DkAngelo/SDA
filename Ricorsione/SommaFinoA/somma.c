int SommaFinoA(int n) {
	if (n <= 0)
		return -1;

	return SommaFinoARec(n);
}

int SommaFinoARec(int n) {
	if (n == 1)
		return 1;
	
	return n + SommaFinoA(n - 1);
}