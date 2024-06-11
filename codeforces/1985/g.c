#include <stdio.h>

const long long mod = 1e9 + 7;

long long power(long long a, long long b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a;

	long long x = power(a, b / 2);
	return (((power(a, b % 2) * x) % mod) * x) % mod;
}

long long test() {
	long long l, r, k;
	scanf("%lld %lld %lld", &l, &r, &k);
	if (k >= 10)
		return 0;
	if (k >= 5)
		return (power(2, r) - power(2, l) + mod) % mod;
	if (k == 4)
		return (power(3, r) - power(3, l) + mod) % mod;
	if (k == 3)
		return (power(4, r) - power(4, l) + mod) % mod;
	if (k == 2)
		return (power(5, r) - power(5, l) + mod) % mod;
	return (power(10, r) - power(10, l) + mod) % mod;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		printf("%lld\n", test());
}
