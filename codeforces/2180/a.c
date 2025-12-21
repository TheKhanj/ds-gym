#include <stdio.h>

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void solve() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	b = b % n;
	if (b == 0)
		printf("%d\n", a);
	else {
		int g = gcd(n, b);
		printf("%d\n", a + g * ((n - 1 - a) / g));
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
