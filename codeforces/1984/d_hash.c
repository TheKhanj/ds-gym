#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
const int mod = 1e9 + 7;

long long p[200000 + 1];

void fill_power() {
	long long x = 1;
	for (int i = 0; i < 200000 + 1; i++) {
		p[i] = x;
		x = (x * 26) % mod;
	}
}

void fill_hash(char *s, int n, long long *hash) {
	memset(hash, 0, n * sizeof(hash[0]));

	for (int i = 0; i < n; i++)
		hash[i] = ((p[i] * (s[i] - 'a') % mod) + (i == 0 ? 0 : hash[i - 1])) % mod;
}

long long get_hash(int l, int r, long long *hash, int n) {
	long long ret = (hash[r - 1] - (l == 0 ? 0 : hash[l - 1]) + mod) % mod;
	ret = (ret * p[n - l]) % mod;
	assert(p[l] >= 0);
	return ret;
}

int check(int n, long long *hash, int t, int *nona) {
	int l = nona[0];
	if (l + t == n)
		return 1;
	int r = nona[l + t];

	while (r < n && r + t <= n) {
		if (get_hash(r, r + t, hash, n) != get_hash(l, l + t, hash, n))
			return 0;

		r = r + t == n ? n : nona[r + t];
	}

	return r == n;
}

void fill_nona(char *s, int n, int *nona) {
	int last = n;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != 'a')
			last = i;
		nona[i] = last;
	}
}

void test(char *s, int n) {
	int nona[n];
	fill_nona(s, n, nona);
	long long hash[n];
	fill_hash(s, n, hash);

	if (nona[0] == n) {
		printf("%d\n", n - 1);
		return;
	}

	uint64_t ans = 0;

	for (int t = 1; t + nona[0] <= n; t++) {
		if (!check(n, hash, t, nona))
			continue;

		int l = 0, r = nona[0];
		int dis = nona[0];
		while (l < n && r < n) {
			dis = MIN(dis, r - l);
			l = r + t;
			r = nona[l];
		}
		ans += dis + 1;
	}
	printf("%llu\n", ans);
}

int main() {
	fill_power();

	int t;
	scanf("%d", &t);
	char s[(size_t)(2e5 + 1)];
	while (t--) {
		scanf("%s", s);
		test(s, strlen(s));
	}
}
