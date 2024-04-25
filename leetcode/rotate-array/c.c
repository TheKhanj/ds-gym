int gcd(int a, int b) {
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void rotate(int *arr, int n, int k) {
	k = k % n;
	for (int start = 0; start < gcd(n, k); start++) {
		int i = start;
		while (i != (start + k) % n) {
			swap(arr + i, arr + (i - k + n) % n);
			i = (i - k + n) % n;
		};
	}
}
