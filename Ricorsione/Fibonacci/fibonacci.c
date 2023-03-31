static int FibonacciII(int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	return FibonacciII(n - 1) + FibonacciII(n - 2);
}

int Fibonacci(int n) {
	if (n < 0) {
		return -1;
	}

	return FibonacciII(n);
}