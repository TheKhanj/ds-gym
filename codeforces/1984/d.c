#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void z_function(char *s, int n, int *z) {
	memset(z, 0, sizeof(z[0]) * n);
	z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r)
			z[i] = MIN(r - i, z[i - l]);
		while (z[i] + i < n && s[z[i]] == s[z[i] + i])
			++z[i];
		if (r < z[i] + i)
			l = i, r = z[i] + i;
	}
}

int check(int n, int *z, int t, int *nona) {
	int l = nona[0];
	if (l + t == n)
		return 1;
	int r = nona[l + t];

	while (r < n) {
		if (z[r] < t)
			return 0;

		if (r + t >= n)
			return 1;
		r = nona[r + t];
	}
	return 1;
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
	int z[n];
	z_function(s + nona[0], n - nona[0], z + nona[0]);

	if (nona[0] == n) {
		printf("%d\n", n - 1);
		return;
	}

	uint64_t ans = 0;

	for (int t = 1; t + nona[0] <= n; t++) {
		if (!check(n, z, t, nona))
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
	int t;
	scanf("%d", &t);
	char s[(size_t)(2e5 + 1)];
	while (t--) {
		scanf("%s", s);
		test(s, strlen(s));
	}
}
