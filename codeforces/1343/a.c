#include <stdio.h>

long long p[50];

int solve(int n) {
	for (int k = 2; p[k] - 1 <= n; k++) {
		if (n % (p[k] - 1) == 0)
			return n / (p[k] - 1);
	}
	return -1;
}

void init_pow() {
	p[0] = 1;
	for (int i = 1; i < 50; i++)
		p[i] = 2 * p[i - 1];
}

int main() {
	int t;
	scanf("%d", &t);
	init_pow();
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
}
