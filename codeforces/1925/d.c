#include <stdio.h>

const long long mod = 1000000007;

#define MAXN 200100

int fac_cache[MAXN];

void fac_init() {
	fac_cache[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fac_cache[i] = (fac_cache[i - 1] * i) % mod;
}

int fac(int n) { return fac_cache[n]; }

int cross(long long a, long long b) { return (a * b) % mod; }

int qpow(int a, int b) {
	if (b == 0)
		return 1;
	int c = qpow(a, b / 2);

	return cross(cross(c, c), b % 2 == 0 ? 1 : a);
}

int choose(int k, int n) {
	return cross(cross(fac(n), qpow(fac(k), mod - 2)), qpow(fac(n - k), mod - 2));
}

void test() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		int a, b, v;
		scanf("%d %d %d", &a, &b, &v);
		sum += v;
	}

	int ans[k + 1];
	for (int i = 0; i <= k; i++)
		ans[i] = 0;

	int ss = (((2 * sum + k - 1) % mod) * k / 2) % mod;
	for (int i = 0; i <= k; i++) {
		int c = choose(i, k);
		int _2_n = choose(2, n);
		int cont = (i) % mod;
		int s = cont + ss;

		int first = c;
		int second = qpow(cross(m, qpow(_2_n, mod - 2)), i);
		int third = qpow(cross(_2_n - m, qpow(_2_n, mod - 2)), k - i);
		int fourth = s;
		printf("k: %d -- 1: %d, 2: %d, 3: %d, 4: %d, 5: %d\n", i, first, second,
					 third, fourth, cont);
		ans[i] = cross(cross(first, second), cross(third, fourth));
	}

	long long x = 0;
	for (int i = 0; i <= k; i++) {
		x += ans[i];
		x %= mod;
	}
	printf("%lld\n", x);
}

int main() {
	int t;
	fac_init();
	scanf("%d", &t);
	while (t--)
		test();
}
