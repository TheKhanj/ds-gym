#include <stdio.h>

int check(long long attacks, long long h, long long n, long long *a,
					long long *c) {
	long long dec = 0;
	for (long long i = 0; i < n; i++) {
		dec += (attacks / c[i] + !!(attacks % c[i])) * a[i];
		if (dec >= h)
			return 1;
	}
	return h <= dec;
}

long long bs(long long l, long long r, long long h, long long n, long long *a,
						 long long *c) {
	long long mid = (l + r) / 2;

	if (l == r - 1)
		return r;

	if (check(mid, h, n, a, c))
		return bs(l, mid, h, n, a, c);
	return bs(mid, r, h, n, a, c);
}

void test() {
	long long h, n;
	scanf("%lld %lld", &h, &n);
	long long a[n], c[n];
	for (long long i = 0; i < n; i++)
		scanf("%lld", a + i);
	for (long long i = 0; i < n; i++)
		scanf("%lld", c + i);

	long long ans = bs(0, 4 * 1e10 + 100, h, n, a, c);
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
