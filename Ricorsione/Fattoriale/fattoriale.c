static unsigned long long FattorialeII(int n) {

	if (n == 0) {
		return 1;
	}

	return FattorialeII(n - 1) * n;
}

unsigned long long Fattoriale(int n) {
	
	if (n < 0) {
		return 0;
	}

	return FattorialeII(n);
}