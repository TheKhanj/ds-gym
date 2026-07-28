#include <stdio.h>

int digits(int n) {
	int ret = 0;
	while (n) {
		n /= 10;
		ret++;
	}
	return ret;
}

int ipow(int a, int b) {
	if (b == 0)
		return 1;

	int p1 = ipow(a, b / 2);
	return p1 * p1 * (b % 2 == 0 ? 1 : a);
}

int answer(int n) {
	int dig = digits(n);
	int x = n / ipow(10, dig - 1);

	// printf("n: %d, dig: %d, ipow: %d\n", n, dig, ipow(10, dig - 1));
	return x + (dig - 1) * 9;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", answer(n));
	}
}
