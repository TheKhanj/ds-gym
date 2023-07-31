#include <stdio.h>

int cache[50];

int calc(int x) {
	if (x == -1) {
		return 0;
	}

	if (cache[x] != -1) {
		return cache[x];
	}

	cache[x] = cache[x - 1] + 5 * x;
	return cache[x];
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < 50; ++i) {
		cache[i] = -1;
	}

	int x = 240 - k;
	int ans = 0;
	while (ans <=n && calc(ans) <= x) {
		// printf("%d: %d\n", ans, calc(ans));
		ans++;
	}

	printf("%d\n", --ans);
}
