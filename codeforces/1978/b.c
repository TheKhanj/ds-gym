#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

long long solve(long long n, long long a, long long b) {
	if (b <= a)
		return a * n;
	long long k = MIN(b - a, n);
	long long r = b - k + 1;
	long long l = b;
	return (l + r) * k / 2 + a * (n - k);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, a, b;
		scanf("%lld %lld %lld", &n, &a, &b);
		printf("%lld\n", solve(n, a, b));
	}
}
